int crvena = 3;
int zelena = 4;

float brzinaTreptanja = 0.5; // pocetna vrednost

bool zelenaUpljena = false;
bool crvenaUpaljena = false;

String komanda;

void setup(){
  Serial.begin(9600);
  pinMode(crvena, OUTPUT);
  pinMode(zelena, OUTPUT);
  Serial.println("Dostupne komande: #CRVENA, #ZELENA, #UVECAJ, #SMANJI");
  Serial.println("------------------------");
  Serial.println("Unesi komandu: ");   
}

unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 1000;      

void loop(){
  //while (Serial.available() == 0){}  
  komanda = Serial.readString(); // citanje sa serial monitora 
  if(komanda.startsWith("#CRVENA")) crvenaUpaljena = !crvenaUpaljena;
  else if(komanda.startsWith("#ZELENA")) zelenaUpljena = !zelenaUpljena;
  else if(komanda.startsWith("#UVECAJ")) { brzinaTreptanja+=0.5; Serial.println(brzinaTreptanja);}
  else if(komanda.startsWith("#SMANJI")) { brzinaTreptanja-=(brzinaTreptanja==0.5?0:0.5); Serial.println(brzinaTreptanja);}
  
  // treptanje bez delay()
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= (1000/(brzinaTreptanja+0.5))) {
    previousMillis = currentMillis;

    if (!digitalRead(crvena) && crvenaUpaljena) digitalWrite(crvena, HIGH);
    else if(digitalRead(crvena) && crvenaUpaljena) digitalWrite(crvena, LOW);
 
    if (!digitalRead(zelena) && zelenaUpljena) digitalWrite(zelena, HIGH);
    else if(digitalRead(zelena) && zelenaUpljena) digitalWrite(zelena, LOW);
    
  }  
  delay(10);
}
