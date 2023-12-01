/*
Desarrollar un programa que solicite y alñmacene distintos conjuntos de datos numericos, contenidos en estructuras de tipo "niveles" y almacenarlos en 
un arreglo de estructuras llamado "datos" segun el tipo: 

struct niveles {int nivel 1; int nivel 2; int nivel 3;int nivel 4;}

Se deberan desarrollar funciones de busqueda de los valores ingresados por el usuario, que se encuentren en alguno de los niveles existentes.
en todos los conjuntos disponibles, indicando entre que niveles fue encontrado. Utilizar funciones que intercambien datos por referencia
El programa debe permitir obtener datos permanentemente hasta que el usuario lo determine.
*/
#include <iostream>
using namespace std;

const int n=3;

struct NIVELES{
	
	float nivel1;
	float nivel2;
	float nivel3;
	float nivel4;
	
}datos[n];

void cargar(struct NIVELES dat[]);
void buscar(struct NIVELES dat[],float *m);

int main(int argc, char *argv[]) {
	
	float m;//valor a buscar
	int t=0; //valor para ingresar acciones
	int band=0;
	
	do{
		
		cout<<"\nIngrese el nro de accion que desea realizar ";
		cout<<"\n1)Cargar valores";
		cout<<"\n2)buscar valores";
		cout<<"\n3)Salir";
		cout<<"\nIngrese un valor: ";
		
		cin>>t;
		
		switch(t){
		case 1:
			cout<<"\nCargando valores: ";
			band=1;
			cargar(datos);
			break;
			
		case 2:
			if(band==1){
				cout<<"\nQue valor desea buscar: ";
				cin>>m;
				
				buscar(datos,&m);
				cout<<"\n";
			}
			else{cout<<"\nError, no ha cargado valores";}
			break;
			
		default: break;
		}
		
	}while(t!=3);
	
	return 0;
}

void buscar(struct NIVELES dat[],float *m){
	
	int band=0;
	int L1=0;
	int L2=0;
	float lim_sup=100000;
	float lim_inf=-100000;
	
	for(int i=0;i<n;i++){
		cout<<"\n\nEn datos ["<<i<<"]";
		band=0;
		lim_inf=-100000;
		lim_sup=100000;
		
		if(datos[i].nivel1 == *m){ cout<<"\nm="<<*m<<" Está en el nivel 1"; band=1;}
		if(datos[i].nivel2 == *m){ cout<<"\nm="<<*m<<" Está en el nivel 2"; band=1;}
		if(datos[i].nivel3 == *m){ cout<<"\nm="<<*m<<" Está en el nivel 3"; band=1;}
		if(datos[i].nivel4 == *m){ cout<<"\nm="<<*m<<" Está en el nivel 4"; band=1;}
		
		if(band==0){
			if(datos[i].nivel1 - *m < 0 and datos[i].nivel1 - *m > lim_inf) {lim_inf=datos[i].nivel1- *m; L1=1;}
			if(datos[i].nivel1 - *m > 0 and datos[i].nivel1 - *m < lim_sup) {lim_sup=datos[i].nivel1- *m; L2=1;}
			
			if(datos[i].nivel2 - *m < 0 and datos[i].nivel2 - *m > lim_inf){ lim_inf=datos[i].nivel2- *m; L1=2;}
			if(datos[i].nivel2 - *m > 0 and datos[i].nivel2 - *m < lim_sup) {lim_sup=datos[i].nivel2- *m; L2=2;}
			
			if(datos[i].nivel3 - *m < 0 and datos[i].nivel3 - *m > lim_inf){ lim_inf=datos[i].nivel3- *m; L1=3;}
			if(datos[i].nivel3 - *m > 0 and datos[i].nivel3 - *m < lim_sup) {lim_sup=datos[i].nivel3- *m; L2=3;}
			
			if(datos[i].nivel4 - *m < 0 and datos[i].nivel4 - *m > lim_inf) {lim_inf=datos[i].nivel4- *m; L1=4;}
			if(datos[i].nivel4 - *m > 0 and datos[i].nivel4 - *m < lim_sup) {lim_sup=datos[i].nivel4- *m; L2=4;}
			
			if(lim_inf!=-100000 and lim_sup!=100000) {
				//cout<<"\nLimite Inferior: "<<lim_inf<<" L1= "<<L1;
				//cout<<"\nLimite Superior: "<<lim_sup<<" L2= "<<L2;
				cout<<"\nm="<<*m<<" Está entre los niveles "<<L1<<" y "<<L2;
			}
			else cout<<"\nNo hay coincidencias";
		}
	}
	
}
	
	void cargar(struct NIVELES dat[]){
		for(int i=0;i<n;i++){
			cout<<"\ndatos ["<<i<<"]";
			
			cout<<"\nnivel1: ";		
			cin>>datos[i].nivel1;
			cout<<"nivel2: ";
			cin>>datos[i].nivel2;
			cout<<"nivel3: ";
			cin>>datos[i].nivel3;
			cout<<"nivel4: ";
			cin>>datos[i].nivel4;
		}
	}
		
