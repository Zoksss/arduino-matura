// ---  B25 - Regulacija brzine UCN5088
// ---  Autor: Mateo Radic 
// ---  11.06.2022.

int button = 3;
int STEP_Pin = 5;

// [ Pomocne promenljive ]
bool debounce = false;
bool isMotorRunning = true; 
 
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
  pinMode(STEP_Pin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(button), button_change, CHANGE); // dodavanje interupta na dugme
}
 
void loop() {   
  if(isMotorRunning){
    int reading = analogRead(A0);
    int readingMap = map(reading, 0, 1024, 200, 1000); // pretvaranje analog reda u vrednosti od 20 - 100
    Serial.println(String(readingMap) + "%");        // ispisivanje brzine u procentima
    digitalWrite(STEP_Pin, HIGH);
    delayMicroseconds(readingMap/2);
    digitalWrite(STEP_Pin, LOW);
    delayMicroseconds(readingMap/2);
  } 
  else {
    Serial.println(isMotorRunning);
  }
}
