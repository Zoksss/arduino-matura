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
  if(!digitalRead(button)) myStepper.step(1);
  else Serial.println(String(analogRead(0) * (5.0 / 1023.0)) + "V");
  
}
