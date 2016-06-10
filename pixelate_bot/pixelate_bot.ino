#include <SoftwareSerial.h>

SoftwareSerial abc(5,6);


  #define l1 3
  #define l2 9
  #define r1 10
  #define r2 11
  #define red 8
  #define green 4
  #define yellow 7

  #define delay_90_l 455
  #define delay_90_r 485
  #define delay_180 800
  #define delay_forward 750
  #define left_speed 240
  #define right_speed 240
  #define turn_left 255
  #define turn_right 255
  
void setup() {
  // put your setup code here, to run once:
  
  abc.begin(9600);
  Serial.begin(9600);

  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (abc.available()) {
    char cmd = abc.read();
    if (cmd=='f') {
      Serial.println('f');
      moveForward();
    } else if (cmd=='b') {
      Serial.println('b');
      turnBack();
    } else if (cmd=='r') {
      turnRight();
    } else if (cmd=='l') {
      turnLeft();
    } else if (cmd=='1') {
      redLed();
    } else if (cmd=='2') {
      greenLed();
    } else if (cmd=='3') {
      yellowLed();
    } else {
      digitalWrite(l1, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(l2, LOW);
      digitalWrite(r2, LOW);
      digitalWrite(red, LOW);
      digitalWrite(green, LOW);
      digitalWrite(yellow, LOW);
    }
  }
}

void moveForward() {
  analogWrite(l1, left_speed);
  analogWrite(r1, right_speed);
  digitalWrite(l2, LOW);
  digitalWrite(r2, LOW);
  Serial.write('O');
  delay(delay_forward);
  Serial.write('K');
  abc.write('K');
  bot_stop();
}

void turnRight() {
  delay(1000);
  analogWrite(l1, turn_left);
  digitalWrite(r1, LOW);
  digitalWrite(l2, LOW);
  analogWrite(r2, turn_right);
  delay(delay_90_r);
  abc.write('K');
  bot_stop();
}

void turnLeft() {
  delay(1000);
  digitalWrite(l1, LOW);
  analogWrite(r1, turn_right);
  analogWrite(l2, turn_left);
  digitalWrite(r2, LOW);
  delay(delay_90_l);
  abc.write('K');
  bot_stop();
}

void turnBack() {
  delay(1000);
  digitalWrite(l1, LOW);
  analogWrite(r1, turn_right);
  analogWrite(l2, turn_left);
  digitalWrite(r2, LOW);
  delay(delay_180);
  abc.write('K');
  bot_stop();
}

void redLed() {
  digitalWrite(red, HIGH);
  delay(3000);
  digitalWrite(red, LOW);
  abc.write('K');
  Serial.write('O');
}

void greenLed() {
  digitalWrite(green, HIGH);
  delay(3000);
  digitalWrite(green, LOW);
  abc.write('K');
}

void yellowLed() {
  digitalWrite(yellow, HIGH);
  delay(5000);
  digitalWrite(yellow, LOW);
  abc.write('K');
}

void bot_stop() {
  digitalWrite(l1, LOW);
  analogWrite(r1, 0);
  analogWrite(l2, 0);
  digitalWrite(r2, LOW);
}

