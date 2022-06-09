// ---  B29 - Korona brojac (Test)
// ---  06.06.2022.

int A = 2, B = 3, C = 4, D = 5;

int ulazSenzor = 6;
int izlazSenzor = 7;

int displayGnd = 12;

int ljudiUProstoriji = 0;

void setup(){
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(displayGnd, OUTPUT);
  pinMode(ulazSenzor, INPUT_PULLUP);
  pinMode(izlazSenzor, INPUT_PULLUP);
  displayDigit(ljudiUProstoriji);
  digitalWrite(displayGnd, LOW);
  
}

void displayDigit(int number){
   if(number == 0){ // 0000
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
  }
  else if(number == 1){ // 0001
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
  }
  else if(number == 2){ // 0010
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
  }
  else if(number == 3){ // 0011
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
  }
  else if(number == 4){ // 0100
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
  }
  else if(number == 5){ // 0101
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
  }
  else if(number == 6){ // 0110
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
  }
  else if(number == 7){ // 0111
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
  }
  else if(number == 8){ // 1000
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
  }
  else if(number == 9){ // 1001
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
  }
}


int debounce = false;
int debounce2 = false;

// pomocne promeljive za treptanje bez delay() funckije
unsigned long previousMillis = 0;       
const long interval = 500; // vreme treptanja displjea (delay)
int displayState = LOW; 

void loop(){
  if(!digitalRead(ulazSenzor) && !debounce){
    debounce = true;
    ljudiUProstoriji+=ljudiUProstoriji>=5?0:1;
    displayDigit(ljudiUProstoriji);
  }
  else if(digitalRead(ulazSenzor) && debounce) debounce = false;
  
  if(!digitalRead(izlazSenzor) && !debounce2){
    debounce2 = true;
    ljudiUProstoriji -= ljudiUProstoriji <= 0 ? 0 : 1;
    displayDigit(ljudiUProstoriji);
  }
  else if(digitalRead(izlazSenzor) && debounce2) debounce2 = false;

  
  
  if(ljudiUProstoriji == 5){
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      if (displayState == LOW) displayState = HIGH;
      else displayState = LOW;

      digitalWrite(displayGnd, displayState);
    }
  }
  else{
    digitalWrite(displayGnd, LOW);
  }
  delay(50);
}
