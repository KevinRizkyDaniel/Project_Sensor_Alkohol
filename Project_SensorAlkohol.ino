#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
int ALKOHOL_SENSOR_LOW=5;
int RED_LED=7;
int BLUE_LED=6;

void setup() {
  pinMode(ALKOHOL_SENSOR_LOW, INPUT_PULLUP);
  pinMode(RED_LED,OUTPUT);
  pinMode(BLUE_LED,OUTPUT);
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  lcd.print("SISTEM PENDETEKSI");
  lcd.setCursor(0,1);
  lcd.print("ALKOHOL");
  lcd.setCursor(0,2);
  lcd.print("TELEKOMUNIKASI PNJ");
  delay(1000);
}

void loop() {
  int ALKOHOL_SENSOR_LOW_READ = digitalRead(ALKOHOL_SENSOR_LOW);
  if (ALKOHOL_SENSOR_LOW_READ == LOW)
  {
    lcd.clear();
    lcd.setCursor(0, 3);
    lcd.print("ALCOHOL DETECTED");
    digitalWrite(RED_LED,HIGH);
    digitalWrite(BLUE_LED,LOW);
    delay(20);
  }
  else
  {
    lcd.clear();
    lcd.setCursor(0, 3);
    lcd.print("ALCOHOL NOT DETECTED");
    digitalWrite(BLUE_LED,HIGH);
    digitalWrite(RED_LED,LOW);
    delay(20);
  }
}
