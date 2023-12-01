#include <iostream>
#include <ctime>

using namespace std;

class crono{
private:
public:
	crono(){
	}
	time_t iniciar(){
		time_t tiempoinicial = time(NULL);
		cout<<"El cronometro se ha iniciado"<<endl;
		return tiempoinicial;
	}
	time_t detener(){
		time_t tiempofinal = time(NULL);
		cout<<"El cronometro se ha detenido"<<endl;
		return tiempofinal;
	}
	void mostrar(time_t tiempotrans){
		cout<<"Tiempo cronometrado "<<tiempotrans/3600<<":"<<(tiempotrans%3600)/60<<":"<<tiempotrans%60<<endl;
	}
	int reanudar(){
		return 1;
	}
	int reset(){
		return 0;
	}
	void listarvueltas(time_t tiempoinicial, time_t vueltas[], int i){
		time_t tiempotrans;
		vueltas[0]=tiempoinicial;
		int j;
		for(j=1; j<i; j++){
			tiempotrans=vueltas[j]-vueltas[j-1];
			cout<<"Vuelta "<<j<<" "<<tiempotrans/3600<<":"<<(tiempotrans%3600)/60<<":"<<tiempotrans%60<<endl;
		}
	}
	void maxminvueltas(time_t tiempoinicial, time_t vueltas[], int i){
		vueltas[0]=tiempoinicial;
		int j;
		time_t tiempomax=(vueltas[1]-vueltas[0]), tiempomin=(vueltas[1]-vueltas[0]);
		for(j=1;j<=i;j++){
			if(tiempomax<vueltas[j]-vueltas[j-1]){
				tiempomax=vueltas[j]-vueltas[j-1];
			}
		}
		for(j=1;j<=i;j++){
			if(tiempomin>vueltas[j]-vueltas[j-1]){
				tiempomin=vueltas[j];
			}
		}
		cout<<"La vuelta mas larga fue de "<<tiempomax/3600<<":"<<(tiempomax%3600)/60<<":"<<tiempomax%60<<endl;
		cout<<"La vuelta mas corta fue de "<<tiempomin/3600<<":"<<(tiempomin%3600)/60<<":"<<tiempomin%60<<endl;
	};
};

int main(){
	crono microno;
	time_t tiempoinicial=0, tiempofinal=0, tiempotrans=0, vueltas[100];
	int estado=0, i=1, e=0;
	while(e!=8){
		cout<<"1. Iniciar cronometro"<<endl<<"2. Detener cronometro"<<endl<<"3. Mostrar tiempo cronometrado"<<endl<<"4. Reanudar cronometro"<<endl<<"5. Reestablecer cronometro"<<endl<<"6. Tomar tiempo parcial"<<endl<<"7. Mostrar vueltas"<<endl<<"8. Mostrar vuelta mas larga y mas corta"<<endl<<"9. Salir"<<endl;
		scanf("%d", &e);
		fflush(stdin);
		switch(e){
		case 1:
			if (estado==0){
			tiempoinicial=microno.iniciar();
			estado=1;
			}
			else cout<<"El cronometro ya esta iniciado"<<endl;
			break;
		case 2:
			if(estado==1){
			tiempofinal=microno.detener();
			estado=2;
			}else cout<<"El cronometro no esta iniciado, o ya se encuentra detenido"<<endl;
			break;
		case 3:
			if(estado==1){
				tiempotrans=time(NULL)-tiempoinicial;
				microno.mostrar(tiempotrans);
			}
			else if(estado==2){
				tiempotrans=tiempofinal-tiempoinicial;
				microno.mostrar(tiempotrans);
			}else cout<<"Tiempo cronometrado 00:00:00"<<endl;
			break;
		case 4:
			if(estado==2){
				estado=microno.reanudar();
			}else cout<<"El cronometro no se encuentra detenido"<<endl;
			break;
		case 5:
			estado=microno.reset();
			i=1;
			cout<<"Cronometro reestablecido"<<endl;
			break;
		case 6:
			if(estado==1){
				vueltas[i]=time(NULL);
				i++;
			}else cout<<"El cronometro no esta iniciado"<<endl;
			break;
		case 7:
			microno.listarvueltas(tiempoinicial, vueltas, i);
			break;
		case 8:
			microno.maxminvueltas(tiempoinicial, vueltas, i);
			break;
		}
	}
}
