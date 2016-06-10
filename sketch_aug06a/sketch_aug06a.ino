#include <SoftwareSerial.h>

SoftwareSerial abc(8, 9);
int led = 0;

void setup()
{
  abc.begin(9600);
  pinMode(13, OUTPUT);
  abc.println("Started...");
  Serial.begin(9600);
  Serial.println("Serial started...");
}

void loop()
{
  if (abc.available())
  {
    int data = abc.read();
    if(data=='1')
    {
      led = 1;
      digitalWrite(13, led);
      abc.println("LED is on");
      Serial.println("LED is on");
    }
    else if (data=='0')
    {
      led = 0;
      digitalWrite(13, led);
      abc.println("LED is off");
      Serial.println("LED is off");
    }
    else if (data=='2')
    {
      while(1)
      {
        digitalWrite(13, HIGH);
        delay(1000);
        digitalWrite(13, LOW);
        delay(1000);
      }
  }
 }
}
