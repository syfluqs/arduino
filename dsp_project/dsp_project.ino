void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT); //red
  pinMode(11, OUTPUT); //green
  pinMode(10, OUTPUT); //blue
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    char s = Serial.read();
    if (s=='r') {
      digitalWrite(12, HIGH);
    } else if (s=='g') {
      digitalWrite(11, HIGH);
    } else if (s=='b') {
      digitalWrite(10, HIGH);
    } else if (s=='R') {
      digitalWrite(12, LOW);
    } else if (s=='G') {
      digitalWrite(11, LOW);
    } else if (s=='B') {
      digitalWrite(10, LOW);
    } else {
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
    }
  }
}
