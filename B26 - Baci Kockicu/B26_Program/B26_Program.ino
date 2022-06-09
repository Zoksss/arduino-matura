// ---  B26 - Baci kockicu 
// ---  Autor: Zoran Todorovic
// ---  09.06.2022.

// [ Biblioteke ] //
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);


int tasterZaBacanje = 6;


void setup() {
  pinMode(tasterZaBacanje, INPUT);
  Serial.begin(9600);
  // obavezni koraci za setup displeja
  lcd.begin();
  lcd.backlight();
  animacija(); // pozivanje test programa
  
}

void animacija(){
  lcd.clear(); // brise sve sa displeja*/

  for(int i = 0; i < 28; i++){
    lcd.clear();
     lcd.setCursor(i, 0);
    lcd.print("Dobar dan"); // postavljanje teksta displeja
    delay(107); // delay zbog 3 sekunde efekta
  }
  
  for(int i = 28; i > 0; i--){
    lcd.clear();
    lcd.setCursor(i, 0);
    lcd.print("Dobar dan"); // postavljanje teksta displeja
    delay(107); // delay zbog 3 sekunde efekta
  }
  lcd.setCursor(0, 0);
  lcd.print("Baci kocku");
}


bool debounce = false;
int broj = 0;


void loop() {
  Serial.println(broj);
  if(!digitalRead(tasterZaBacanje) && !debounce){
     broj = random(1,7);
     debounce = true;
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Vas broj je " + String(broj));
     
    if(broj == 6){
       lcd.setCursor(0,1);
       lcd.print("Ponovite bacannje!");
     }      

  }else if(digitalRead(tasterZaBacanje) && debounce){
    debounce = false;
  }
}
 
