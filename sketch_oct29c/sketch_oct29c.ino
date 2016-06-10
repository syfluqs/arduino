#define LEFT_MOTOR_1 11
#define LEFT_MOTOR_2 10
#define RIGHT_MOTOR_1 9
#define RIGHT_MOTOR_2 6

void setup() {
  // put your setup code here, to run once:
  pinMode(LEFT_MOTOR_1, OUTPUT); // _{ left 
  pinMode(LEFT_MOTOR_2, OUTPUT); //  { motor
  pinMode(RIGHT_MOTOR_1, OUTPUT); // _{ right
  pinMode(RIGHT_MOTOR_2, OUTPUT); //  { motor
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LEFT_MOTOR_1, HIGH);
digitalWrite(LEFT_MOTOR_2, HIGH);
digitalWrite(RIGHT_MOTOR_1, HIGH);
digitalWrite(RIGHT_MOTOR_2, HIGH);
}
