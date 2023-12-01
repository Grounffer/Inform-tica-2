/*
EJERCICIO 1
Basándose en su código fuente de su ejercicio 4 del TP4 de archivos, va a trabajar con
listas enlazadas para una base de datos de imágenes.
Puede tener pre-cargada algunos nodos a su lista. La lista debe ser simplemente
enlazada.
Debe crear funciones que permitan al usuario:
? añadir un nodo a la lista,
? eliminarlo de la lista,
? guardar la lista completa en un archivo ( modo append y binario),
? recuperar/leer esa lista del archivo,
? realizar búsquedas: por cualquiera de los miembros de la estructura imagen (tipo
archivo, nombre, etc). En el caso del tamaño del archivo, especificar si se busca
mayor a X tamaño (ingresado por teclado) o menor a X o un valor exacto de
tamaño.
? Mostrar la lista para visualizar todos sus elementos.
? Mostrar la lista ordenada alfabéticamente según el nombre del archivo.
Comente su código fuente para aclarar la funcionalidad de su programa.
	Recuerde que puede visualizar los archivos binarios usando diversas herramientas, ver
	apunte unidad Archivos, pdf “¿Cómo visualizamos los archivos binarios?
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct nodo{
	char nombre[30];
	char extension[5];
	int codigo;
	int tamano;
	int precio;
	struct nodo* siguiente;
};
//eliminar salto de linea de una cadena al usar fgets
	void limpiar(char string[]){ string[strlen(string)-1]='\0'; }
	
	struct nodo* nodonuevo(struct nodo* cabeza, char nombre[], char extension[], int codigo, int tamano, int precio)
	{ //crear un nodo nuevo
	
		struct nodo* nuevonodo = (struct nodo*)malloc(sizeof(struct nodo)); //creo el nodo nuevo y copio los parametros 
	
		strcpy(nuevonodo->nombre, nombre);
		strcpy(nuevonodo->extension, extension);
		nuevonodo->codigo=codigo;
		nuevonodo->tamano=tamano;
		nuevonodo->precio=precio;
		nuevonodo->siguiente=NULL;
		
		if(cabeza==NULL){	cabeza=nuevonodo;  }	//si el nodo es el primero lo defino como la cabeza, luego devuelvo este valor para usarlo mas tarde
		else{
			struct nodo* temp = cabeza;
			while(temp->siguiente!=NULL){
				temp=temp->siguiente;
			}									//de lo contrario, busco el ultimo nodo y configuro su siguiente para apuntar al nodo nuevo
			temp->siguiente = nuevonodo;
		}
		return cabeza;
	}
		
int eliminarnodo(struct nodo* cabeza, int codigo){ //funcion para eliminar un nodo
	if(cabeza==NULL){  //devuelve 0 si no hay nodos
		return 0;
	}
	else{
		struct nodo* temp=cabeza;
		do{	
			if(codigo==temp->codigo){ //recorre la lista hasta encontrar un nodo con el codigo ingresado
			if(temp==cabeza){
				cabeza=cabeza->siguiente;
				free(temp);							//elimina el nodo si es la cabeza
				return 1;
			}
			else if(temp->siguiente==NULL){
				temp=cabeza;
				while((temp->siguiente)->siguiente!=NULL){
					temp=temp->siguiente;
				}													//elimina el nodo si es el ultimo 					
				free(temp->siguiente);
				temp->siguiente=NULL;
				return 1; 
			}
			else{
				temp=cabeza;
				while((temp->siguiente)->codigo!=codigo){
					temp=temp->siguiente;
				}
				temp->siguiente=(temp->siguiente)->siguiente;	//elimina el nodo si no es ni el primero ni el ultimo
				free(temp->siguiente);
				return 1;
			}
			}
			temp=temp->siguiente;
		} while(temp!=NULL);
	}
	return 0; 
}
int archivar(struct nodo* cabeza, FILE* file){ //funcion para guardar un nodo en un archivo
	if(cabeza==NULL){
		return 0;
	}
	else{
		struct nodo* temp = cabeza;
		while(temp!=NULL){			//recorre la lista, escribiendo nodo por nodo en el archivo hasta el fin de la lista
			fwrite(&temp, sizeof(struct nodo), 1, file);
			temp = temp->siguiente;
		}
	}
	return 1;
}
void leerarchivo(FILE* file){ //funcion para leer un archivo, no funciona
	struct nodo* temp;
	while((fread(&temp, sizeof(struct nodo), 1, file))==1){
	printf("Nombre: ");
	fputs(temp->nombre, stdout);
	printf("\nExtension: ");				//supuestamente toma un nodo del archivo y lo guarda en temp
	fputs(temp->extension, stdout);			//luego lo imprime, si hay mas nodos por guardar, repite el proceso
	printf("\nCodigo: %d\n", temp->codigo); 
	printf("Tamano: %d\n", temp->tamano);
	printf("Precio: %d\n\n", temp->precio);
	}
}

void buscar(struct nodo* cabeza){ //funcion para buscar un nodo
char nombre[30], extension[5];
int f, g, codigo, tamano, precio;
printf("\n1. Buscar por nombre\n2. Buscar por extension\n3. Buscar por codigo\n4. Buscar por tamano\n5. Buscar por precio\n");
scanf("%d", &f);
fflush(stdin);
struct nodo* temp = cabeza;
switch(f){
case 1: 
	printf("Ingrese un nombre:\n");
	fgets(nombre, 30, stdin);
	limpiar(nombre);
	do{
		if(strcmp(temp->nombre, nombre)==0){
			printf("Nombre: ");
			puts(temp->nombre);
			printf("Extension: ");							//toma un valor y recorre la lista
			puts(temp->extension);							//si un nodo tiene el nombre, extension, etc 
			printf("Codigo: %d\n", temp->codigo);			//ingresado lo imprime
			printf("Tamano: %d\n", temp->tamano);
			printf("Precio: %d\n\n", temp->precio);
			temp=temp->siguiente;
		}else temp = temp->siguiente;
	}while(temp!=NULL);
	break;
case 2: 
	printf("Ingrese una extension:\n");
	fgets(extension, 5, stdin);
	limpiar(extension);
	do{
		if(strcmp(temp->extension, extension)==0){
			printf("Nombre: ");
			puts(temp->nombre);
			printf("Extension: ");
			puts(temp->extension);
			printf("Codigo: %d\n", temp->codigo);
			printf("Tamano: %d\n", temp->tamano);
			printf("Precio: %d\n\n", temp->precio);
			temp=temp->siguiente;
		}else temp = temp->siguiente;
	}while(temp!=NULL);
	break;
case 3: 
	printf("Ingrese un codigo:\n");
	scanf("%d", &codigo);
	fflush(stdin);
	do{
		if(temp->codigo==codigo){
			printf("Nombre: ");
			puts(temp->nombre);
			printf("Extension: ");
			puts(temp->extension);
			printf("Codigo: %d\n", temp->codigo);
			printf("Tamano: %d\n", temp->tamano);
			printf("Precio: %d\n\n", temp->precio);
			temp=temp->siguiente;
		}else temp = temp->siguiente;
	}while(temp!=NULL);
	break;
case 4:
	printf("1. Buscar imagenes menores al tamaño ingresado\n2. Buscar imagenes mayores al tamaño ingresado\n3. Buscar imagenes con el tamaño exacto ingresado\n");
	scanf("%d", &g);
	fflush(stdin);
	printf("Ingrese el tamaño");
	scanf("%d", &tamano);
	fflush(stdin);
	switch(g){
	case 1:
		do{
			if(temp->tamano<tamano){
				printf("Nombre: ");
				puts(temp->nombre);
				printf("Extension: ");
				puts(temp->extension);
				printf("Codigo: %d\n", temp->codigo);
				printf("Tamano: %d\n", temp->tamano);
				printf("Precio: %d\n\n", temp->precio);
				temp=temp->siguiente;
			}else temp = temp->siguiente;
		}while(temp!=NULL);
		break;
	case 2:
		do{
			if(temp->tamano>tamano){
				printf("Nombre: ");
				puts(temp->nombre);
				printf("Extension: ");
				puts(temp->extension);
				printf("Codigo: %d\n", temp->codigo);
				printf("Tamano: %d\n", temp->tamano);
				printf("Precio: %d\n\n", temp->precio);
				temp=temp->siguiente;
			}else temp = temp->siguiente;
		}while(temp!=NULL);
		break;
	case 3:
		do{
			if(temp->tamano==tamano){
				printf("Nombre: ");
				puts(temp->nombre);
				printf("Extension: ");
				puts(temp->extension);
				printf("Codigo: %d\n", temp->codigo);
				printf("Tamano: %d\n", temp->tamano);
				printf("Precio: %d\n\n", temp->precio);
				temp=temp->siguiente;
			}else temp = temp->siguiente;
		}while(temp!=NULL);
		break;
	}
	break;
case 5: 
	printf("Ingrese un precio:\n");
	scanf("%d", &precio);
	fflush(stdin);
	do{
		if(temp->precio==precio){
			printf("Nombre: ");
			puts(temp->nombre);
			printf("Extension: ");
			puts(temp->extension);
			printf("Codigo: %d\n", temp->codigo);
			printf("Tamano: %d\n", temp->tamano);
			printf("Precio: %d\n\n", temp->precio);
			temp=temp->siguiente;
		}else temp = temp->siguiente;
	}while(temp!=NULL);
	break;
}
}

void mostrarlista(struct nodo* cabeza){ //funcion para imprimir la lista
	struct nodo* temp = cabeza;
	while(temp!=NULL){
		printf("Nombre: ");
		puts(temp->nombre);
		printf("Extension: ");
		puts(temp->extension);						//recorre la lista imprimiendo los valores de los nodos
		printf("Codigo: %d\n", temp->codigo);
		printf("Tamano: %d\n", temp->tamano);
		printf("Precio: %d\n\n", temp->precio);
		temp=temp->siguiente;
	}
}	
	
	void ordenarlista(struct nodo *cabeza) { 
		if (cabeza == NULL or (cabeza)->siguiente == NULL) {
			return;
		}
		
		struct nodo* listaordenada = NULL;
		struct nodo* actual = cabeza;
		
		while (actual != NULL) {
			struct nodo* siguiente = actual->siguiente;
			struct nodo* temp = listaordenada;
			struct nodo* anterior = NULL;
			
			while (temp != NULL and strcmp(actual->nombre, temp->nombre) > 0) {
				anterior = temp;
				temp = temp->siguiente;
			}
			
			if (anterior == NULL) {
				actual->siguiente = listaordenada;
				listaordenada = actual;
			} else {
				anterior->siguiente = actual;
				actual->siguiente = temp;
			}
			
			actual = siguiente;
		}
		
		cabeza = listaordenada;
		
		struct nodo* temp = cabeza;
		while(temp!=NULL){
			printf("Nombre: ");
			puts(temp->nombre);
			printf("Extension: ");
			puts(temp->extension);
			printf("Codigo: %d\n", temp->codigo);
			printf("Tamano: %d\n", temp->tamano);
			printf("Precio: %d\n\n", temp->precio);
			temp=temp->siguiente;
		}
	}

	
	int main(){
		FILE *file;
		struct nodo* cabeza=NULL;
		char nombre[30], extension[5], archivo[30];
		int codigo, tamano, precio, e=0;
		while(e!=8){
				  cout<<"OPCIONES\n\n";
				  cout<<"\n1) Añadir una imagen como nodo";
				  cout<<"\n2) Eliminar un nodo";
				  cout<<"\n3) Guardar lista en un archivo";
				  cout<<"\n4) Leer archivo";
				  cout<<"\n5) Buscar en la lista";
				  cout<<"\n6) Mostrar lista";
				  cout<<"\n7) Mostrar lista ordenada";
				  cout<<"\n8) Salir\n";
				  cout<<"\n\nQue accion desea realizar?: ";
			
			//scanf("%d",&e);
			cin>>e;
			fflush(stdin);
			switch(e){
			case 1:
				printf("Ingrese un nombre, extension, codigo, tamano y precio\n");
				fgets(nombre, 30, stdin);
				limpiar(nombre);
				fgets(extension, 5, stdin);
				limpiar(extension);
				scanf("%d",&codigo);    
				fflush(stdin);			
				scanf("%d",&tamano);  	
				fflush(stdin);			
				scanf("%d",&precio);	
				fflush(stdin);
				
				cabeza = nodonuevo(cabeza, nombre, extension, codigo, tamano, precio);
				break;
			case 2:
				printf("Ingrese el codigo de la imagen\n");
				scanf("%d", &codigo);
				fflush(stdin);
				if(eliminarnodo(cabeza, codigo)==1){  // tomo un codigo, y lo envio a la funcion eliminarnodo
					printf("Imagen eliminada\n");
				}else printf("No se encontro una imagen con ese codigo\n");
				break;
			case 3:
				printf("Ingrese un nombre para el archivo\n");
				fgets(archivo, 30, stdin);
				limpiar(archivo);
				printf("%s", archivo);
				file=fopen(archivo, "w");  //pide un nombre para crear un archivo, verifica que se haya creado correctamente
				if(file == NULL){
					printf("No se pudo crear el archivo.\n");
					return 1;
				}
				archivar(cabeza, file);
				fclose(file);
				break;
			case 4:
				printf("Ingrese el nombre del archivo\n");
				do{
					fgets(archivo, 30, stdin);
					limpiar(archivo);
					file = fopen(archivo, "rb"); //pide el nombre del archivo a leer
					if(file==NULL){
						printf("El archivo no existe, ingrese un nombre nuevo\n");
					}
				} while(file==NULL);
				leerarchivo(file);
				fclose(file);
				break;
			case 5:
				buscar(cabeza);
				break;
			case 6:
				mostrarlista(cabeza); 
				break;
			case 7:
				ordenarlista(cabeza);		
				break;
			case 8:
				return 0;  
				break;
			}
		}
	}
