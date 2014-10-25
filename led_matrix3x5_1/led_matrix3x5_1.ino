int x[] = {5,6,7}; //Cathode
int y[] = {9,10,11,12,13}; //Anode
int d = 0.5;
int on[20][2] = { {1,5}, {2,3} };

void setup()
{
  for (int i=0;i<3;i++)
  {
    pinMode(x[i],OUTPUT);
    digitalWrite(x[i],HIGH);
  }
  for (int i=0;i<5;i++)
  {
    pinMode(y[i],OUTPUT);
    digitalWrite(y[i], LOW);
  }
}

void loop()
{
  
  for (int i=0;on[i][0];i++)
  {
    //turning on
    digitalWrite(y[on[i][1]-1],HIGH);
    digitalWrite(x[on[i][0]-1],LOW);
    delay(d);
    //turning off
    digitalWrite(y[on[i][1]-1],LOW);
    digitalWrite(x[on[i][0]-1],HIGH);
    delay(d);
  }
  
}
