// 6-channel RC RF-Bot
//
// Coded By: Subham Roy
// E-Mail : syfluqs@gmail.com
#define CODE_VERSION "2.0"

//set this constant 1 if you want to print debug messages
#define DEBUG 0
//set 1 if you want to print receiver's pulse width
#define PRINT_REC_PW 1

//defining pins needed for motor movement and light control
#define LEFT_MOTOR_1 11
#define LEFT_MOTOR_2 10
#define RIGHT_MOTOR_1 9
#define RIGHT_MOTOR_2 6

#define HEADLIGHTS 12
#define TAILLIGHTS 8
#define REVERSE_LED 8

//set these values from 0 to 255
//these will be the output PWM signals to motor driver
#define MOTOR_DRIVE_MAX 255
#define MOTOR_DRIVE_MIN 0
//max decrease or increase in output value while turning
//while in linear mode: max_output=MOTOR_DRIVE_MAX-LINEAR_MODE_DELTA
#define LINEAR_MODE_DELTA 70

//defines min and max values of input pulse width from
//receiver unit
#define CH1_MAX 1990
#define CH1_MIN 985
#define CH2_MAX 1995
#define CH2_MIN 995
#define CH3_MAX 1990
#define CH3_MIN 990
#define CH4_MAX 1987
#define CH4_MIN 985
//separate values for ch5 3-way switch
#define CH5_1_MAX 990
#define CH5_1_MIN 980
#define CH5_2_MAX 1505
#define CH5_2_MIN 1480
#define CH5_3_MAX 2005
#define CH5_3_MIN 1992
//separate values for ch6 2-way switch
#define CH6_0_MAX 2005
#define CH6_0_MIN 1992
#define CH6_1_MAX 990
#define CH6_1_MIN 977

//delay in between every loop
#define loop_delay 70
//pulseIn timeout
#define pw_timeout 50000

//===========================================================

int ch1,ch2,ch3,ch4,ch5,ch6;
//reverse mode
boolean reverse = false;

//movement_variables
//analog output values to motor driver
//values must be from MOTOR_DRIVE_MIN to MOTOR_DRIVE_MAX
int left_1 = 0;
int left_2 = 0;
int right_1 = 0;
int right_2 = 0;
int forward = 0;
int delta_left=0;
int delta_right=0;

void setup()
{
  pinMode(LEFT_MOTOR_1, OUTPUT); // _{ left 
  pinMode(LEFT_MOTOR_2, OUTPUT); //  { motor
  pinMode(RIGHT_MOTOR_1, OUTPUT); // _{ right
  pinMode(RIGHT_MOTOR_2, OUTPUT); //  { motor
  
  pinMode(HEADLIGHTS, OUTPUT);
  pinMode(TAILLIGHTS, OUTPUT);
  
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

  if(DEBUG || PRINT_REC_PW) {
  Serial.begin(9600);
  Serial.print("RFbot v"); Serial.print(CODE_VERSION); Serial.println(" Online...");
  }
  
  //ToDo :: Test Sequence
  
}

void loop()
{
  //collecting values
  ch1 = pulseIn(A0, HIGH, pw_timeout);
  ch2 = pulseIn(A1, HIGH, pw_timeout);
  ch3 = pulseIn(A2, HIGH, pw_timeout);
  ch4 = pulseIn(A3, HIGH, pw_timeout);
  ch5 = pulseIn(A4, HIGH, pw_timeout);
  ch6 = pulseIn(A5, HIGH, pw_timeout);

  if (PRINT_REC_PW) {
    Serial.print(ch1); Serial.print("||");
    Serial.print(ch2); Serial.print("||");
    Serial.print(ch3); Serial.print("||");
    Serial.print(ch4); Serial.print("||");
    Serial.print(ch5); Serial.print("||");
    Serial.print(ch6); Serial.println();
  }
    
  //headlights
  if (ch6>CH6_1_MIN) {
    digitalWrite(HEADLIGHTS, HIGH); //headlights on
    //if (DEBUG) { Serial.println("Headlights On"); }
  } else {
    digitalWrite(HEADLIGHTS, LOW); //headlights off
    //if (DEBUG) { Serial.println("Headlights Off"); }
  }

  //=================== main motor driving code ===============================
  
  //ch5 switch set at 1
  //linear speed mode
  //bot moves at constant linear velocity whether in straight
  //or curved path
  if (ch5>=CH5_1_MIN && ch5<CH5_1_MAX) {

    forward = map(ch3, CH3_MIN, CH3_MAX, MOTOR_DRIVE_MIN, MOTOR_DRIVE_MAX-LINEAR_MODE_DELTA);
    delta_left = map(ch1, CH1_MIN, CH1_MAX, -LINEAR_MODE_DELTA, LINEAR_MODE_DELTA);
    delta_right = -delta_left;

    left_1 = forward+delta_left;
    left_2 = 0;
    right_1 = forward+delta_right;
    right_2 = 0;
    if (left_1<0) {left_1=0;}
    if (right_1<0) {right_1=0;}

    if (DEBUG) { Serial.print("mode1: "); Serial.print(forward); Serial.print("||");
                                          Serial.print(left_1); Serial.print("||");
                                          Serial.print(right_1); Serial.println(); }
    
  }
  
  //ch5 switch set at 2
  //drift mode
  //bot moves with max velocity possible and exhibits sharp
  //turns
  else if (ch5>=CH5_2_MIN && ch5<CH5_1_MAX) {
    
    forward = map(ch3, CH3_MIN, CH3_MAX, MOTOR_DRIVE_MIN, MOTOR_DRIVE_MAX);
    delta_left = map(ch1, CH1_MIN, CH1_MAX, -LINEAR_MODE_DELTA, LINEAR_MODE_DELTA);
    delta_right = -delta_left;

    if (DEBUG) { Serial.print("mode2: "); Serial.print(forward); Serial.print("||");
                                          Serial.print(delta_left); Serial.print("||");
                                          Serial.print(delta_right); Serial.println(); }

    left_1 = forward+delta_left;
    left_2 = 0;
    right_1 = forward+delta_right;
    right_2 = 0;
  }
  
  //ch5 switch set at 3
  //not implemented yet
  else if (ch5>=CH5_3_MIN && ch5<CH5_3_MAX) {
    if (DEBUG) { Serial.println("ch5 switch set to 3"); }
  }

  //remote switched off
  else {
    left_1 = 0;
    left_2 = 0;
    right_1 = 0;
    right_2 = 0;
  }

  //detect reverse condition
  if ( (ch4 < (CH4_MIN+200)) && !reverse ) { reverse = true; }
  else if ( (ch4 < (CH4_MIN+200)) && reverse ) {reverse = false; }
  //if in reverse mode, turn on reverse LED
  digitalWrite(REVERSE_LED, reverse);

  //set values to the motor driver
  if (reverse) {
    analogWrite(LEFT_MOTOR_1, right_2);
    analogWrite(LEFT_MOTOR_2, right_1);
    analogWrite(RIGHT_MOTOR_1, left_2);
    analogWrite(RIGHT_MOTOR_2, left_1);
  }
  else {
    analogWrite(LEFT_MOTOR_1, left_1);
    analogWrite(RIGHT_MOTOR_1, right_1);
    analogWrite(LEFT_MOTOR_2, left_2);
    analogWrite(RIGHT_MOTOR_2, right_2);
  }
  
  delay(loop_delay);
}
