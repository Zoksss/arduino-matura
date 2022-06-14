// ---  B22 - Kontrola proizovdnje (Test program)
// ---  Autor: Zoran Todorovic
// ---  06.06.2022.

#include <Stepper.h>

const int button = 6; // pin na koji je povezano dugme

const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

// [ Pomocne promenljive ]
bool debounce = false;

void setup() {
  myStepper.setSpeed(60);
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  int senzor=map(analogRead(A0),0,1024,180,215);
  Serial.println(senzor);
  if(!digitalRead(button) && !debounce) {
    debounce=true;
  if(senzor>= 196 && senzor<=204){
    Serial.println("ISPRAVAN");
  myStepper.step(100);
  delay(1000);
  myStepper.step(-100);
  } else {
    Serial.println("NEISPRAVAN");
  myStepper.step(-100);
  delay(1000);
  myStepper.step(100);
    }
  } 
  else if (digitalRead(button) && debounce) debounce=false;
}
