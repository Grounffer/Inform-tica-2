/*EJERCICIO 3
Debe tener al menos un archivo de texto con contenido ya creado. A modo de ejemplo en
esta consigna usamos Origen y Destino para referirse a los archivos de texto a usar.
Realice un programa que permita el ingreso de los dos nombres de archivo: uno Origen y
otro Destino.
Debe verificar que ambos archivos existan o estén disponibles y sean nombres válidos.
Luego debe permitir el ingreso de dos palabras.
Se deberá copiar el contenido del archivo Origen en el Destino, pero reemplazando toda
palabra que se encuentre igual a la primera ingresada, por la segunda ingresada.*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
using namespace std;

int validar(char []);

int main(int argc, char *argv[]) {
	
	FILE *origen,*destino;
	
	char name1[50],name2[20]; 	//nombre de los archivos
	char pal1[10],pal2[10]; 	//palabras para reemplazar
	char texto[1000],copia[1500]; 	//contenido de Origen
	
	int v=0; //v toma el valor de la funcion validar v=0, no valido. v=1, valido
	int i=0,k=0; //contador
	int coincidencias=0; //coincidencias de las letras en el texto a reemplazar
	int m=0; //indice de cadena copia
	do{		
		cout<<"\nQue archivo de ORIGEN desea abrir?\n";
		fgets(name1,50,stdin);
		v = validar(name1); //si es valido: v=1, sino: v=0
		if(v==1) {
			cout<<"\nNombre de archivo valido";
			origen = fopen(name1, "r"); //abro el archivo como lectura
			if (origen==NULL) {		////pregunto si el archivo se abrio correctamente, si no, da mensaje de error
				fputs ("\nFile error",stderr); 
				exit (1);
			}	
			cout<<"\nARCHIVO ABIERTO"; 
		}else cout<<"\nERROR, EL NOMBRE DE ARCHIVO NO ES VALIDO\n";
	}while(v==0);
	
	i=0;
	while(1) {
		
		texto[i] = fgetc(origen); //Lee de a un caracter a la vez y lo guarda en la variable
		
		// si estoy en el End Of File, sale del bucle
		if( feof(origen) ){ break ;	}
		//cout<<"\nd["<<i<<"] : "<<texto[i];
		i++;
	}
	texto[i-1]='\0'; //coloco el fin de cadena en lugar del salto de linea
	cout<<"\ni: "<<i;
	cout<<"\nTexto: "<<texto<<"[FIN]"; //Muestro el texto contenido en archivo origen
	
	fclose(origen); //cierro el archivo
	
	cout<<"\nPalabra que desea reemplazar?: ";
	fgets(pal1,10,stdin);
	pal1[strlen(pal1)-1]='\0';
	//cout<<"\npal1: "<<pal1<<"[FIN]";
	
	cout<<"\nCual palabra desea colocar en su lugar?: ";
	fgets(pal2,10,stdin);
	pal2[strlen(pal2)-1]='\0';
	//cout<<"\npal2: "<<pal2<<"[FIN]";
	
	int tamPal1=strlen(pal1);
	m=0;
	
	for(int j=0;j<i;j++){
		
		//cout<<"\ntexto["<<j<<"]: "<<texto[j];
		//cout<<"\npal1["<<k<<"]: "<<pal1[k];		
		
		k=0;
		coincidencias=0;
		if(texto[j]!=pal1[0]){
			copia[m]=texto[j];
			m++;
		}
		
		while(texto[j]==pal1[k] and j<i){
			
			//if(k==0) m=j;
			
			cout<<"\n\nENTRAMOS";
			cout<<"\ntexto["<<j<<"]: "<<texto[j];
			cout<<"\npal1["<<k<<"]: "<<pal1[k];
			coincidencias++;
			k++;
			j++;
			if(coincidencias==tamPal1) {
				cout<<"\n-------------------------------ACA esTA";
				
				for(int l=0;l<strlen(pal2);l++){
					copia[m]=pal2[l];
					m++;
				}
			}
		}
		j++;
	}
	
	cout<<"\n\ncopia: "<<copia;
	
	v=0;
	do{		
		cout<<"\nQue archivo de ORIGEN desea abrir?\n";
		fgets(name2,50,stdin);
		v = validar(name2); //si es valido: v=1, sino: v=0
		if(v==1) {
			cout<<"\nNombre de archivo valido";
			destino = fopen(name2, "w"); //abro el archivo como lectura
			if (destino==NULL) {		////pregunto si el archivo se abrio correctamente, si no, da mensaje de error
				fputs ("\nFile error",stderr); 
				exit (1);
			}	
			cout<<"\nARCHIVO ABIERTO"; 
		}else cout<<"\nERROR, EL NOMBRE DE ARCHIVO NO ES VALIDO\n";
	}while(v==0);
	
	fputs(copia,destino);
	
	fclose(destino);
	
	
	
	return 0;
}

int validar(char cad[]){
	
	int t = strlen(cad)-1; //tamaño de la cadena
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
			e++;
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
	
	//si hay UN solo punto e==1, y todos los caracteres son validos band==1, return 1; 
	if(e==1 and band==1) return 1;
	return 0;
}
	
