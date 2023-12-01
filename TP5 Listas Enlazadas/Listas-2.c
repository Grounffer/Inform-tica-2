#include <stdio.h>
#include <stdlib.h>/*Para uso de malloc*/
struct nodo { /*Definimos nuestra estructura nodo (Puede tener cualquier nombre)*/
	int CoordX;
	int CoordY;
	struct nodo *next;/*importante que uno de los miembros sea un puntero al mismo tipo de estructura (para poder apuntar a la siguiente)*/
}INICIO1, FIN2;
/*INICIO1 va a ser nuestro nodo inicial ya que le insertaremos a la derecha
FIN2 va a ser el nodo final de la segunda lista ya que le insertaremos a la izquierda*/
	
struct nodo *nuevoNodo ();
struct nodo *nuevoNodoParam (int x, int y);
struct nodo *insertarAntesDe (struct nodo *actual, struct nodo *nuevo);
struct nodo *insertarDespuesDe (struct nodo *actual, struct nodo *nuevo);
void grabarPunto (struct nodo *actual, int x, int y);

int main() {
	int i;
	struct nodo  *conAntesDe, *conDespuesDe, *temp;
	conDespuesDe = &INICIO1; conDespuesDe->next = NULL;	
	conAntesDe = &FIN2; conAntesDe->next = NULL; 
	
	
	/*Crea e inserta 10 nodos*/
	for (i=0; i<10; i++) {	
		/*Se van insertando nodos a la derecha*/
		conDespuesDe=insertarDespuesDe (conDespuesDe, nuevoNodo());
		/*Se le asigna un valor a los miembros del nuevo nodo*/
		grabarPunto (conDespuesDe, i, i);
		
		conAntesDe=insertarAntesDe(conAntesDe, nuevoNodoParam(i,i));
	}
	
	printf("Lista creada con después de:\n");
	temp=&INICIO1;
	while(temp!=NULL){
		printf("DD:\tX:%d Y:%d\n\n", temp->CoordX, temp->CoordY);
		temp=temp->next;
	}
	printf("\nLista creada con antes de:\n");
	temp=conAntesDe;
	while(temp!=NULL){
		printf("AD:\tX:%d Y:%d\n\n", temp->CoordX, temp->CoordY);
		temp=temp->next;
	}
}
/*Función que crea un nuevo nodo*/	
/*Con el uso de esta función podemos crear un nodo vacio o datos, por ejemplo:
Un nodo al que aún no se le insertaron los valores de sus coordenadas,
tenga un valor (0,0), o incluso se pueden agregar parámetros 
para que al momento de crear el nodo ya se inicialice con los datos correspondientes
Se crearán en este caso ambos ejemplos
*/
/*Ejemplo que inicializa en un valor por defecto SIN perdir por parámetro*/
struct nodo *nuevoNodo () { /* */
	struct nodo *nuevo = (struct nodo *) malloc (sizeof (struct nodo));
	/*Se inicializa en (0,0)*/
	nuevo->CoordX=0;
	nuevo->CoordY=0;
	nuevo->next=NULL;/*Como es un nodo "suelto" no tiene siguiente*/
	return nuevo;
}
/*Ejemplo que crea el nodo y pide sus datos por parámetro*/
struct nodo *nuevoNodoParam (int x, int y) { 
	struct nodo *nuevo = (struct nodo *) malloc (sizeof (struct nodo));
	/*Se inicializa en (x,y)*/
	nuevo->CoordX=x;
	nuevo->CoordY=y;
	nuevo->next=NULL;/*Como es un nodo "suelto" no tiene siguiente*/
	return nuevo;
}

struct nodo *insertarAntesDe (struct nodo *actual, struct nodo *nuevo) { 
	nuevo->next=actual;/*El nodo actual va a ser el siguiente del nuevo*/	
	return nuevo;/*Retorno de la nueva primera posición*/
}
struct nodo *insertarDespuesDe (struct nodo *actual, struct nodo *nuevo) { 
	actual->next=nuevo;/*Definimos el siguiente como nuestro nuevo nodo*/
	nuevo->next=NULL;/*El nuevo nodo al ser el último, apunta a NULL 
	(esta línea de código se puede obviar en este ejemplo, ya que al momento 
	de crear el nodo ya inicializamos el next en NULL)*/
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
