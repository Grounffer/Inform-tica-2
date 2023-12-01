/*
EJERCICIO 6
Copie el código fuente de su ejercicio 4 del TP3 de estructuras. Añada a su programa la
funcionalidad para guardar en archivo el arreglo de estructuras y para mostrarlo luego.
Use las funciones fread y fwrite para la lectura y escritura del archivo binario.
size_t fread(void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);
size_t fwrite(const void *ptr, size_t size_of_elements, size_t number_of_elements, FILE
*a_file);
Comente su código fuente para aclarar la funcionalidad de su
	programa.
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

struct punt {
	float x;
	float y;
}Puntos[100];

struct punt2 {
	float x;
	float y;
}Puntos2[100];

int validar(char []);

int main() {
	FILE *archivo1,*archivo2;
	
	char name[10];
	int i=0, band=0, n, coincidencias=0;
	float j=-5, pend, ord;
	//struct punt Puntos[100];
	//struct punt2 Puntos2[100];
	float DeltaY=0;
	
	j=-5;
	for(i=0;i<101;i++){
		Puntos[i].x=j;
		//Puntos[i].y=2-j/2; 	//si desea cambiar la función para encontrar más puntos que concuerden, modifique esta línea
		Puntos[i].y=j*j;
		j=j+0.1;		
	}
		
		//imprimir los puntos
		//for(i=0;i<101;i++){	printf("x: %.2f , ", Puntos[i].x);	printf("y: %.2f", Puntos[i].y);	 printf("\n");	}
		
	do{
	printf("\n ¿Qué desea hacer?");
	printf("\n 1) Ingresar datos");
	printf("\n 2) Comprobar si la recta ingresada corta a la función.");
	printf("\n 3) Guardar los puntos de las funciones en archivos."); 
	printf("\n 4) mostrar puntos de la FUNCION PRINCIPAL guardados en un archivo"); 
	printf("\n 5) mostrar puntos de la FUNCION CARGADA POR EL USUARIO guardados en un archivo "); 
	printf("\n 6) Salir.\n Opción seleccionada: "); 
	scanf("%d", &n);
	
	switch(n){
	case 1:
		
		printf("\n Ingrese el valor de la pendiente: ");
		fflush(stdin);
		scanf("%f", &pend);	
		printf("\n Ingrese el valor de la ordenada al origen: ");
		fflush(stdin);
		scanf("%f", &ord);
		fflush(stdin);
		
		/*
		cout<<"\npos 0";
		cout<<"\n\nx1= "<<Puntos[0].x<<"  x2= "<<Puntos2[0].x;
		cout<<"\ny1= "<<Puntos[0].y<<"  y2= "<<Puntos2[0].y;
		*/
		
		//cargo los puntos de la recta definida por el usuario
		j=-5;
		for(i=0;i<101;i++){
			Puntos2[i].x = j;
			Puntos2[i].y = (pend*j)+ord; 	
			j=j+0.1;		
		}
		/*
		cout<<"\npos 0";
		cout<<"\n\nx1= "<<Puntos[0].x<<"  x2= "<<Puntos2[0].x;
		cout<<"\ny1= "<<Puntos[0].y<<"  y2= "<<Puntos2[0].y;
		cout<<"\n\nPuntos1";
		//imprimir los puntos1
		for(i=0;i<101;i++){	printf("x1: %.2f , ", Puntos[i].x);	printf("y1: %.2f", Puntos[i].y);	 printf("\n");	}
		cout<<"\n\nPuntos2";
		//mostrar puntos2
		for(i=0;i<101;i++){	printf("x2: %.2f , ", Puntos2[i].x);	printf("y2: %.2f", Puntos2[i].y);	printf("\n");	}
		*/
		band=1;
	break;
	case 2:
		if(band==0){
			cout<<"\nERROR, NO HAY DATOS CARGADOS\n";
			break;
		};
		coincidencias=0;	//reinicio la bandera de coincidencias
		
		for(i=0;i<101;i++){
			
			//cout<<"\n\nx1= "<<Puntos[i].x<<"  x2= "<<Puntos2[i].x;
			//cout<<"\ny1= "<<Puntos[i].y<<"  y2= "<<Puntos2[i].y;
			
			if(Puntos[i].y>=Puntos2[i].y){ 	//si y1 >= y2, los resto. si y2 > y1 resto alrevez
				DeltaY=(Puntos[i].y - Puntos2[i].y);
			}else {
				DeltaY=(Puntos2[i].y - Puntos[i].y);
			}
			//cout<<"\nDeltaY: "<<DeltaY;
		
			if(DeltaY<0) DeltaY=DeltaY*(-1); //convierto DeltaY a positivo (val absoluto)
			
			//cout<<"\nDeltaY modificado: "<<DeltaY;
			
			if(DeltaY<0.12){
				coincidencias=1;
				printf("\n\nintersecan en el punto: ");
				printf("( %.2f , ", Puntos2[i].x);		
				printf(" %.2f ) \n", Puntos2[i].y);
			}
		}
		if(coincidencias==0) cout<<"\nLas funciones no se cortan en ningun punto";
	break;
		
	case 3:
		fflush(stdin);
		cout<<"\nIngrese el nombre de su archivo con su extension para la PRIMER FUNCION: \n";
		fgets(name,10,stdin);
		
		if(validar(name)==1) {
			cout<<"\nNombre de archivo valido";
			
			archivo1 = fopen(name, "wb");
			if(archivo1==NULL){
				cout<<"\nERROR AL ABRIR ARCHIVO\n";
				break;
			}else{
				
				fwrite(&Puntos,sizeof(struct punt), 101, archivo1);
				fclose(archivo1);
				printf("\nSe creó el archivo con éxito.");
			} 
		}else cout<<"\nERROR, EL NOMBRE DE ARCHIVO NO ES VALIDO\n";
		
		if(band==0){	//si no hay datos cargados en la segunda funcion, da error y no guarda en el archivo
			cout<<"\nERROR, NO HAY DATOS CARGADOS EN LA 2DA FUNCION\n";
			break;
		};
		
		fflush(stdin);
		cout<<"\nIngrese el nombre de su archivo con su extension para la SEGUNDA FUNCION: \n";
		fgets(name,10,stdin);
		
		if(validar(name)==1) {
			cout<<"\nNombre de archivo valido";
			
			archivo2 = fopen(name, "wb");
			if(archivo2==NULL){
				cout<<"\nERROR AL ABRIR ARCHIVO\n";
				break;
			}else{
				
				fwrite(&Puntos2,sizeof(struct punt), 101, archivo2);
				fclose(archivo2);
				printf("\nSe creó el archivo con éxito.");
			} 
		}else cout<<"\nERROR, EL NOMBRE DE ARCHIVO NO ES VALIDO\n";
		
	break;	
	
	case 4:
		fflush(stdin);
		cout<<"\nIngrese el nombre de su archivo con su extension: \n";
		fgets(name,10,stdin);
		
		if(validar(name)==1) {
			cout<<"\nNombre de archivo valido\n";
			
			archivo1 = fopen(name, "rb");
			if(archivo1==NULL){
				cout<<"\nERROR AL ABRIR ARCHIVO\n";
				break;
			}else{
				
				fread(&Puntos,sizeof(struct punt), 101, archivo1);
				fclose(archivo1);
				
				//imprimir los puntos
				for(i=0;i<100;i++){
					printf("x: %.2f , ", Puntos[i].x);		
					printf("y: %.2f", Puntos[i].y);
					printf("\n");
				}
				
			} 
		}else cout<<"\nERROR, EL NOMBRE DE ARCHIVO NO ES VALIDO\n";
	break;	
	
	case 5:
		fflush(stdin);
		cout<<"\nIngrese el nombre de su archivo con su extension: \n";
		fgets(name,10,stdin);
		
		if(validar(name)==1) {
			cout<<"\nNombre de archivo valido\n";
			
			archivo2 = fopen(name, "rb");
			if(archivo2==NULL){
				cout<<"\nERROR AL ABRIR ARCHIVO\n";
				break;
			}else{
				
				fread(&Puntos2,sizeof(struct punt), 101, archivo2);
				fclose(archivo2);
				
				//imprimir los puntos
				for(i=0;i<101;i++){	printf("x: %.2f , ", Puntos2[i].x);	printf("y: %.2f", Puntos2[i].y);printf("\n");}
				
			} 
		}else cout<<"\nERROR, EL NOMBRE DE ARCHIVO NO ES VALIDO\n";
		
		band=1; //indico que se han guardado datos en la funcion 2
		
		break;	
	
	default: break;
	}
	
	}while(n!=6);
	return 0;
}

int validar(char cad[]){
	
	int t = strlen(cad)-1; //tama?o de la cadena
	int e=0; //cuando encuentre un punto sera e=1, significa que hay extension
	int band=1; //si no hay caracteres especiales ser? band=1
	
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
	
