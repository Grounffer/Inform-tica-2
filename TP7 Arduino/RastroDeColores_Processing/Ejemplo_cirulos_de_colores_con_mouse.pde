void setup(){
size(1280,720);
}
void draw(){
  if(mousePressed){
  fill(0); //Si presiono el mouse, dibujaré de color negro
  }
  else{
  fill(255); //si no presiono el mouse, dibujaré de color blanco
  }
  ellipse(mouseX,mouseY,80,80);  
} 
