/*
EJERCICIO 2
Realizar un programa que permita copiar archivos. El programa deberá abrir el archivo
“Origen” y crear un nuevo archivo “Destino” el cual resultará una copia exacta del primero
en tamaño y contenido.
El nombre del archivo “Origen” y su extensión lo ingresa el usuario. El nombre del archivo
“Destino” es de su elección, pero recuerde que DEBE mantener la extensión de archivo.
Pruebe la ejecución con distintos tipos de archivo (.txt, .cpp, .jpg u otros de imágenes)
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

int validar(char cad[]);
int main () {
	
	FILE *origen,*destino;//declaro punteros de tipo archivo 
	int v=0; //v toma el valor de la funcion validar v=0, no valido. v=1, valido
	int i=0;
	char d[1000]; //cadena de caracteres donde guardaré el contenido del archivo Origen
	char nombre[50]; 
	char ext[50]; 
	char texto[1000];
	char nombreDestino[1000]={"Destino"};
	
	do{		
		cout<<"\nIngrese el nombre de su archivo: ";
		fgets(nombre,50,stdin);
		cout<<"\nIngrese la extension de su archivo (ej: .txt , .cpp , .mp3): ";
		fgets(ext,50,stdin);
		
		v = validar(ext);
		
		//cout<<"\nv= "<<v;
		
		if(v==1) {
			cout<<"\nNombre de archivo valido, ";
	
			nombre[strlen(nombre)-1]='\0'; 
			//en el ultimo elemento de la cadena hay un salto de linea ( nombre[t-1]='\n' ) , el enter al ingresar la palabra
			//lo reemplazo con un fin de cadena para que no de error al guardar el nombre de archivo
			
			strcat(nombre,ext); //concateno el nombre con su extension
			
			cout<<"Cad Nombre: "<<nombre;
			
			origen = fopen(nombre, "w"); //creo o abro el archivo origen con su nuevo Nombre
			
			if (origen==NULL) {		////pregunto si el archivo se abrio correctamente, si no, da mensaje de error
				fputs ("\nFile error",stderr); 
				exit (1);
			}	
			
			cout<<"\nARCHIVO CREADO"; 
			
		}else cout<<"\nERROR, EL NOMBRE DE ARCHIVO NO ES VALIDO\n";
	}while(v==0);
	
	//ya tengo abierto el archivo CAD, ahora ingreso el texto CAD1
	
	cout<<"\nEscriba lo que desa guardar en el archivo\n";
	fgets(texto,1000,stdin);
	
	fputs(texto, origen); //escribo en el archivo la cadena que ingresé dentro del programa
	
	fclose(origen);//cierro el archivo origen
	
//CREO EL ARCHIVO DE DESTINO
	
	cout<<"Que nombre desea que tenga el archivo destino?: ";
	
	fgets(nombreDestino,50,stdin);
	
	nombreDestino[strlen(nombreDestino)-1]='\0'; //borro el caracter final de ENTER o salto de linea
	
	strcat(nombreDestino,ext);
	
	cout<<"nombre de destino: "<<nombreDestino<<"[FIN]\n";
	
	destino = fopen(nombreDestino,"w");
	
	if (destino==NULL) {		////pregunto si el archivo se abrio correctamente, si no, da mensaje de error
		fputs ("\nFile error",stderr); 
		exit (1);
	}

	fclose(destino);//cierro el archivo destino
	
	cout<<"\n\nGUARDANDO DATOS DE ORIGEN\n\n";

	origen = fopen(nombre,"r");
	
	i=0;
	while(1) {
		
		d[i] = fgetc(origen); //Lee de a un caracter a la vez y lo guarda en la variable
		
		if( feof(origen) ) {  // f es de File, eof es de End Of File. Pregunta si estoy en el final de archivo
			break ;
		}
		
		//printf("%c", d[i]);
		cout<<"\nd["<<i<<"] : "<<d[i];
		i++;
	}
	d[i-1]='\0';
	cout<<"\ni: "<<i;
	
	fclose(origen);

	cout<<"\n\nmostrando contenido de cadena\n\n";
	
	cout<<d<<"[FIN]";
	
	destino = fopen(nombreDestino,"w");
	
	fputs(d, destino); //escribo en el archivo la cadena que ingresé dentro del programa
	
	fclose(destino);//cierro el archivo origen
	
	cout<<"\nSE HA COPIADO EL CONTENIDO DEL ORIGEN, EN EL ARCHIVO DESTINO";
	
	return(0);
}

int validar(char cad[]){
	
	int t = strlen(cad)-1;
	int e=0; //cuando encuentre un punto sera e=1, significa que hay extension
	int band=1; //si no hay caracteres especiales será band=1
	//cout<<"\ncadena: "<<cad;
	//cout<<"\nt: "<<t;
	
	cad[t]='\0';//en cad[t]='\n' hay un salto de linea, el enter al ingresar la palabra
	//lo reemplazo con un fin de cadena para que no de error al guardar el nombre de archivo
	
	if(cad[t-1]=='.'){ 
		e=0; 
		cout<<"\nEROR Debe ingresar la extension del archivo"; 
		return 0; 
	}
	
	for(int i=0;i<t;i++){
		//cout<<"\ncad ["<<i<<"]= "<<cad[i];
		if(cad[i]=='.'){
			//cout<<"\n\nPUNTO++\n";
			e++; //cada vez que encuentra un punto, sumo 1 al contador
		}
		if( (cad[i]>='a' and cad[i]<='z') or (cad[i]>='A' and cad[i]<='Z') or (cad[i]>='0' and cad[i]<='9') or cad[i]=='.' ){
			//cout<<"\nletra valida";
		}
		else { 
			//cout<<"\nLetra NO VALIDA, band=0"; 
			band=0;
		}
	}	
	//cout<<"\ne="<<e<<" , band="<<band;
	if(e==1 and band==1) return 1;
	return 0;
}
	
