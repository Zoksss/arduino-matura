// ---  B28 - Regulacija brzine ULN2003 (Test)
// ---  Autor: Zoran Todorovic
// ---  06.06.2022.

// [ Biblioteke ]
#include <Stepper.h>

int button = 3;

// [ Pomocne promenljive ]
bool debounce = false;
bool isMotorRunning = false; 
int stepsPerRevolution = 200;

 
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
 
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
  myStepper.setSpeed(60);
  attachInterrupt(digitalPinToInterrupt(button), button_change, CHANGE); // dodavanje interupta na dugme
}
 
void loop() {   
  if(isMotorRunning){
    myStepper.step(stepsPerRevolution);
  }
  Serial.println(String(analogRead(A0) * (5.0 / 1023.0)) + "V");
}
