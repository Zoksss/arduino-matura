// ---  B23 - Regulacija brzine A4988 (Test)
// ---  Autor: Mateo Radic & Zoran Todorovic
// ---  11.06.2022.

int STEP_Pin = 5;
int button = 3;

bool debounce = false;
bool isMotorRunning = false; 

void button_change(){   // funkcija za interupt dugmeta
  if(!digitalRead(button) && !debounce) { 
    debounce = true; 
    isMotorRunning = true;
  }
  else if(debounce) debounce = false; 
}

void setup() {
 pinMode(STEP_Pin, OUTPUT);
 pinMode(A0, INPUT);
 Serial.begin(9600);
 pinMode(button, INPUT_PULLUP);
 attachInterrupt(digitalPinToInterrupt(button), button_change, CHANGE); // dodavanje interupta na dugme
}

void loop() {
  int reading = analogRead(A0);
  Serial.println(reading * (5.0 / 1023.0))
  if(isMotorRunning){
    digitalWrite(STEP_Pin, HIGH);
    delay(5);
    digitalWrite(STEP_Pin, LOW);
    delay(5);
  }
}
