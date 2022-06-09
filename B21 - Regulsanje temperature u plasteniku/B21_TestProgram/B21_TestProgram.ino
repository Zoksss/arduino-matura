// ---  B21 - Regulisanje temperature u plasteniku (Test program)
// ---  Autor: Zoran Todorovic
// ---  09.06.2022.

// [Biblioteke] //
#include <dht.h> // ukljucivanje DHT biblioteke

dht DHT;

// [Promenljive za pinove] //
#define DHT11_PIN A0 // pin na koji je spojen DHT (analogni ili digitalni, ali digitalni preporucujem)
const int grejacLED = 11;   // pin na koji je spojen grejac (LED)
const int ventilatorLED = 9; // pin na koji je spojen ventilator (LED)


// [Custom map funkcija za decimalne (float) brojeve ] //
float mapFloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return float((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

void test(){
  DHT.read11(DHT11_PIN);
  float voltage = float(mapFloat(DHT.temperature, 0, 50, 0.5, 3));
  Serial.println("Napon = " + String(voltage) + "V");
  delay(1000);
  digitalWrite(grejacLED, HIGH);
  delay(1000);
  digitalWrite(ventilatorLED, HIGH);
  digitalWrite(grejacLED, LOW);
  delay(1000);
  digitalWrite(ventilatorLED, LOW);
}

void setup(){
  Serial.begin(9600);
  pinMode(grejacLED, OUTPUT);
  pinMode(ventilatorLED, OUTPUT);
  test();
}


void loop(){
  Serial.println("Test potenciometar: " + String((analogRead(A5) * (5000 / 1024.0) - 500) / 100));
  float temp = mapFloat(analogRead(A3), 0, 1024, 0 , 50);

  // [Regulsanje LED na osnovu DHT Temperature ] //
  if(temp < 20) digitalWrite(grejacLED, HIGH); 
  else if(temp >= 25 && digitalRead(grejacLED)) digitalWrite(grejacLED, LOW); 
  if(temp >= 30) digitalWrite(ventilatorLED, HIGH); 
  else if(temp <= 25 && digitalRead(ventilatorLED)) digitalWrite(ventilatorLED, LOW); 

  delay(200);
}
