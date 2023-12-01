#include <stdio.h>
#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

int main(int argc, char *argv[]) {
	
	FILE *archivo;
	
	//IMPRIMIENDO CON FORMATO
	
	archivo=fopen("Archivo_fprintf.txt","w+");
	
	if (archivo==NULL) { cout<<"Error al abrir el archivo"; }
	else {
		fprintf(archivo,"Entero: %d\nDecimal:%0+*.4f",50,10,35.7);
		//fprintf(stdout,"Entero: %d\nDecimal:%0+*.4f",50,10,35.7);
		//salida por pantalla:
		
			//Entero: 50
			//Decimal:+0035.7000		
	}
	fclose(archivo);
	
	//GUARDO DENUEVO
	archivo=fopen("Archivo_fprintf.txt","w+");
		if (archivo==NULL) { cout<<"Error al abrir el archivo"; }
		else {
			fprintf(archivo,"H %d %d H %d",10,13,23);
		}
	fclose(archivo);
	
	//LEYENDO CON FORMATO
	
	int a,b,c;
	char l1,l2;
	
	archivo=fopen("Archivo_fprintf.txt","r");
	
	if (archivo==NULL) { cout<<"Error al abrir el archivo"; }
	else {
		//fscanf(archivo,"formatos", variables donde guardaré los datos leidos);
		fscanf(archivo,"%c%d%d",&l1,&a,&b);

	}
	fclose(archivo);

	cout<<"\nTenemos: "<<l1<<" "<<a<<" "<<b;
	
	return 0;
}

