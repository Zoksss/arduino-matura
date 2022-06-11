// ---  B25 - Regulacija brzine UCN5088 (Test)
// ---  06.06.2022.


int button = 3;
int STEP_Pin = 5;

// [ Pomocne promenljive ]
bool debounce = false;
bool isMotorRunning = false; 
 
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
  pinMode(button, INPUT);
  pinMode(STEP_Pin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(button), button_change, CHANGE); // dodavanje interupta na dugme
}
 
void loop() {   
  if(isMotorRunning){
    digitalWrite(STEP_Pin, HIGH);
    delay(2);
    digitalWrite(STEP_Pin, LOW);
    delay(2);
  }
  Serial.println(String(analogRead(0) * (5.0 / 1023.0)) + "V");
}
