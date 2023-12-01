
class Timer{ //clase en la cual trabajaremos con las funciones del temporizador.
private:
  unsigned long tiempoInicio;
  unsigned long tiempoFinal;
  unsigned long diferencialTemp;
public:
  Timer();
  ~Timer(){}
  void inicioTemp();//funcion que inicia el temporizador
  void finTemp();   //funcion que finaliza el temporizador
  unsigned long diferencialTemp(); // funcion que devuevle el valor transcurrido del programa
};

Timer::Timer(){
   tiempoInicio = 0;
   tiempoFinal = 0;
   diferencialTemp = 0;
}

void Timer::inicioTemp(){
  tiempoInicio = millis();
}

void Timer::finTemp(){
  tiempoFinal = millis();
}

unsigned long Timer::diferencialTemp(){
  return (tiempoFinal - tiempoInicio);
}