// ---  B23 - Regulacija brzine A4988
// ---  Autor: Mateo Radic & Zoran Todorovic
// ---  11.06.2022.

int STEP_Pin = 5;
int button = 3;

bool debounce = false;
bool isMotorRunning = false; 

void button_change(){   // funkcija za interupt dugmeta
  if(!digitalRead(button) && !debounce) { 
    debounce = true; 
    isMotorRunning = !isMotorRunning; 
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
  if(isMotorRunning){
    int reading = analogRead(A0);
    Serial.println(map(reading, 0, 950, 20, 100));
    int stepDelay = map(reading, 0, 950, 10, 1);
    digitalWrite(STEP_Pin, HIGH);
    delay(stepDelay);
    digitalWrite(STEP_Pin, LOW);
    delay(stepDelay);
  }
  else Serial.println("0%");
}
