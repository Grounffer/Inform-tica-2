import processing.serial.*;

boolean estadoBoton = false; //defino el boton como apagado
//defino colores rgb
color Apagado = color(200,0,0);
color Prendido = color(0,200,0);
Serial MiSerial; //defino la variable que utilizare como puerto serial

void setup(){
size(800,600);                                    //defino una ventana grafica
println(Serial.list());                           //Imprime los puertos seriales usados por la pc
MiSerial=new Serial(this,Serial.list()[1],9600);    //definimos la variable MiSerial como un NUEVO puerto serial
}

void draw(){
  background(255);      //fonfr blanco
  if(estadoBoton==true){
    fill(Prendido);
  }else{
    fill(Apagado);
  }
  ellipse(200,200,100,100);
}

void mouseClicked(){ //funcion para realizar acciones cuando se lee un click del mouse
float distancia = dist(200,200,mouseX,mouseY); //calculo la distancia del mouse respecto del punto (200,200) el centro de mi circulo con la funcion "dist"
if(distancia<50){ //si la dist del mouse es menor al Radio quiere decir que estoy dentro del circulo
estadoBoton = !estadoBoton;
MiSerial.write('a'); //envio una 'a' para encender el led
}
}
