  bool sensor1=false; 
  bool sensor2=false;
  int led1=8;
  int led2=9;
  int led3=10;  
  int boton1=5;
  int boton2=7;
  char Letra;
void setup() {
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(boton1,INPUT);
  pinMode(boton2,INPUT);
}

void loop() {
  Letra = Serial.read();
  
  if(digitalRead(boton1)==HIGH or Letra=='a'){
    delay(20);
    sensor1= !sensor1;
    digitalWrite(led1,sensor1);
    digitalWrite(led2,sensor1);
    Serial.write('a');
  }
  if(digitalRead(boton2)==HIGH or Letra=='b'){
    delay(20);
    sensor2= !sensor2;
    digitalWrite(led3, sensor2);
    Serial.write('b');
  }
  
}
