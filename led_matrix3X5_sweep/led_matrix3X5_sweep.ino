int x[] = {5,6,7};         //LED Cathodes
int y[] = {9,10,11,12,13}; //LED Anodes
int d = 1;                 //time delay in milliseconds between each iteration
int r = 15;                //repition for each sequence

//define pattern sequence here
int on[10][20][2] = { 
  { {1,1},{2,1},{3,1} },
  { {1,2},{2,2},{3,2} },
  { {1,3},{2,3},{3,3} },
  { {1,4},{2,4},{3,4} },
  { {1,5},{2,5},{3,5} },
  { {1,4},{2,4},{3,4} },
  { {1,3},{2,3},{3,3} },
  { {1,2},{2,2},{3,2} },
  { {1,1},{2,1},{3,1} },
  };
  
/* === DO NOT EDIT BELOW THIS === */

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
  for (int a=0;a<=9;a++)
  {
    for (int t=1;t<=r;t++)
    {
  for (int i=0;on[a][i][0];i++)
  {
    if (on[a][i][1]==9&&on[a][i][0]==9)
    {
      delay(d*2);
      //delayMicroseconds(d*2);
    }
    else
    {
    //turning on
    digitalWrite(y[on[a][i][1]-1],HIGH);
    digitalWrite(x[on[a][i][0]-1],LOW);
    delay(d);
    //delayMicroseconds(d);
    //turning off
    digitalWrite(y[on[a][i][1]-1],LOW);
    digitalWrite(x[on[a][i][0]-1],HIGH);
    delay(d);
    //delayMicroseconds(d);
    }
  }
    }
  }
}
