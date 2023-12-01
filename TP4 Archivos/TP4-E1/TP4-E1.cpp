/*Recomendaciones:
? En este TP puede usar e incluir las librerías de c string.h, file.h, stdio.h, stdlib.h
? Recuerde validar si el archivo pudo ser creado/abierto, antes de continuar con el
resto del programa.
? Recuerde, al finalizar de manipular un archivo (leerlo, escribirlo, etc), cerrar el
archivo.
EJERCICIO 1
El nombre del archivo lo deberá ingresar el usuario. Ud. debe crear una función que se
encargue de validar el nombre de archivo ingresado. Puede usar funciones de la librería
string.h
Debe verificar que el nombre sólo tenga letras (mayúsculas o minúsculas) y/o números,
más la extensión del archivo.
Nombre del archivo —> ejemploCodigoFuente.c ? extensión del archivo
Ejemplos de nombres válidos: t3xt0.txt , codigo4.cpp, tp4.c, misNotas.txt
Ejemplos de nombres inválidos: t3xt0 (no tiene extensión de archivo), tp4-2.cpp (contiene
un guión), h. (olvidó la extensión), .cpp (olvidó el nombre), h*la.txt (contiene caracter
asterisco).
Luego del ingreso del nombre de archivo y su validación, deberá permitir que ingrese por
pantalla texto y luego almacenarlo en un archivo cuyo nombre ya eligió el usuario.
Posteriormente, partiendo del archivo cerrado, se deberá leer el contenido del archivo y
mostrarlo en pantalla.
Si se vuelve a abrir el mismo archivo (se ingresa el mismo nombre de archivo), deberá
añadirse el nuevo texto al final del archivo sin borrar su contenido anterior (modo append
“a” de apertura de archivo).*/
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int validar(char cad[]); //recibe una cadena y devuelve 1 si el nombre con extension es válido, sino devuelve 0

int main(int argc, char *argv[]) {
	
	FILE *fp;//declaro un puntero de tipo archivo 
	
	char cad[50]; //nombre del archivo
	char cad1[1000]; //texto a ingresar
	int v=0; //v toma el valor de la funcion validar v=0, no valido. v=1, valido
	int c=0;
	
	//mientras el archivo no sea valido....
	do{		
		cout<<"\nIngrese el nombre de su archivo con su extension: \n";
		fgets(cad,50,stdin);
		
		v = validar(cad); //si es valido: v=1, sino: v=0
		
		//cout<<"\nv= "<<v;
		if(v==1) {
			cout<<"\nNombre de archivo valido";
			
			fp = fopen(cad, "a"); //creo y abro el archivo nuevo
	
			if (fp==NULL) {		////pregunto si el archivo se abrio correctamente, si no, da mensaje de error
			fputs ("\nFile error",stderr); 
			exit (1);
			}	
			cout<<"\nARCHIVO CREADO"; 
			
		}else cout<<"\nERROR, EL NOMBRE DE ARCHIVO NO ES VALIDO\n";
	}while(v==0);
	
	//ya tengo abierto el archivo CAD, ahora ingreso el texto CAD1
	
	cout<<"\nEscriba lo que desa guardar en el archivo\n";
	fgets(cad1,1000,stdin);
	
	fputs(cad1, fp); //escribo en el archivo la cadena que ingresé dentro del programa
	
	fclose(fp);//cierro el archivo
	
	cout<<"\n\nMOSTRANDO EL ARCHIVO\n\n";
	
	fp = fopen(cad,"r"); //abro el archivo en modo lectura "read"
	
	while(1) {
		
		c = fgetc(fp); //Lee de a un caracter a la vez y lo guarda en la variable c
		
		if( feof(fp) ){ break ; } // f es de File, eof es de End Of File. Pregunta si estoy en el final de archivo
			
		printf("%c", c);
	}
	
	fclose(fp);
	
	cout<<"\nFin del programa";
	
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
