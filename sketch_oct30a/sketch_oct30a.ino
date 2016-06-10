
int ch1,ch2,ch3,ch4;
void setup()
{
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A4,INPUT);
pinMode(A5,INPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
Serial.begin(9600);}

void loop()
{
ch1=pulseIn(A1,HIGH);
ch2=pulseIn(A2,HIGH);
ch3=pulseIn(A4,HIGH);
ch4=pulseIn(A5,HIGH);

if(ch3>1550)
{double m;
  m=((ch3-1550)/450)*255;
  if(ch1<1550&&ch1>1450) // straight
  { analogWrite(5,m);
  analogWrite(6,0);
  analogWrite(9,m);
  analogWrite(10,0);}
  if(ch1>1550) //turn right while moving
  {double j;
  j=((ch1-1550)/450)*255;
  analogWrite(5,0);
  analogWrite(6,j);
  analogWrite(5,j);
  analogWrite(6,0);}
  if(ch1<1450) //turn left while moving
  {double j;
  j=((ch1-1550)/450)*255;
  analogWrite(5,j);
  analogWrite(6,0);
  analogWrite(5,0);
  analogWrite(6,j);}
  
  
  if(ch3<1450)
{double m;
  m=((1450-ch3)/450)*255;
  if(ch1<1550&&ch1>1450) //straight
  { analogWrite(5,m);
  analogWrite(6,0);
  analogWrite(9,m);
  analogWrite(10,0);}
  if(ch1>1550) //turn right while moving
  {double j;
  j=((ch1-1550)/450)*255;
  analogWrite(5,0);
  analogWrite(6,j);
  analogWrite(5,j);
  analogWrite(6,0);}
  if(ch1<1450)  //turn left while moving
  {double j;
  j=((ch1-1550)/450)*255;
  analogWrite(5,j);
  analogWrite(6,0);
  analogWrite(5,0);
  analogWrite(6,j);}
  
  
if(ch3>1450&&ch3<1550)
{
  if(ch1>1450&&ch1<1550) //straight
  {analogWrite(5,0);
  analogWrite(6,0);
  analogWrite(9,0);
  analogWrite(10,0);}
  if(ch1>1550) //turn right while moving
  {double j;
  j=((ch1-1550)/450)*255;
  analogWrite(5,0);
  analogWrite(6,j);
  analogWrite(5,j);
  analogWrite(6,0);}
  if(ch1<1450) //turn left while moving
  {double j;
  j=((ch1-1550)/450)*255;
  analogWrite(5,j);
  analogWrite(6,0);
  analogWrite(5,0);
  analogWrite(6,j);}
  

}
}}}

