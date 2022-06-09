// ---  B21 - Regulisanje temperature u plasteniku
// ---  Autor: Zoran Todorovic
// ---  09.06.2022.


// [Biblioteke] //
#include <dht.h> // ukljucivanje DHT biblioteke

dht DHT;

// [Promenljive za pinove] //
#define DHT11_PIN A0 // pin na koji je spojen DHT (analogni ili digitalni, ali digitalni preporucujem)
const int grejacLED = 11;   // pin na koji je spojen grejac (LED)
const int ventilatorLED = 9; // pin na koji je spojen ventilator (LED)


void setup(){
  Serial.begin(9600);
  pinMode(grejacLED, OUTPUT);
  pinMode(ventilatorLED, OUTPUT);
}


void loop(){
  DHT.read11(DHT11_PIN);
  Serial.println("DHT11: " + String(DHT.temperature) + "°C");

  // [Regulsanje LED na osnovu DHT Temperature ] //
  if(DHT.temperature < 20) digitalWrite(grejacLED, HIGH); 
  else if(DHT.temperature >= 25 && digitalRead(grejacLED)) digitalWrite(grejacLED, LOW); 
  if(DHT.temperature >= 30) digitalWrite(ventilatorLED, HIGH); 
  else if(DHT.temperature <= 25 && digitalRead(ventilatorLED)) digitalWrite(ventilatorLED, LOW); 

  delay(200);
}
