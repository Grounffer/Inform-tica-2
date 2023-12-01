int num;
bool state;
void setup() {
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  //pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  //pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  //pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}

void loop() {
 
    num--; 
  
    delay(1500); 

  if(num<0)num=9;
  
switch(num){
  case 0:
  digitalWrite(1,1);
  digitalWrite(2,1);
  //digitalWrite(3,0);
  digitalWrite(4,1);
  //digitalWrite(5,1);
  digitalWrite(6,1);
  digitalWrite(7,1);
  //digitalWrite(8,1);
  digitalWrite(9,1);
  digitalWrite(10,0);
  break;
    case 1:
  digitalWrite(1,0);
  digitalWrite(2,0);
  //digitalWrite(3,0);
  digitalWrite(4,1);
  //digitalWrite(5,1);
  digitalWrite(6,1);
  digitalWrite(7,0);
  //digitalWrite(8,0);
  digitalWrite(9,0);
  digitalWrite(10,0);
  break;
  case 2:
  digitalWrite(1,1);
  digitalWrite(2,1);
  digitalWrite(4,0);
  digitalWrite(6,1);
  digitalWrite(7,1);
  digitalWrite(9,0);
  digitalWrite(10,1);
  break;
    case 3:
  digitalWrite(1,0);
  digitalWrite(2,1);
  digitalWrite(4,1);
  digitalWrite(6,1);
  digitalWrite(7,1);
  digitalWrite(9,0);
  digitalWrite(10,1);
  break;
    case 4:
  digitalWrite(1,0);
  digitalWrite(2,0);
  digitalWrite(4,1);
  digitalWrite(6,1);
  digitalWrite(7,0);
  digitalWrite(9,1);
  digitalWrite(10,1);
  break;
    case 5:
  digitalWrite(1,0);
  digitalWrite(2,1);
  digitalWrite(4,1);
  digitalWrite(6,0);
  digitalWrite(7,1);
  digitalWrite(9,1);
  digitalWrite(10,1);
  break;
    case 6:
  digitalWrite(1,1);
  digitalWrite(2,1);
  digitalWrite(4,1);
  digitalWrite(6,0);
  digitalWrite(7,1);
  digitalWrite(9,1);
  digitalWrite(10,1);
  break;
    case 7:
  digitalWrite(1,0);
  digitalWrite(2,0);
  digitalWrite(4,1);
  digitalWrite(6,1);
  digitalWrite(7,1);
  digitalWrite(9,0);
  digitalWrite(10,0);
  break;
  case 8:
  digitalWrite(1,1);
  digitalWrite(2,1);
  digitalWrite(4,1);
  digitalWrite(6,1);
  digitalWrite(7,1);
  digitalWrite(9,1);
  digitalWrite(10,1);
  break;  
    case 9:
  digitalWrite(1,0);
  digitalWrite(2,1);
  digitalWrite(4,1);
  digitalWrite(6,1);
  digitalWrite(7,1);
  digitalWrite(9,1);
  digitalWrite(10,1);
  break;
  }
}
