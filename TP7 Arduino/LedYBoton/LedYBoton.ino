int led1 = 13;
bool estadoLed1 = false;

void setup() {
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  digitalWrite(led1,estadoLed1); //el led encendera o se apagara segun la variable estadoLed1
}

void loop() {
 
  if(Serial.available()){ //si hay comunicacion serial...
    char Letra = Serial.read(); //creo una variable y leo una letra
     if(Letra=='a'){
      estadoLed1 = !estadoLed1; //si es una 'a' cambio el estado del led
     }
     digitalWrite(led1,estadoLed1); //prendo o apago el led
  }
}
