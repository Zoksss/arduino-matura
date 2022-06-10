// ---  B25 - Vlaznost zemljista [TEST]
// ---  Autor: Zoran Todorovic
// ---  10.06.2022.

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);


// pinovi za senzor
int senzorVlage = A0; 
int servoPin = 10;

Servo Servo1; 


void setup() {
  Servo1.attach(servoPin);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,0);
  Servo1.write(180);
  delay(1000);
  Servo1.write(0);
}

void loop() {
  lcd.clear();
  lcd.print(analogRead(senzorVlage));
  delay(500);
}
 
