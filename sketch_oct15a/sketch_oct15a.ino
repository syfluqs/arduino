#include <SoftwareSerial.h>

SoftwareSerial bt(10,11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bt.begin(9600);
  bt.println("Started");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(bt.available()) {
    Serial.println("asd");
  }
  
}
