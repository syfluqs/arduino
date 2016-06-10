#include <LiquidCrystal.h>
int threshold = 500;
int t=0;
int a = 0;
int j=0;
double v = 0.0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
 
  lcd.begin(16,2);
  lcd.print("Voltage=");
  delay(1000);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  a = analogRead(0);
  v=0.0;
  if (a<5) {
    j=0;
    v = 0.0;
  }
  if (a>150 && a<210) {
    j=1;
    v = 9.0/8.0;
  }
  if (a>270 && a<340) {
    j=2;
    v = 9.0/4.0;
  }
  if (a>430 && a <480) {
    j=3;
    v = 27.0/8.0;
  }
  if (a>510 && a<570) {
    j=4;
    v = 4.5;
  }
  if (a>650 && a<690) {
    j=5;
    v = 45.0/8.0;
  }
  if (a>750 && a<790) {
    j=6;
    v = 27.0/4.0;
  }
  if (a>850) {
    j=7;
    v = 63.0/8.0;
  }
  lcd.setCursor(0,1);
  Serial.println(j);
  lcd.print(v);
  
}
