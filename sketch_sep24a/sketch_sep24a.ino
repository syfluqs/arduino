#define RX 2
#define TX 3
#define LEFT_1 5
#define LEFT_2 6
#define RIGHT_1 8
#define RIGHT_2 9

#include <SoftwareSerial.h>

SoftwareSerial abc(RX,TX);

void setup()
{
  pinMode(LEFT_1, OUTPUT);
  pinMode(RIGHT_1, OUTPUT);
  pinMode(LEFT_2, OUTPUT);
  pinMode(RIGHT_2, OUTPUT);
  pinMode(13, OUTPUT);
  
  
  abc.begin(9600);
  
  digitalWrite(LEFT_1, LOW);
  digitalWrite(LEFT_2, LOW);
  digitalWrite(RIGHT_1, LOW);
  digitalWrite(RIGHT_2, HIGH);
}

void loop()
{
  if(abc.available())
  {
    char a = abc.read();
    abc.println(a);
    if (a=='1')
    {
      digitalWrite(LEFT_1, HIGH);
      digitalWrite(RIGHT_1, HIGH);
      digitalWrite(LEFT_2, LOW);
      digitalWrite(RIGHT_2, LOW);
    }
  else if (a=='2')
{
digitalWrite(LEFT_1, LOW);
digitalWrite(RIGHT_1, HIGH);
digitalWrite(LEFT_2, HIGH);
digitalWrite(RIGHT_2, LOW);
}
else if (a=='3')
{
  digitalWrite(LEFT_1, HIGH);
  digitalWrite(LEFT_2, LOW);
  digitalWrite(RIGHT_1, LOW);
  digitalWrite(RIGHT_2, HIGH);
}
else if (a=='4')
{
  digitalWrite(LEFT_1, LOW);
  digitalWrite(LEFT_2, HIGH);
  digitalWrite(RIGHT_1, LOW);
  digitalWrite(RIGHT_2, HIGH);
}
else
{
  digitalWrite(LEFT_1, LOW);
  digitalWrite(LEFT_2, LOW);
  digitalWrite(RIGHT_1, LOW);
  digitalWrite(RIGHT_2, LOW);
}

  }
}
