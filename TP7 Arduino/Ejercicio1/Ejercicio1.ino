bool c = true;
#define led1 9
#define led2 10
#define boton1 5
#define boton2 12
#define boton3 13
int led = led1; //defino el led1 como el led en que comienzo a trabajar

void setup() {
  //defino los pulsadores y led
  pinMode(boton1,INPUT);
  pinMode(boton2,INPUT);
  pinMode(boton3,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}

void loop() {
    //Si el botón 1 es pulsado, inicio el led en LOW y aumenta su luz
  if(digitalRead(boton1)==HIGH){
      delay(20);
      digitalWrite(led,LOW);
      int i=0;
      for(i=0;i<256;i++){
        analogWrite(led,i);
        delay(10);
      }
    }
  //Si el botón 2 es pulsado, inicio el led en HIGH y disminuye su luz
    if(digitalRead(boton2)==HIGH){
      delay(20);
      digitalWrite(led,HIGH);
      int i = 256;
      for(i=256;i>=0;i--){
        analogWrite(led,i);
        delay(10);
      }
    }
    //Cambio el led en el que trabajo
    if(digitalRead(boton3)){
      delay(20);
      if(c){
        led = led2;
        c = false;
        delay(200);
      }else{
        led = led1;
        c = true;
        delay(200);
      }
    }
}
