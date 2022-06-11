// ---  B25 - Vlaznost zemljista
// ---  Autor: Mateo Radic
// ---  10.06.2022.

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

float zadatiStepenVlage = 27.5;
int statusZemlje = 0;

// pinovi za senzore
int senzorVlage = A0; 
int servoPin = 10;

Servo Servo1; 


void setup() {
  Servo1.attach(servoPin);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,0);
}

void loop() {
  Servo1.write(150);
  int reading = analogRead(senzorVlage); // ocitavanje sa pina
  float naponSenzora = reading;
  float vlaga = map(reading,0,1024,0,100);
  lcd.setCursor(0, 1); // tekst se prebacuje u drugi red
  lcd.print("Vlaga: "+String(vlaga)+"%");
  if(zadatiStepenVlage < vlaga && statusZemlje == 0) {
    lcd.setCursor(0,0);
    lcd.write("MOKRA ZEMLJA! ");
    statusZemlje = 1;
  } 
  else if(zadatiStepenVlage > vlaga && statusZemlje == 1) {
    lcd.setCursor(0,0);
    lcd.write("SUVA ZEMLJA!  ");
    statusZemlje = 0;
    Servo1.write(30);
    delay(1000);
    Servo1.write(150);
  }
  delay(2000); // osvezavanje svake 2 sekunde
}
 
