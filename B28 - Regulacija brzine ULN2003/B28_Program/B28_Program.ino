// ---  B28 - Regulacija brzine ULN2003
// ---  Autor: Zoran Todorovic
// ---  06.06.2022.

// [ Biblioteke ]
#include <Stepper.h>

int button = 3;

// [ Pomocne promenljive ]
bool debounce = false;
bool isMotorRunning = false; 

 
Stepper myStepper(64, 8, 9, 10, 11);
 
void button_change(){   // funkcija za interupt dugmeta
  if(!digitalRead(button) && !debounce) { 
    debounce = true; 
    isMotorRunning = !isMotorRunning; 
  }
  else if(debounce) { 
    debounce = false; 
  }
}
 
void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), button_change, CHANGE); // dodavanje interupta na dugme
}
 
void loop() {   
  if(isMotorRunning){
    int reading = analogRead(A0);
    int readingMap = map(reading, 0, 1024, 20, 100); // pretvaranje analog reda u vrednosti od 20 - 100
    Serial.println(String(readingMap) + "%");        // ispisivanje brzine u procentima
    myStepper.step(1);
    myStepper.setSpeed(readingMap);
  } 
  else {
    Serial.println("0%");
  }
}
