
/*
TP5-EJERCICIO 1
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
tamaño .
? Mostrar la lista para visualizar todos sus elementos.
? Mostrar la lista ordenada alfabéticamente según el nombre del archivo.
Comente su código fuente para aclarar la funcionalidad de su programa.
Recuerde que puede visualizar los archivos binarios usando diversas herramientas, ver
apunte unidad Archivos, pdf “¿Cómo visualizamos los archivos binarios?
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

// Crear un inventario node
struct inventario {
	int codigo=0;
	char nombre[50]={"0\n"};
	char extension[50]={"0\n"};
	int tamBytes=0;
	float precio=0;
	struct inventario *next;
};

//eliminar salto de linea de una cadena al usar fgets
void limpiar(char string[]){ string[strlen(string)-1]='\0'; }
void printNode(struct inventario *temp_node) { //funcion que recibe un nodo y lo imprime
	cout<<"\nCodigo: "<<temp_node->codigo;
	cout<<"\nNombre: "<<temp_node->nombre;
	cout<<"\nExtension: "<<temp_node->extension;
	cout<<"\nTamno en Bytes: "<<temp_node->tamBytes;
	cout<<"\nPrecio: "<<temp_node->precio;
}
	
void agregarAlFinal(struct inventario **cabeza,int *c) {
	
	//reservo memoria para un nuevo nodo, con el tamaño de una estructura
	struct inventario* new_node = (struct inventario*)malloc(sizeof(struct inventario)); 
	
	// creo un nodo temporal y lo ubico en la cabecera para empezar a recorrer
	struct inventario* temp_node = *cabeza; 
	
	int code;			//codigo		
	char n[50],e[50];	//nombre, extension
	int B;				//tamaño en Bytes
	float p;			//precio

	(*c)++; //aunmento el nro de nodos cargados
	//cout<<"\nc: "<<*c<<"\n";
	
	cout<<"\nINGRESANDO IMAGEN "<<*c;
	cout<<"\nIngrese el codigo: ";
	cin>>code;
	cout<<"Ingrese el nombre: ";
	fflush(stdin);
	fgets(n,50,stdin);
	limpiar(n);
	cout<<"Ingrese la extension: ";
	fflush(stdin);
	fgets(e,50,stdin);
	limpiar(e);
	cout<<"Ingrese el tamaño en bytes: ";
	cin>>B;
	cout<<"Ingrese el precio: ";
	cin>>p;
	
	//asigno los nuevos datos al new_node
	new_node->codigo = code;
	strcpy(new_node->nombre,n);
	strcpy(new_node->extension,e);
	new_node->tamBytes = B;
	new_node->precio = p;
	
	// en new_node el apartado next apunta a NULL, es decir queda como el ultimo nodo.
	new_node->next = NULL;
	
	// si en mi nodo de cabecera no hay nada, copio el contenido del new_node y salgo de la funcion
	if (*cabeza == NULL) {
		*cabeza = new_node;
		return;
	}
	
	//  El nodo temporal esta ubicado en la cabecera
	//	mientras el next no apunte a NULL, es decir mientras no llegue al ultimo nodo...
	//	recorro todos los nodos hasta llegar al ultimo, 
	while (temp_node->next != NULL) temp_node = temp_node->next;
	
	//AGREGO EL NUEVO NODO AL FINAL DEL ARREGLO DE NODOS
	temp_node->next = new_node;
	
	return;
}
int eliminarnodo(struct inventario **cabeza, int *c , int *m){ //funcion para eliminar un nodo
	
	int i=1;
	
	// creo un nodo temporal y lo ubico en la cabecera para empezar a recorrer
	struct inventario *temp_node = *cabeza; 
	
	// creo un nodo auxiliar y lo ubico en la cabecera para empezar a recorrer
	struct inventario *aux_node = *cabeza; 
	
	if(temp_node==NULL){ //si mi nodo de cabecera esta vacío, no hay datos guardados
		cout<<"\nError, no hay datos guardados"; 
		return 0;
	}
	
	while (temp_node != NULL) { //rrecorro los nodos hasta llegar al final
		//cout<<"\n\n---------- OBJETO "<<i<<" ----------";
		
		if( (i+1) == *m )	aux_node = temp_node; //si estoy en un nodo anterior al que quiero borrar, lo guardo en aux_nodo
		
		//si estoy en el nodo que quiero borrar, hago que el next de aux_node apunte al proximo de mi nodo actual borrando el nodo del medio
		if(	i == *m ){						
			aux_node-> next = temp_node->next; 
			free(temp_node);
			(*c)--; 			//disminuyo la cantidad de imagenes guardadas
			return 0;
		}
		
		temp_node = temp_node->next;
		i++;
	}
	return 0; 
}
void printList(struct inventario* temp_node) {
	
	int i=0;
	
	if(temp_node==NULL) cout<<"\nError, no hay datos guardados";
	
	while (temp_node != NULL) {
		cout<<"\n\n---------- OBJETO "<<i+1<<" ----------";
		
		cout<<"\nCodigo: "<<temp_node->codigo;
		cout<<"\nNombre: "<<temp_node->nombre;
		cout<<"\nExtension: "<<temp_node->extension;
		cout<<"\nTamno en Bytes: "<<temp_node->tamBytes;
		cout<<"\nPrecio: "<<temp_node->precio;
		
		temp_node = temp_node->next;
		i++;
	}
}
void searchNode(struct inventario **cabeza) {
	
	int i=1,m=0,x=0;
	
	int code;			//codigo		
	char n[50],e[50];	//nombre, extension
	int B;				//tamaño en Bytes
	float p;			//precio
	
	struct inventario* temp_node = *cabeza;
	
	if(temp_node==NULL){ cout<<"\nError, no hay datos guardados"; return;}
	
	do{
		cout<<"\nBUSQUEDA";
		cout<<"\n1)Codigo";
		cout<<"\n2)Nombre";
		cout<<"\n3)Extension";
		cout<<"\n4)Tamaño en Bytes";
		cout<<"\n5)precio";
		cout<<"\n6)Salir";
		
		cout<<"\nBuscar por:  ";
		cin>>m;
		
		i=1;
		temp_node = *cabeza; //reinicio el nodo para recorrer desde el principio
		
		switch(m){
			
		case 1: 
			cout<<"\nIngrese el codigo a buscar: ";
			cin>>code;
			
			while (temp_node != NULL) {
				if (temp_node->codigo == code) {
					cout<<"\n\n---------- OBJETO "<<i<<" ----------";
					printNode(temp_node);
				}
				temp_node = temp_node->next;
				i++;
			}
			cout<<"\n";
		break;
		
		case 2: 
			cout<<"\nIngrese el nombre a buscar: ";
			fflush(stdin);
			fgets(n,50,stdin);
			limpiar(n);
			
			while (temp_node != NULL) {
				if (strcmp(temp_node->nombre,n)==0) {
					cout<<"\n\n---------- OBJETO "<<i<<" ----------";
					printNode(temp_node);
				}
				temp_node = temp_node->next;
				i++;
			}
			cout<<"\n";
			break;
		case 3: 
			cout<<"\nIngrese la extension a buscar: ";
			fflush(stdin);
			fgets(e,50,stdin);
			limpiar(e);
			
			while (temp_node != NULL) {
				if (strcmp(temp_node->extension,e)==0) {
					cout<<"\n\n---------- OBJETO "<<i<<" ----------";
					printNode(temp_node);
				}
				temp_node = temp_node->next;
				i++;
			}
			cout<<"\n";
			break;
			
		case 4: 
			cout<<"\nIngrese el tamaño en Bytes a buscar: ";
			cin>>B;
			
			do{
			cout<<"\n1)Buscar valores MAYORES o iguales";
			cout<<"\n2)Buscar valores MENORES o iguales";
			cout<<"\nQue desea hacer?: ";
			cin>>x;
			
			switch(x){
				case 1:
					while (temp_node != NULL) {
						if (temp_node->tamBytes >= B) {
							cout<<"\n\n---------- OBJETO "<<i<<" ----------";
							printNode(temp_node);
						}
						temp_node = temp_node->next;
						i++;
					}
				break;
			case 2:
				while (temp_node != NULL) {
					if (temp_node->tamBytes <= B) {
						cout<<"\n\n---------- OBJETO "<<i<<" ----------";
						printNode(temp_node);
					}
					temp_node = temp_node->next;
					i++;
				}
				break;
			default: break;
			}
			}while(x!=1 and x!=2);
			
			cout<<"\n";
			
			break;
			
		case 5: 
			cout<<"\nIngrese el precio a buscar: ";
			cin>>p;
			
			while (temp_node != NULL) {
				if (temp_node->precio == p) {
					cout<<"\n\n---------- OBJETO "<<i<<" ----------";
					printNode(temp_node);
				}
				temp_node = temp_node->next;
				i++;
			}
			cout<<"\n";
			break;
		default:
		break;
		}
	}while(m!=6);
}


void guardar(struct inventario** head_ref) {
	FILE *fp;
	int i=0;
	struct inventario* actual = *head_ref;
	
	fp = fopen("Archivo.bin", "wb+");
	
	if (fp==NULL) {////pregunto si el archivo se abrio correctamente, si no, da mensaje de error
		cout<<"Error al abrir el archivo";
	}else {
		while (actual != NULL) { 
			fwrite (&actual, sizeof(inventario), 1, fp);
			i++;
			actual = actual->next;
		}
	}
	fclose(fp);
	
}
/*
void leerfp(struct inventario** head_ref) {
	FILE *fp;
	int i=0;
	struct inventario* actual = *head_ref;
	
	fp = fopen("Archivo.bin", "rb");
	
	if (fp==NULL) {
		cout<<"Error al abrir el archivo";
	}else {
		while (actual != NULL) {
			fread (&actual, sizeof(inventario), 1, fp);
			cout<<"\n\nMedicion "<<i+1;
			printf("\nVoltaje: %d ", actual->v);
			printf("\nAmperaje %d ", actual->a);
			i++;
			actual = actual->next;
		}
	}
	fclose(fp);
}

*/
int main() {
	FILE *fp;
	int n=0,m=0,band=0;
	int c=0; //	c es la cantidad de nodos cargados
	
	struct inventario* INICIO = NULL; //declaro el primer nodo como NULL
	
	do{
		cout<<"\n1)cargar datos";
		cout<<"\n2)presentar datos";
		cout<<"\n3)Eliminar datos";
		cout<<"\n4)buscar";
		cout<<"\n5)Resguardar datos en un archivo";
		cout<<"\n6)Leer datos del archivo";
		cout<<"\n7)Salir";
		
		cout<<"\nQue accion desea realizar?: ";
		cin>>n;
		
		switch(n){
			
		case 1: 
			agregarAlFinal(&INICIO,&c); //paso por referencia el nodo inicial y la cant de nodos cargados
			break;		
			
		case 2:
			printList(INICIO);
			cout<<endl;
			break;
		case 3:
			cout<<"\nQue nodo desea eliminar?: ";
			cin>>m;
			eliminarnodo(&INICIO,&c,&m);
			
			break;
		case 4:
			searchNode(&INICIO);
			cout<<endl;
			break;
			
		case 5: 
			
			fp = fopen("Datos TP5-e1.bin", "wb");
			
			if(fp==NULL){
				cout<<"\n\nERROR AL ABRIR ARCHIVO";
				exit (1);
			}else{
				
				if(INICIO==NULL){ cout<<"\nError, no hay datos guardados";}
				else{
					
					struct inventario* temp = INICIO; //creo un nodo temporal y lo ubico en la cabecera
					
					//fprintf( fp ,"%d ", c); //guardo en el archivo la variable c, es la cant de estructuras cargadas
					
				while(temp!=NULL){			//recorre la lista, escribiendo nodo por nodo en el archivo hasta el fin de la lista
					fwrite(temp, sizeof(struct inventario), 1, fp);
					temp = temp->next;
				}
			}
			fclose(fp);
			}
			cout<<"\nDatos guardados\n";
		break;
		
		case 6: 
			
			c=0;
			band=0;
			
			cout<<"\nLeyendo\n";
			
			fp = fopen("Datos TP5-e1.bin", "rb");
			
			if(fp==NULL){
				cout<<"\n\nERROR AL ABRIR ARCHIVO";
				exit (1);
			}else{
				cout<<"\nLeyendo archivo abierto\n";
				
				do{
					//reservo memoria para un nuevo nodo, con el tamaño de una estructura
					struct inventario* new_node = (struct inventario*)malloc(sizeof(struct inventario)); 
					
					// creo un nodo temporal y lo ubico en la cabecera para empezar a recorrer
					struct inventario* temp_node = INICIO; 
					
					c++; //aunmento el nro de nodos cargados
					//cout<<"\nc: "<<*c<<"\n";
					
					cout<<"\n----------NEW NODE-------------\n";
					fread(new_node, sizeof(struct inventario), 1, fp);
					printNode(new_node);
					cout<<"\n";
					
					// en new_node el apartado next apunta a NULL, es decir queda como el ultimo nodo.
					new_node->next = NULL;
					
					if(new_node->next == NULL){
						cout<<"\nULTIMO NODO GUARDADO\n";
						band=1;
					}
					
					// si en mi nodo de cabecera no hay nada, copio el contenido del new_node y salgo de la funcion
					if (INICIO == NULL) {
						INICIO = new_node;
						
						temp_node = INICIO; //ubico el nodo temporal en la cabecera
						break;
					}
					
					//  El nodo temporal esta ubicado en la cabecera
					//	mientras el next no apunte a NULL, es decir mientras no llegue al ultimo nodo...
					//	recorro todos los nodos hasta llegar al ultimo, 
					while (temp_node->next != NULL) temp_node = temp_node->next;
					
					//AGREGO EL NUEVO NODO AL FINAL DEL ARREGLO DE NODOS
					temp_node->next = new_node;
				
				}while(band!=1);
				
			}
			cout<<"\n\nc FINAL= "<<c<<"\n";
			fclose(fp);
			break;
		
			/*
		case 6: 
			
			c=0;
			band=0;
			
			cout<<"\nLeyendo\n";
			
			fp = fopen("Datos TP5-e1.bin", "rb");
			
			if(fp==NULL){
				cout<<"\n\nERROR AL ABRIR ARCHIVO";
				exit (1);
			}else{
				cout<<"\nLeyendo archivo abierto\n";
					
					struct inventario	*new_node = (struct inventario*)malloc(sizeof(struct inventario)); 
					
					struct inventario	*siguiente = (struct inventario*)malloc(sizeof(struct inventario)); 
					
					do{			//recorre la lista, escribiendo nodo por nodo en el archivo hasta el fin de la lista

						cout<<"\n----------NEW NODE-------------\n";
						
						fread(new_node, sizeof(struct inventario), 1, fp);
						printNode(new_node);
						cout<<"\n";
						
						cout<<"\n\nc= "<<c<<"\n";
						
						if(c==0){
							cout<<"\n1ER NODO GUARDADO\n";
							INICIO = new_node;
						}else{
							
							INICIO->next = new_node;
							INICIO = INICIO->next;
						}
						
						if(new_node->next == NULL){
							
							INICIO->next = NULL;
							
							cout<<"\nULTIMO NODO GUARDADO\n";
							band=1;
						}
						
						c++; //aumento nro de nodos guardados
						
						//cout<<"\n+++++INICIO+++++\n";	printNode(INICIO);
						
					}while(new_node->next != NULL and band!=1);				
			}
			cout<<"\n\nc FINAL= "<<c<<"\n";
			fclose(fp);
		break;
		*/
		default: break;
		}
	} while(n!=7);
	
	return 0;
}

