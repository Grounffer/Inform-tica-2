/*
Segundo Parcial

Programa para adquirir, resguardar, presentar y buscar datos, relativos de:

Tema 1 ·         Puntos en el plano.

Tema 2 ·         Variables climáticas.

Tema 3 ·         Variables eléctricas.

Funciones del programa:

·         Solicitar datos permanentemente, hasta que el usuario lo desee.  (Aprobado Básico)

·         Contener algunos o todos los datos, en alguna etapa del programa en una lista enlazada.  (Aprobado Básico)

·         Utilización de estructuras adecuadamente. (Aprobado Básico)

-----------------

·         Utilización de funciones. (+1)

·         Resguardar datos en un archivo.  (+1)

·         Permitir obtener los datos, posteriormente desde un archivo. (+1)

·         Permitir realizar búsquedas de datos al usuario, según algún criterio elegido. (+2)
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// Crear un ELECTRICO node
struct ELECTRICO {
	int v;
	int a;
	// puedo agregar mas elementos a la estructura
	struct ELECTRICO* next;
};

void agregarAlFinal(struct ELECTRICO** head_ref, int new_v,int new_a) {
	
	struct ELECTRICO* new_node = (struct ELECTRICO*)malloc(sizeof(struct ELECTRICO));
	struct ELECTRICO* last = *head_ref; /* used in step 5*/
	
	cout<<"\nQue valor de voltaje se midio?: ";
	cin>>new_v;
	cout<<"Que valor de amperaje se midio?: ";
	cin>>new_a;
	
	new_node->v = new_v;
	new_node->a = new_a;
	new_node->next = NULL;
	
	if (*head_ref == NULL) {
		*head_ref = new_node;
		return;
	}
	
	while (last->next != NULL) last = last->next;
	
	last->next = new_node;
	return;
}



void printList(struct ELECTRICO* node) {
	
	int i=0;
	
	if(node==NULL) cout<<"\nError, no hay datos guardados";
	
	while (node != NULL) {
		cout<<"\n\nMedicion "<<i+1;
		printf("\nVoltaje: %d ", node->v);
		printf("\nAmperaje %d ", node->a);
		node = node->next;
		i++;
	}
}
void searchNode(struct ELECTRICO** head_ref) {
	
	int buscov,buscoa,i=0;
	
	cout<<"\nQue voltaje desea buscar?: ";
	cin>>buscov;
	cout<<"\nQue amperaje desea buscar?: ";
	cin>>buscoa;
	
	struct ELECTRICO* actual = *head_ref;
	
		while (actual != NULL) {
			if (actual->v == buscov or actual->a == buscoa ) {
				cout<<"\n\nMedicion "<<i+1;
				printf("\nVoltaje: %d ", actual->v);
				printf("\nAmperaje %d ", actual->a);
				i++;
			}
			actual = actual->next;
		}
	}

void guardar(struct ELECTRICO** head_ref) {
	FILE *fp;
	int i=0;
	struct ELECTRICO* actual = *head_ref;
	
	fp = fopen("Archivo.bin", "wb+");
	
	if (fp==NULL) {////pregunto si el archivo se abrio correctamente, si no, da mensaje de error
		cout<<"Error al abrir el archivo";
	}else {
		while (actual != NULL) { 
			fwrite (&actual, sizeof(ELECTRICO), 1, fp);
			i++;
			actual = actual->next;
		}
	}
	fclose(fp);
		
}

void leerfp(struct ELECTRICO** head_ref) {
	FILE *fp;
	int i=0;
	struct ELECTRICO* actual = *head_ref;
	
	fp = fopen("Archivo.bin", "rb");
	
	if (fp==NULL) {
		cout<<"Error al abrir el archivo";
	}else {
		while (actual != NULL) {
			fread (&actual, sizeof(ELECTRICO), 1, fp);
			cout<<"\n\nMedicion "<<i+1;
			printf("\nVoltaje: %d ", actual->v);
			printf("\nAmperaje %d ", actual->a);
			i++;
			actual = actual->next;
		}
	}
	fclose(fp);
}

int main() {
	
	int n=0;
	struct ELECTRICO* INICIO = NULL;
	
	//ELECTRICO info;

	do{
		
		cout<<"\n1)cargar datos";
		cout<<"\n2)presentar datos";
		cout<<"\n3)buscar";
		cout<<"\n4)Resguardar datos en un archivo";
		cout<<"\n5)Leer datos del archivo";
		cout<<"\n6)Salir";
		
		cout<<"\nQue accion desea realizar?: ";
		cin>>n;
		
		switch(n){
			
		case 1: 
			agregarAlFinal(&INICIO, 1,3);
			break;		
			
		case 2:
			printList(INICIO);
			cout<<endl;
			break;
			
		case 3:
			searchNode(&INICIO);
			cout<<endl;
			break;
			
		case 4: 
			
			guardar(&INICIO);
			cout<<"\nDatos Resguardados\n ";
			break;
		
		case 5: 
				cout<<"\nLeyendo datos\n ";
				leerfp(&INICIO);
				
				/*if ((fp = fopen("Archivo.bin", "rb")) != NULL){
					printf("\n\nApertura exitosa");	
					
					fread (&info, sizeof(ELECTRICO), 1, fp);			
					printf("\nSe ha terminado de leer Archivo.bin con fread usando estructuras...");	
					
				} else  printf("Problemas al abrir");
				fclose(fp);	
				printf ("\n\nAsignatura leída de Archivo.bin: ");
				printf ("\nv:%d\nv: %d\n",info.v, info.a);*/
				cout<<endl;
		break;
		}
	} while(n!=6);
		
return 0;
}
	
