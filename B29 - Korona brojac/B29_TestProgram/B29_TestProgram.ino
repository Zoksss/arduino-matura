// ---  B29 - Korona brojac (Test)
// ---  06.06.2022.

int A = 2, B = 3, C = 4, D = 5;

int ulazSenzor = 6;
int izlazSenzor = 7;

int displayGnd = 12;

void setup(){
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(displayGnd, OUTPUT);
  pinMode(ulazSenzor, INPUT_PULLUP);
  pinMode(izlazSenzor, INPUT_PULLUP);
  displayDigit(0);
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

void loop(){
  if(!digitalRead(ulazSenzor)) { displayDigit(8); }
  else if(!digitalRead(izlazSenzor)) { displayDigit(0); }
}
