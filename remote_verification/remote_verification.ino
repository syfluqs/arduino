const int d=100;
const long int t=50000;
int ch1,ch2,ch3,ch4,ch5,ch6;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("online");
pinMode(13, OUTPUT);
digitalWrite(13, HIGH);
delay(1000);
digitalWrite(13, LOW);
delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  ch1 = pulseIn(A0, HIGH,t);
  ch2 = pulseIn(A1, HIGH,t);
  ch3 = pulseIn(A2, HIGH,t);
  ch4 = pulseIn(A3, HIGH,t);
  ch5 = pulseIn(A4, HIGH,t);
  ch6 = pulseIn(A5, HIGH,t);

  Serial.print(ch1);
  Serial.print("--");
  Serial.print(ch2);
  Serial.print("--");
  Serial.print(ch3);
  Serial.print("--");
  Serial.print(ch4);
  Serial.print("--");
  Serial.print(ch5);
  Serial.print("--");
  Serial.print(ch6);
  Serial.println();

  delay(d);
}
