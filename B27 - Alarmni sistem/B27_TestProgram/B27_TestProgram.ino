// ---  B27 - Alarmni sistem
// ---  09.06.2022.


// pinovi za elemente
int crvena = 6;
int buzzer = 7; // zvucnik
int pirSenzor = 8;

int ukljucenPuta = 0;


void setup() {
  Serial.begin(9600);
  pinMode(crvena, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(pirSenzor, INPUT);
}

// pomocna promeljiva
bool isActive = false;

void loop() {
  int senzor = digitalRead(pirSenzor); // citanje sa senora (0 ili 1)
  Serial.println(senzor);
  if(senzor){
    digitalWrite(crvena, HIGH);
    tone(buzzer, 2000);
    delay(1000);
    noTone(buzzer);
  }
 }
 
