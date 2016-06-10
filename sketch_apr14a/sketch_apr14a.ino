#include <Servo.h>

Servo s1;
Servo s2;
int pos1=90;
int pos2=90;
int ldr1=0;
int ldr2=0;
int ldr3=0;
int ldr4=0;

int delta=30;

void setup() {
  // put your setup code here, to run once:
  s.attach(9);
  s.attach(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  ldr1 = analogRead(A0);
  ldr2 = analogRead(A1);
  ldr3 = analogRead(A2);
  ldr4 = analogRead(A3);

  diff1 = ldr1-ldr2;
  diff2 = ldr3-ldr4;

  if (diff1>=0) {
    while(diff1<delta) {
      s1.write(pos1);
      pos1-=1;
      delay(15);
    }
  } else if (diff1<0) {
    while((-1)*diff1<delta) {
      s1.write(pos1);
      pos1+=1;
      delay(15);
    }
  }

  if (diff2>=0) {
    while(diff2<delta) {
      s2.write(pos2);
      pos2-=1;
      delay(15);
    }
  } else if (diff2<0) {
    while((-1)*diff2<delta) {
      s2.write(pos2);
      pos2+=1;
      delay(15);
    }
  }
}
