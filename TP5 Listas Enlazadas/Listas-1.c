#include <stdio.h>
#include <stdlib.h>/*Para uso de malloc*/
struct nodo { /*Definimos nuestra estructura nodo (Puede tener cualquier nombre)*/
	int CoordX;
	int CoordY;
	struct nodo *next;/*importante que uno de los miembros sea un puntero al mismo tipo de estructura (para poder apuntar a la siguiente)*/
}INICIO1, FIN2;
/*INICIO1 va a ser nuestro nodo inicial ya que le insertaremos a la derecha
FIN2 va a ser el nodo final de la segunda lista ya que le insertaremos a la izquierda*/
	
struct nodo *insertarAntesDe (struct nodo *actual);
struct nodo *insertarDespuesDe (struct nodo *actual);
void grabarPunto (struct nodo *actual, int x, int y);

int main() {
	int i;
	struct nodo  *conAntesDe, *conDespuesDe, *temp;
	conDespuesDe = &INICIO1; conDespuesDe->next = NULL;	
	conAntesDe = &FIN2; conAntesDe->next = NULL; 	
	
	/*Crea e inserta 10 nodos*/
	for (i=0; i<10; i++) {	
		/*Se van insertando nodos a la derecha de la primer lista*/
		conDespuesDe=insertarDespuesDe (conDespuesDe);
		/*Se van insertando nodos a la izquierda de la segunda lista*/
		conAntesDe=insertarAntesDe(conAntesDe);
		
		/*Se le asigna un valor a los miembros del nuevo nodo*/
		grabarPunto (conDespuesDe, i, i);
		grabarPunto (conAntesDe, i, i);		
		
	}
	
	printf("Lista creada con después de:\n");
	temp=&INICIO1;
	while(temp!=NULL){
		printf("DD:\tX:%d Y:%d\n\n", temp->CoordX, temp->CoordY);
		temp=temp->next; /*notar como recorremos la lista aqui*/
	}
	printf("\nLista creada con antes de:\n");
	temp=conAntesDe;
	while(temp!=NULL){
		printf("AD:\tX:%d Y:%d\n\n", temp->CoordX, temp->CoordY);
		temp=temp->next; /*notar como recorremos la lista aqui*/
	}
}

struct nodo *insertarAntesDe (struct nodo *actual) { 
	struct nodo *nuevo = (struct nodo *) malloc (sizeof (struct nodo));
	nuevo->next=actual;/*El nodo actual va a ser el siguiente del nuevo*/	
	return nuevo;/*Retorno de la nueva primera posición*/
}
struct nodo *insertarDespuesDe (struct nodo *actual) { 
	struct nodo *nuevo = (struct nodo *) malloc (sizeof (struct nodo));
	actual->next=nuevo;/*Definimos el siguiente como nuestro nuevo nodo*/
	nuevo->next=NULL;
	return nuevo;/*Retorno de la nueva última posición*/
}

void grabarPunto (struct nodo *actual, int x, int y){ 
	/*Esta función hace lo mismo que haría acceder a los miembros directamente,
	pero debemos pensar que por ejemplo, podría leer datos de algún otro lado como
	un puerto serie en lugar de cargarlos por parámetro
	*/
	actual ->CoordX = x;
	actual ->CoordY = y;
}
