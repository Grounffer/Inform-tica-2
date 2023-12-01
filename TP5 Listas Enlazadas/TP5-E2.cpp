/*
EJERCICIO 2
Basándose en su código fuente de su ejercicio 5 del TP4 de archivos, va a trabajar con
listas enlazadas para datos de mediciones.
Puede tener pre-cargada algunos nodos a su lista. La lista debe ser doblemente enlazada.
Debe crear funciones que permitan al usuario:
? añadir un nodo a la lista,
? eliminarlo de la lista,
? guardar la lista completa en un archivo (modo append y binario),
? recuperar/leer esa lista del archivo (al momento de iniciar el programa y cuando el
usuario lo solicite),
? realizar búsquedas de mediciones:
? Por el tipo de sensor
? Por el valor medido. En el caso del valor medido, especificar si se busca
mediciones cuyo valor supere un umbral X (ingresado por teclado) o
mediciones menores a X umbral o mediciones de exactamente el mismo
valor.
? Mostrar el contenido de la lista para visualizar todos sus elementos
? Mostrar la lista ordenada cronológicamente según la fecha de la medición
(dd/mm/aaaa).
Comente su código fuente para aclarar la funcionalidad de su programa.
	Recuerde que puede visualizar los archivos binarios usando diversas herramientas, ver
	apunte unidad Archivos, pdf “¿Cómo visualizamos los archivos binarios?”
	
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct fecha{
	int dia;
	int mes;
	int anio;
	struct fecha* sig;
	struct fecha* ant;
};

struct nodo{
	int valor;
	int hora;
	char comentarios[1000];
	struct fecha* fecha;	
	struct sensor* sensor;
	struct nodo* sig;
	struct nodo* ant;
};

struct sensor{
	char marca[50];
	char tipo[50];
	char unidad[50];
	struct sensor* sig;
	struct sensor* ant;
};
void limpiar(char string[]){ 
	string[strlen(string)-1]='\0';
}
	
	//funcion para crear un nodo nuevo
struct nodo* nuevonodo(struct nodo* cabeza, int valor, int hora, char comentarios[], struct fecha* cabezafecha, struct sensor* cabezasensor){ 
	//creo el nodo nuevo y copio los parametros 
struct nodo* nuevonodo = (struct nodo*)malloc(sizeof(struct nodo)); 
	
	nuevonodo->valor=valor;
	nuevonodo->hora=hora;
	
	//asigna memoria al nodo y copia los valores
	strcpy(nuevonodo->comentarios, comentarios);								
	nuevonodo->sig=NULL;
	
	nuevonodo->fecha = (struct fecha*)malloc(sizeof(struct fecha));
	
	struct fecha* temp=cabezafecha;
	while(temp->sig!=NULL){
		temp=temp->sig;
	}
	nuevonodo->fecha->dia=temp->dia;
	nuevonodo->fecha->mes=temp->mes;
	nuevonodo->fecha->anio=temp->anio;
	
	nuevonodo->sensor = (struct sensor*)malloc(sizeof(struct sensor));
	
	struct sensor* temp2=cabezasensor;
	while(temp2->sig!=NULL){
		temp2=temp2->sig;
	}
	strcpy(nuevonodo->sensor->marca, temp2->marca);
	strcpy(nuevonodo->sensor->tipo, temp2->tipo);
	strcpy(nuevonodo->sensor->unidad, temp2->unidad);
	
	if(cabeza==NULL){
		cabeza=nuevonodo;			
	}
	else{
		struct nodo* temp3 = cabeza;
		//ubica el nodo nuevo
		while(temp3->sig!=NULL){
			temp3=temp3->sig;						
		}
		temp3->sig=nuevonodo;
		nuevonodo->ant=temp3;
	}
	return cabeza;
}
		

//crea un nuevo nodo en la lista de fechas, para usar en el nodo
struct fecha* nuevafecha(struct fecha* cabeza, int dia, int mes, int anio){
	struct fecha* fechanueva = (struct fecha*)malloc(sizeof(struct fecha));
	fechanueva->dia=dia;
	fechanueva->mes=mes;						
	fechanueva->anio=anio;							
	fechanueva->sig=NULL;
	if(cabeza==NULL){
		fechanueva->ant=NULL;
		cabeza=fechanueva;		
	}
	else{
		struct fecha* temp = cabeza;
		while(temp->sig!=NULL){
			temp=temp->sig;
		}
		temp->sig=fechanueva;
		fechanueva->ant=temp;
	}
	return cabeza;
}
	
	//crea un nuevo nodo en la lista de sensores, para usar en el nodo
struct sensor* nuevosensor(struct sensor* cabeza, char marca[], char tipo[], char unidad[]){
	struct sensor* sensornuevo= (struct sensor*)malloc(sizeof(struct sensor)); 
	strcpy(sensornuevo->marca, marca);
	strcpy(sensornuevo->tipo, tipo);
	strcpy(sensornuevo->unidad, unidad);
	sensornuevo->sig=NULL;
	if(cabeza==NULL){
		sensornuevo->ant=NULL;						
		cabeza=sensornuevo;			
	}
	else{
		struct sensor* temp = cabeza;
		while(temp->sig=NULL){
			temp=temp->sig;
		}
		temp->sig=sensornuevo;
		sensornuevo->ant=temp;
	}
	return cabeza;
}
	//funcion para eliminar un nodo
	struct nodo* eliminarnodo(struct nodo* cabeza, int valor, int hora){ 
		if(cabeza==NULL){  //devuelve 0 si no hay nodos
			return 0;
		}
		else{
			struct nodo* temp=cabeza;
			do{	
				if(temp->hora==hora and temp->valor==valor){ //recorre la lista hasta encontrar un nodo con el codigo ingresado
					if(temp==cabeza){
						if(temp->sig!=NULL){
							temp->sig->ant=NULL;
							cabeza=temp->sig;
						}
						else{
							//elimina el nodo si es la cabeza
							cabeza=NULL;
						}
						free(temp);							
						return cabeza;
					}
					//elimina el nodo si es el ultimo 	
					else if(temp->sig==NULL){								
						temp->ant->sig=NULL;
						free(temp);
						return cabeza; 
					}
					//elimina el nodo si esta en el medio
					else{
						temp->ant->sig=temp->sig;			
						temp->sig->ant=temp->ant;
						free(temp);
						return cabeza;
					}
				}
				temp=temp->sig;
			} while(temp!=NULL);
		}
		return 0; 
	}

//funcion para guardar un nodo en un archivo
int archivar(struct nodo* cabeza, FILE* file){ 	if(cabeza==NULL){
		return 0;
	}
	else{
		struct nodo* temp = cabeza;
		while(temp!=NULL){			//recorre la lista, escribiendo nodo por nodo en el archivo hasta el fin de la lista
			fwrite(&temp, sizeof(struct nodo), 1, file);
			temp = temp->sig;
		}
	}
	return 1;
}
	
	struct nodo* leerarchivo(struct nodo* cabeza, FILE* file) {
		while (!feof(file)) {
			struct nodo* buffer = (struct nodo*)malloc(sizeof(struct nodo));
			buffer->fecha = (struct fecha*)malloc(sizeof(struct fecha));
			buffer->sensor = (struct sensor*)malloc(sizeof(struct sensor));
			//copia los valores del archivo en un nodo buffer, luego los pasa a la lista y repite hasta que no hayan mas nodos que copiar
			fread(buffer, sizeof(struct nodo), 1, file); 			
			
			buffer->sig = NULL; 
			buffer->ant = NULL;
			
			struct nodo* nuevonodo = buffer;
			
			if (cabeza == NULL) {
				cabeza = nuevonodo;
			} else if (cabeza->sig == NULL) {
				cabeza->sig = nuevonodo;
				nuevonodo->ant = cabeza;
			} else {
				struct nodo* temp3 = cabeza;
				while (temp3->sig != NULL) {
					temp3 = temp3->sig;
				}
				temp3->sig = nuevonodo;
				nuevonodo->ant = temp3;
			}
		}
		return cabeza;
	}
	
	void buscar(struct nodo* cabeza){ //funcion para buscar un nodo
		char tipo[30];
		int f, g, valor;
		printf("\n1. Buscar por tipo de sensor\n2. Buscar por valor\n");
		scanf("%d", &f);
		fflush(stdin);
		struct nodo* temp = cabeza;
		switch(f){
		case 1: 
			printf("Ingrese un tipo de sensor:\n");
			fgets(tipo, 30, stdin);
			limpiar(tipo);
			do{
				if(strcmp(temp->sensor->tipo, tipo)==0){
					printf("\nValor: %d", temp->valor);
					printf("\nHora: %d", temp->hora);
					printf("\nComentarios: %s", temp->comentarios);
					printf("\nFecha: %d/%d/%d", temp->fecha->dia, temp->fecha->mes, temp->fecha->anio);
					printf("\nSensor: Sensor de %s %s (%s)", temp->sensor->tipo, temp->sensor->marca, temp->sensor->unidad);
					temp=temp->sig;
				}else temp = temp->sig;
			}while(temp!=NULL);
			break;
		case 2:
			printf("1. Buscar mediciones con valores menores al ingresado\n2. Buscar mediciones con valores mayores al ingresado\n3. Buscar mediciones con valores iguales al ingresado\n");
			scanf("%d", &g);
			fflush(stdin);
			printf("Ingrese el tamaño");
			scanf("%d", &valor);
			fflush(stdin);
			switch(g){
			case 1:
				do{
					if(temp->valor<valor){
						printf("\nValor: %d", temp->valor);
						printf("\nHora: %d", temp->hora);
						printf("\nComentarios: %s", temp->comentarios);
						printf("\nFecha: %d/%d/%d", temp->fecha->dia, temp->fecha->mes, temp->fecha->anio);
						printf("\nSensor: Sensor de %s %s (%s)", temp->sensor->tipo, temp->sensor->marca, temp->sensor->unidad);
						temp=temp->sig;
					}else temp = temp->sig;
				}while(temp!=NULL);
				break;
			case 2:
				do{
					if(temp->valor>valor){
						printf("\nValor: %d", temp->valor);
						printf("\nHora: %d", temp->hora);
						printf("\nComentarios: %s", temp->comentarios);
						printf("\nFecha: %d/%d/%d", temp->fecha->dia, temp->fecha->mes, temp->fecha->anio);
						printf("\nSensor: Sensor de %s %s (%s)", temp->sensor->tipo, temp->sensor->marca, temp->sensor->unidad);
						temp=temp->sig;
					}else temp = temp->sig;
				}while(temp!=NULL);
				break;
			case 3:
				do{
					if(temp->valor==valor){
						printf("\nValor: %d", temp->valor);
						printf("\nHora: %d", temp->hora);
						printf("\nComentarios: %s", temp->comentarios);
						printf("\nFecha: %d/%d/%d", temp->fecha->dia, temp->fecha->mes, temp->fecha->anio);
						printf("\nSensor: Sensor de %s %s (%s)", temp->sensor->tipo, temp->sensor->marca, temp->sensor->unidad);
						temp=temp->sig;
					}else temp = temp->sig;
				}while(temp!=NULL);
				break;
			}
			break;
		}
	}	
							
void mostrarlista(struct nodo* cabeza){ //funcion para imprimir la lista
	struct nodo* temp = cabeza;
	while(temp!=NULL){
		printf("\nValor: %d", temp->valor);
		printf("\nHora: %d", temp->hora);
		printf("\nComentarios: %s", temp->comentarios);
		printf("\nFecha: %d/%d/%d", temp->fecha->dia, temp->fecha->mes, temp->fecha->anio);
		printf("\nSensor: Sensor de %s %s (%s)\n", temp->sensor->tipo, temp->sensor->marca, temp->sensor->unidad);
		temp=temp->sig;
	}
}	
								
void ordenarlista(struct nodo *cabeza) { //funcion para ordenar e imprimir la lista
	if (cabeza==NULL or cabeza->sig == NULL) {
		return;
	}
	
	struct nodo* listaordenada = NULL;
	struct nodo* actual = cabeza;
	
	while (actual != NULL) {
		struct nodo* sig = actual->sig;
		struct nodo* temp = listaordenada;
		struct nodo* anterior = NULL;
		
		while (temp != NULL and (actual->fecha->dia>temp->fecha->dia and actual->fecha->mes>temp->fecha->mes and actual->fecha->anio>temp->fecha->anio)) {
			anterior = temp;
			temp = temp->sig;
		}
		
		if (anterior == NULL) {
			actual->sig = listaordenada;
			listaordenada = actual;
		} else {
			anterior->sig = actual;
			actual->sig = temp;
		}
		
		actual = sig;
	}
	
	cabeza = listaordenada;
	
	struct nodo* temp = cabeza;
	while(temp!=NULL){
		printf("\nValor: %d", temp->valor);
		printf("\nHora: %d", temp->hora);
		printf("\nComentarios: %s", temp->comentarios);
		printf("\nFecha: %d/%d/%d", temp->fecha->dia, temp->fecha->mes, temp->fecha->anio);
		printf("\nSensor: Sensor de %s %s (%s)\n", temp->sensor->tipo, temp->sensor->marca, temp->sensor->unidad);
		temp=temp->sig;
	}
}

int main(){
	FILE *file;
	struct nodo* cabeza=NULL;
	struct fecha* cabezafecha=NULL;
	struct sensor* cabezasensor=NULL;
	char comentarios[500], tipo[30], marca[30], unidad[10], archivo[30];
	int valor, hora, dia, mes, anio, e;
	
	
	while(e!=8){
			cout<<"OPCIONES\n\n";
			cout<<"\n1. Añadir una medicion como nodo";
			cout<<"\n2. Eliminar una medicion";
			cout<<"\n3. Guardar lista en un archivo";
			cout<<"\n4. Importar archivo";
			cout<<"\n5. Buscar en la lista";
			cout<<"\n6. Mostrar lista";
			cout<<"\n7. Mostrar lista ordenada";
			cout<<"\n8. Salir\n";
			cout<<"\n\nQue accion desea realizar?: ";  
		cin>>e;
		fflush(stdin);
		switch(e){
		case 1:
			printf("Ingrese un valor, hora, dia, mes, anio, los datos del sensor(marca, tipo y unidad), y comentarios, en ese orden:\n"); //pide los datos y los pasa a sus funciones
			scanf("%d", &valor);
			fflush(stdin);
			scanf("%d", &hora);
			fflush(stdin);
			scanf("%d", &dia);
			fflush(stdin);
			scanf("%d", &mes);
			fflush(stdin);
			scanf("%d", &anio);
			fflush(stdin);
			fgets(marca, 30, stdin);
			limpiar(marca);
			fgets(tipo, 30, stdin);
			limpiar(tipo);
			fgets(unidad, 10, stdin);
			limpiar(unidad);
			fgets(comentarios, 500, stdin);
			limpiar(comentarios);
			cabezafecha=nuevafecha(cabezafecha, dia, mes, anio);
			cabezasensor=nuevosensor(cabezasensor, marca, tipo, unidad);
			cabeza = nuevonodo(cabeza, valor, hora, comentarios, cabezafecha, cabezasensor);
			break;
		case 2:
			printf("Ingrese el valor y hora de la medicion\n");		//toma valor y hora para enviarlos a la funcion
			scanf("%d", &valor);
			fflush(stdin);
			scanf("%d", &hora);
			fflush(stdin);
			cabeza=eliminarnodo(cabeza, valor, hora);
			break;
		case 3:
			printf("Ingrese un nombre para el archivo\n");
			fgets(archivo, 30, stdin);
			limpiar(archivo);
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
			leerarchivo(cabeza, file);
			fclose(file);
			break;
		case 5:
			buscar(cabeza);
			break;
		case 6:
			mostrarlista(cabeza);   //case 5 6 7 llaman a la funcion directamente
			break;
		case 7:
			ordenarlista(cabeza);		
			break;
		case 8:
			return 0;   //salir
			break;
}}}
