/*EJERCICIO 3 - Base de datos de mediciones
Debe utilizar arreglos de estructuras, estructuras anidadas y agrupar su código
en funciones creadas por Ud.
Desarrollar una base de datos de experimentos para un laboratorio.
Se debe contar con una base ya cargada de sensores (marca sensor, tipo,
unidad de medida). Por cada medición se carga la fecha, la hora, sensor, valor
medido, comentarios
El programa permitirá realizar, en cada momento, y cada vez que el usuario lo
desee, las siguientes operaciones, que debe implementar en funciones:
? Agregar una nueva medición.
? Eliminar mediciones existentes.
? Modificar mediciones existentes
? Búsquedas por fecha, sensor o valor medido.*/
#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

const int TMAX =5;

struct SENSOR{
	char marca[50];
	char tipo[50];
	char unid_med[50];
};

struct SENSOR sen1={"sony","distancia","m"};
struct SENSOR sen2={"philco","termico","°c"};
struct SENSOR sen3={"sanyo","presion","bar"};

struct MEDICION{
	char fecha[50];
	char hora[50];
	struct SENSOR sens_usado;
	float val_med=0;
	char coment[50];
}mediciones[TMAX];

void agregar(struct MEDICION med[],int *c);
void mostrar(struct MEDICION med[],int *c);
void modificar(struct MEDICION med[],int *c);
void buscar(struct MEDICION med[],int *c);
void mostrarBusqueda(struct MEDICION *med);
void eliminar(struct MEDICION med[],int *c);
void mostrarSensores();


int main(int argc, char *argv[]) {
	
	int n=0;//nro para ingresar acciones
	int c=0;//cantidad de mediciones cargadas
	
	cout<<"Bienvenido!";
	do{
		cout<<"\n\nIngrese el nro de accion que desea realizar:";
		cout<<"\n1)Agregar mediciones";
		cout<<"\n2)Eliminar mediciones";
		cout<<"\n3)Modificar mediciones";
		cout<<"\n4)Buscar mediciones";
		cout<<"\n5)Mostrar mediciones";
		cout<<"\n6)Mostrar SENSORES";
		cout<<"\n7)Salir\n";
		cin>>n;
		
		switch(n){
		case 1: 
			cout<<"\nAGREGAR MEDICION\n";
			agregar(mediciones,&c);
			break;
			
		case 2: 
			if(c==0) cout<<"\nError No hay mediciones realizadas";
			else {
			cout<<"\nELIMINAR MEDICION\n";
			//eliminar(Imagen,&c);
			}
			break;
			
		case 3: 
			if(c==0) cout<<"\nError No hay mediciones realizadas";
			else{	cout<<"\nMODIFICANDO";	modificar(mediciones,&c); }	
		break;
			
		case 4: 
			if(c==0) cout<<"\nError No hay mediciones realizadas";
			else {
			cout<<"\nBUSCAR MEDICION\n";
			buscar(mediciones,&c);
			}
		break;
		case 5: 
			if(c==0) cout<<"\nError No hay mediciones realizadas";
			else {
				cout<<"\nMOSTRANDO MEDICIONES";
				mostrar(mediciones,&c);
			}	
		break;
		case 6: cout<<"\nMOSTRANDO SENSORES"; mostrarSensores();
		break;
		default: break;
		}//llave del switch	
	}while(n!=7);
	return 0;
}

void agregar(struct MEDICION med[],int *c){

	int m=0;
	if(*c<=TMAX){
		cout<<"\nINGRESANDO MEDICION "<<*c;
		cout<<"\nIngrese la fecha: ";
		fflush(stdin);
		fgets(med[*c].fecha,50,stdin);
		cout<<"Ingrese la hora: ";
		fflush(stdin);
		fgets(med[*c].hora,50,stdin);
		
		do{
		cout<<"\nQue nro de sensor desea cargar?";
		cout<<"\n1) Sensor 1";
		cout<<"\n2) Sensor 2";
		cout<<"\n3) Sensor 3";
		cout<<"\nIngrese un valor: ";
		cin>>m;
		}
		while(m<1 or m>3);
		switch(m){
			case 1:	med[*c].sens_usado = sen1;	break;
			case 2:	med[*c].sens_usado = sen2;  break;
			case 3: med[*c].sens_usado = sen3;	break;
			default: break;
		}
		cout<<"Ingrese El valor medido: ";
		cin>>med[*c].val_med;
		cout<<"Ingrese un comentario: ";
		fflush(stdin);
		fgets(med[*c].coment,50,stdin);
		
		(*c)++;//Aumento la cant de mediciones ingresadas
	}
	else{
		cout<<"\nERROR No hay espacio";
	}
}
void mostrar(struct MEDICION med[],int *c){ 	
	for(int i=0;i<*c;i++){
		cout<<"\n\n------------MEDICION "<<i<<"-------------\n";
		cout<<"\nFecha: "<<med[i].fecha;
		cout<<"Hora: "<<med[i].hora;
		cout<<"SENSOR: ";
			cout<<"\n\tMarca: "<<med[i].sens_usado.marca;
			cout<<"\n\tTipo: "<<med[i].sens_usado.tipo;
			cout<<"\n\tUnidad de medida: "<<med[i].sens_usado.unid_med;
		cout<<"\n\nValor medido: "<<med[i].val_med;
		cout<<"\nComentarios: "<<med[i].coment;
}}

void mostrarSensores(){ 	
		cout<<"\n\nSENSOR 1: ";
		cout<<"\n\tMarca: "<<sen1.marca;
		cout<<"\n\tTipo: "<<sen1.tipo;
		cout<<"\n\tUnidad de medida: "<<sen1.unid_med;
		cout<<"\n\nSENSOR 2: ";
		cout<<"\n\tMarca: "<<sen2.marca;
		cout<<"\n\tTipo: "<<sen2.tipo;
		cout<<"\n\tUnidad de medida: "<<sen2.unid_med;
		cout<<"\n\nSENSOR 3: ";
		cout<<"\n\tMarca: "<<sen3.marca;
		cout<<"\n\tTipo: "<<sen3.tipo;
		cout<<"\n\tUnidad de medida: "<<sen3.unid_med;
}	
void modificar(struct MEDICION med[],int *c){
	int m=0;
	int n=0;
	do{
		cout<<"\nQue nro de MEDICION (entre 0 y "<<(*c)-1 <<") desea modificar? (Ingrese '-1' para salir)\ningrese un valor: ";
		cin>>m;
		if(m==-1) return;
	}while(m>=(*c) or m<0);
	
	cout<<"\nINGRESANDO MEDICION "<<m;
	cout<<"\nIngrese la fecha: ";
	fflush(stdin);
	fgets(med[m].fecha,50,stdin);
	cout<<"Ingrese la hora: ";
	fflush(stdin);
	fgets(med[m].hora,50,stdin);
	
	do{
		cout<<"\nQue nro de sensor desea cargar?";
		cout<<"\n1) Sensor 1";
		cout<<"\n2) Sensor 2";
		cout<<"\n3) Sensor 3";
		cout<<"\nIngrese un valor: ";
		cin>>n;
	}
	while(n<1 or n>3);
	switch(n){
	case 1:	med[m].sens_usado = sen1;	break;
	case 2:	med[m].sens_usado = sen2;  break;
	case 3: med[m].sens_usado = sen3;	break;
	default: break;
	}
	cout<<"Ingrese El valor medido: ";
	cin>>med[m].val_med;
	cout<<"Ingrese un comentario: ";
	fflush(stdin);
	fgets(med[m].coment,50,stdin);
	
}

void mostrarBusqueda(struct MEDICION *med){
	cout<<"\nFecha: "<<med->fecha;
	cout<<"Hora: "<<med->hora;
	cout<<"SENSOR: ";
	cout<<"\n\tMarca: "<<med->sens_usado.marca;
	cout<<"\n\tTipo: "<<med->sens_usado.tipo;
	cout<<"\n\tUnidad de medida: "<<med->sens_usado.unid_med;
	cout<<"\n\nValor medido: "<<med->val_med;
	cout<<"\nComentarios: "<<med->coment;
}
	
void buscar(struct MEDICION med[],int *c){
	int m=0;
	float b=0; //Numero a buscar
	int p=0; //nro de sensor a buscar
	char cad[50];//cadena a buscar
	int band=0; //band=1 si encuentra coincidencias
	do{
		band=0;//reinicio las coincidencias
		cout<<"\nBuscar por: ";
		cout<<"\n1)fecha";
		cout<<"\n2)Sensor";
		cout<<"\n3)Valor medido";
		cout<<"\n4)Volver al menu principal\n";
		cin>>m;
		if(m==4) return;
		switch(m){
			
		case 1:
			do{
				cout<<"\nQue FECHA desea buscar?: ";
				fflush(stdin);
				fgets(cad,50,stdin);
			}while(strlen(cad)>40);
			
			cout<<"\nResultado: ";
			for(int i=0;i<*c;i++){
				if(strcmp(cad, med[i].fecha )==0){
					band=1;
					cout<<"\n\nMEDICION "<<i<<"\n";
					mostrarBusqueda(&med[i]);
				}}
			if(band==0) cout<<"\nNo se encontraron coincidencias";
			cout<<endl<<"\nPresione una tecla para continuar\n";
			getch();
		break;
		case 2:
			do{
				cout<<"\nQue SENSOR desea buscar? (1,2 o 3): ";
				cin>>p;
			}while(p<1 or p>3);
			
			switch(p){
			case 1:
				cout<<"\nResultados para SENSOR 1: ";
				for(int i=0;i<*c;i++){
						if( strcmp(med[i].sens_usado.marca,sen1.marca)==0 and strcmp(med[i].sens_usado.tipo,sen1.tipo)==0  and strcmp(med[i].sens_usado.unid_med,sen1.unid_med)==0 ){
						band=1;
						cout<<"\n\nMEDICION "<<i<<"\n";
						mostrarBusqueda(&med[i]);
				}}
				if(band==0) cout<<"\nNo se encontraron coincidencias";
				cout<<endl<<"\nPresione una tecla para continuar\n";
				getch();
			break;
			case 2:
				cout<<"\nResultados para SENSOR 2: ";
				for(int i=0;i<*c;i++){
					if( strcmp(med[i].sens_usado.marca,sen2.marca)==0 and strcmp(med[i].sens_usado.tipo,sen2.tipo)==0  and strcmp(med[i].sens_usado.unid_med,sen2.unid_med)==0 ){
						band=1;
						cout<<"\n\nMEDICION "<<i<<"\n";
						mostrarBusqueda(&med[i]);
					}}
				if(band==0) cout<<"\nNo se encontraron coincidencias";
				cout<<endl<<"\nPresione una tecla para continuar\n";
				getch();
			break;
			case 3:
				cout<<"\nResultados para SENSOR 3: ";
				for(int i=0;i<*c;i++){
					if( strcmp(med[i].sens_usado.marca,sen3.marca)==0 and strcmp(med[i].sens_usado.tipo,sen3.tipo)==0  and strcmp(med[i].sens_usado.unid_med,sen3.unid_med)==0 ){
						band=1;
						cout<<"\n\nMEDICION "<<i<<"\n";
						mostrarBusqueda(&med[i]);
					}}
				if(band==0) cout<<"\nNo se encontraron coincidencias";
				cout<<endl<<"\nPresione una tecla para continuar\n";
				getch();
			break;
			default: break;
			}
		break;			
		case 3:
			do{
				cout<<"\nQue VALOR MEDIDO desea buscar?: ";
				cin>>b;
			}while(b>40);
			
			cout<<"\nResultado: ";
			for(int i=0;i<*c;i++){
				if(b==med[i].val_med){
					band=1;
					cout<<"\n\nMEDICION "<<i<<"\n";
					mostrarBusqueda(&med[i]);
				}}
			if(band==0) cout<<"\nNo se encontraron coincidencias";
			cout<<endl<<"\nPresione una tecla para continuar\n";
			getch();
		break;
		}
	}while(m!=4);
}
void eliminar(struct MEDICION med[],int *c){		
	int m=0;
	do{
		cout<<"\nQue nro de MEDICION (entre 0 y "<<(*c)-1 <<") desea ELIMINAR? (Ingrese '-1' para salir)\n ingrese un valor: ";
		cin>>m;
		if(m==-1) return;
	}while(m>=(*c) or m<0);
		
	cout<<"\nELIMINANDO MEDICION "<<m;
	for(int i=m; i<(*c)-1;i++){	//elimino una medicion y pongo la siguiente en su lugar, corro todas las MEDICIONES a una posicion anterior
		strcpy(med[i].fecha,med[i+1].fecha);
		strcpy(med[i].hora,med[i+1].hora);
		med[i].sens_usado = med[i+1].sens_usado;
		med[i].val_med=med[i+1].val_med;
		strcpy(med[i].coment,med[i+1].coment);	
	}
	(*c)--;//decremento el nro de MEDICIONES guardadas
}
