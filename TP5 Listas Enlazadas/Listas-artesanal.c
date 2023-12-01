#include <stdio.h>
struct nodo { /*Definimos nuestra estructura nodo (Puede tener cualquier nombre)*/
	int CoordX;
	int CoordY;
	struct nodo *next;/*importante que uno de los miembros sea un puntero al mismo tipo de estructura (para poder apuntar a la siguiente)*/
};

int main() {/*METODO NO RECOMENDADO LO PRESENTAMOS PARA ENTENDER LISTAS DESDE EL ABSURDO !!*/
	struct nodo A,B,C,D,E,F, *temp;   /*                      :)                           */ 
	/*Carga de la información de cada nodo*/
	A.CoordX = 1; 
	A.CoordY = 2; 	
	B.CoordX = 3; 
	B.CoordY = 4;
	C.CoordX = 5; 
	C.CoordY = 6; 	
	D.CoordX = 7; 
	D.CoordY = 8;
	E.CoordX = 9; 
	E.CoordY = 10; 	
	F.CoordX = 11; 
	F.CoordY = 12;
	
	/*Enlazando los nodos*/
	A.next = &B; /*A se enlaza con B*/    /* no utilizar este metodo en el parcial puede ser contraproducente */
	B.next = &C; /*B se enlaza con C*/    /*                      :)                                          */ 
	C.next = &D; /*C se enlaza con D*/
	D.next = &E; /*D se enlaza con E*/
	E.next = &F; /*E se enlaza con F*/
	F.next = NULL; /*F como es el nodo final, apunta a NULL*/	
	
	/*Uso del operador -> (membrecía indirecta)*/
	temp = &A;  printf("temp apuntando a A:\n\tX:%d Y:%d\n\n", temp->CoordX, temp->CoordY);
	temp = &B;  printf("temp apuntando a B:\n\tX:%d Y:%d\n\n", temp->CoordX, temp->CoordY);
	
	/*Uso del operador . ( (*nombre).miembro ) */
	temp = &C;  printf("temp apuntando a C:\n\tX:%d Y:%d\n\n", (*temp).CoordX, (*temp).CoordY);
	temp = &D;  printf("temp apuntando a D:\n\tX:%d Y:%d\n\n", (*temp).CoordX, (*temp).CoordY);
	return 0;
}

