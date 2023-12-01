#include "Timer.h"

String Recibido; // Vamos a recibir un string.
Timer clock;     // Creamos un objeto del tipo Timer
#define led 13

void setup() {

  Serial.begin(9600);
  pinMode(led,OUTPUT);
  Serial.setTimeout(100);
}

void loop() {

  if(Serial.available()>0){ //Observo los datos del puerto
    Recibido = Serial.readString(); //Leo el dato como un string
    if((Recibido == "A")||(Recibido == "a")){ 
      //si el caracter que recibo es A, inicio el temporizador y prendo el led de la placa.
      digitalWrite(led, HIGH);
      clock.inicioTemp();
    }
    if((Recibido == "D")||(Recibido == "d")){
      //si el caracter que recibo es D, finalizo el temporizador y apago el led de la placa.
      digitalWrite(led, LOW);
      clock.finTemp();
    }
    if((Recibido == "R")||(Recibido == "r")){
      //si caracter que recibo es R, calculo el tiempo transcurrido y lo mando por serial.
      Serial.println("Los segundos transcurridos son:");
      Serial.println((float)clock.diferencialTemp()/1000);
  }
}
