// ---  B26 - Baci kockicu (Test)
// ---  Autor: Zoran Todorovic
// ---  09.06.2022.

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int tasterZaBacanje = 6;

void setup() {
  pinMode(tasterZaBacanje, INPUT_PULLUP);
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Dobar dan");
}


void loop() {
  Serial.println(broj);
  if(!digitalRead(tasterZaBacanje)){
     lcd.clear();
     lcd.print("Zdravo");
  }
}
 
