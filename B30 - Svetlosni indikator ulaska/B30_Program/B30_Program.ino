int crvena = 3;
int zelena = 4;

String komanda;

void setup(){
  Serial.begin(9600);
  pinMode(crvena, OUTPUT);
  pinMode(zelena, OUTPUT);
}



void loop(){
  komanda = Serial.readString(); // citanje sa serial monitora 
  if(komanda == "#TEST"){
    digitalWrite(crvena, HIGH);
    digitalWrite(zelena, HIGH);
    delay(1000);
    digitalWrite(crvena, LOW);
    digitalWrite(zelena, LOW);
  }
}
