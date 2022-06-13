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
  if(senzor && !isActive){
    // senzor je dektovao
    isActive = true;
    ukljucenPuta++;
    digitalWrite(crvena, HIGH);
    tone(buzzer, 1000); // upalice zvucnik sa frekvencijom od 1000Hz
    Serial.println("UPOZORENJE   " + String(ukljucenPuta));
  }
  else if(!senzor && isActive){
    digitalWrite(crvena, LOW);
    noTone(buzzer); // upalice zvucnik sa frekvencijom od 1000Hz
    isActive = false;
    Serial.println("Bezbedno");
  }
  delay(50);
 }
 
