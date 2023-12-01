#include <stdio.h>
#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

int main () {
	
	char mensaje[50]="Ejemplo de prueba 123456789.";
	char mensaje2[50]=" Segunda parte del ejemplo en archivos";
	char cad[100];
	int i=0; //contador
	int c=0; //lo uso para leer archivos
		
	FILE *archivo1,*archivo2,*archivo3;//creo punteros de tipo FILE 
	
	//abro los 3 archivos 
	archivo1=fopen("ArchivoPrueba1.txt","a");
	archivo2=fopen("ArchivoPrueba2.txt","ab+");
	archivo3=fopen("ArchivoPrueba3.txt","w+");
	
	if(archivo1 and archivo2 and archivo3)	cout<<"Apertura exitosa";
	else cout<<"Problemas al abrir los archivos";
	
	int fcloseall(); //retorna 0 si cerro correctamente o EOF si falla
		
	// int fputc(char mensaje[i], FILE archivo);
	//fputc imprime en el archivo un solo caracter por vez
	
	archivo3=fopen("ArchivoPrueba3.txt","w+"); //abro el archivo3
	
	if (archivo3==NULL) {////pregunto si el archivo se abrio correctamente, si no, da mensaje de error
		fputs ("\nFile error",stderr); 
		exit(0);
	}else {
		cout<<"\nApertura exitosa 2";
		
		while(mensaje[i]){ //mientras haya caracteres en la cadena mensaje...
			fputc(mensaje[i],archivo3); //escribe el caracter [i] en el archivo
		i++;
		}
	}
	fclose(archivo3);
	
	//para leer de a un caracter a la vez
	// fgetc(FILE archivo);
	
	cout<<"\n\nLeyendo el archivo en que guarde de a un caracter con fputc: \n";
	
	archivo3=fopen("ArchivoPrueba3.txt","r");
	
	while(1) {
		c = fgetc(archivo3); //Lee de a un caracter a la vez y lo guarda en la variable c
		if( feof(archivo3) ) {  // f es de File, eof es de End Of File. Pregunta si estoy en el final de archivo
			break ;
		}
		printf("%c", c);
	}
	fclose(archivo3);
	
	//Para escribir toda una cadena en el archivo 
	//sin incluir el caracter nulo \0 y coloca el cursor al final
	// fputs(char cadena,FILE archivo);
	
	archivo3=fopen("ArchivoPrueba3.txt","a");
	
	if (archivo3==NULL) {////pregunto si el archivo se abrio correctamente, si no, da mensaje de error
		cout<<"Error al abrir el archivo";
	}else {
		fputs(mensaje2,archivo3); //Guardo el mensaje 2 completamente
	}
	fclose(archivo3);
	
	//Leo el contenido de archivo con fgetc(archivo3); 
	//Lee de a un caracter a la vez y el cursor avanza al siguiente carácter
	
	cout<<"\n\nLeyendo un archivo: \n";
	archivo3=fopen("ArchivoPrueba3.txt","r");
	
	if (archivo3==NULL) { cout<<"Error al abrir el archivo"; }
	else {
		while(feof(archivo3)==0){	//mientras no esté en el final de archivo...		
			cout<<(char)fgetc(archivo3);
		}
	}	
	fclose(archivo3);
	
	//GUARDANDO en una cadena
	
	i=0;
	
	cout<<"\n\nGuardando en una cadena lo que hay en el archivo: ";
	archivo3=fopen("ArchivoPrueba3.txt","r");
	
	if (archivo3==NULL) { cout<<"Error al abrir el archivo"; }
	else {
		while(feof(archivo3)==0){
			cad[i]=fgetc(archivo3);
			i++;
		}
		cad[i]='\0'; //en la ultima posicion guardo el fin de cadena
		cout<<"COMPLETADO\n";
	}
	fclose(archivo3);
	
	cout<<"\nContenido de la cadena: \n";
	puts(cad);
	
	// fgets(cad,n,archivo);
	// Lee los n carácteres hasta el EOF y los guarda en una cadena insertando el '\0'
	cout<<"\n\nGuardando en una cadena los n caracteres del archivo: ";
	archivo3=fopen("ArchivoPrueba3.txt","r");
	
	if (archivo3==NULL) { cout<<"Error al abrir el archivo"; }
	else {
		fgets(cad,34,archivo3);
	}
	cout<<"\nContenido de la cadena: \n";
	puts(cad);
	return(0);
}
