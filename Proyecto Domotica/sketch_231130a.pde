import processing.serial.*;

Serial myPort;  // Serial communication object
int[] lights = {0, 0, 0, 0};  // State of lights in each room (0 off, 1 on)
boolean estado1=false;
boolean estado2=false;

void setup() {
  size(500, 350);
  println(Serial.list());                           //Imprime los puertos seriales usados por la pc
  myPort = new Serial(this, Serial.list()[1], 9600);  // Adjust the index based on your setup
}

void draw() {
  background(255);

  // Draw the rooms
  fill(200);
  rect(100, 100, 210, 180);
  rect(100, 100, 70, 90);

  // Draw the lights
  fill(255, 0, 0);  // Red color for off lights
  if (estado1==true || myPort.read() == 'a') {
      fill(238, 210, 2);  // Change to green if the light is on
  }
  ellipse(300, 150, 20, 20);
  ellipse(300, 230, 20, 20);
  fill(255, 0, 0);
  if (estado2==true  || myPort.read() == 'b') {
      fill(238, 210, 2);  // Change to green if the light is on
  }
  ellipse(110, 145, 20, 20);

}

void mousePressed() {
   if(dist(mouseX, mouseY, 300, 150) < 10){
   estado1=!estado1;
   myPort.write('a'); //envio una 'a' para encender el led
   }
   if(dist(mouseX, mouseY, 300, 230) < 10){
   estado1=!estado1;
   myPort.write('a'); //envio una 'a' para encender el led
   }
  if(dist(mouseX, mouseY, 110, 145) < 10){
   estado2=!estado2;
   myPort.write('b'); //envio una 'a' para encender el led
  }
}

/*void sendStateToArduino() {
  // Send the state of lights to Arduino through serial communication
  for (int i = 0; i < lights.length; i++) {
    myPort.write(str(lights[i]));
  }
}*/
