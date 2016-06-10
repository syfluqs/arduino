#include <SoftwareSerial.h>
SoftwareSerial abc(12,13);

void setup()
{
abc.begin(10600);
pinMode(6,OUTPUT);
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
pinMode(3,OUTPUT);
}

void loop()
{
 if(abc.available())
  {
    char a = abc.read();
   if(a=='F')
    {
      digitalWrite(6,HIGH);
      digitalWrite(3,LOW);
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
    }
   if(a=='B')
    {
      digitalWrite(6,LOW);
      digitalWrite(3,HIGH);
      digitalWrite(10,LOW);
      digitalWrite(11,HIGH);
    }

   if(a=='L')
    {
      digitalWrite(6,HIGH);
      digitalWrite(3,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
    }

   if(a=='R')
    {
      digitalWrite(6,LOW);
      digitalWrite(3,LOW);
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
    }
  }
}

