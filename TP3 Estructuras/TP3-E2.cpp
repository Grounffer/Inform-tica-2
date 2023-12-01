/*
Ejercicio 2 - Listado de imágenes
Debe utilizar arreglos de estructuras y agrupar su código en funciones creadas
por Ud.
Defina una estructura que permita luego almacenar un stock de imágenes a la
venta (arreglo de estructuras). Cada elemento debe almacenar lo siguiente:
? Código de inventario.
? Nombre del archivo.
? Extensión del archivo o tipo de imagen (ejemplos: tiff, jpg, png )
? Tamaño en bytes.
? Precio de la imagen.
El programa permitirá realizar, en cada momento, y cada vez que el usuario lo
desee, las siguientes operaciones, que debe implementar en funciones:
? Agregar una nueva imagen.
? Eliminar un elemento existente.
? Modificar los datos de algún elemento.
? Búsquedas por nombre de archivo, extensión, tamaño.
*/
#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

const int TMAX =5;

struct inventario {
	int codigo=0;
	char nombre[50]={"0\n"};
	char extension[50]={"0\n"};
	int tamBytes=0;
	float precio=0;
}Imagen[TMAX];


void agregar(struct inventario img[],int *c){
	if(*c<=TMAX){
		cout<<"\nINGRESANDO IMAGEN "<<*c;
		cout<<"\nIngrese el codigo: ";
		cin>>img[*c].codigo;
		cout<<"Ingrese el nombre: ";
		fflush(stdin);
		fgets(img[*c].nombre,50,stdin);
		cout<<"Ingrese la extension: ";
		fflush(stdin);
		fgets(img[*c].extension,50,stdin);
		cout<<"Ingrese el tamaño en bytes: ";
		cin>>img[*c].tamBytes;
		cout<<"Ingrese el precio: ";
		cin>>img[*c].precio;
		(*c)++;//Aumento la cant de imagenes ingresadas
		//cout<<"\nContenido de c: "<<*c<<"\n";
	}
	else{
		cout<<"\nERROR No hay espacio";
	}
}
	
void mostrar(struct inventario img[],int tam){ 	
	for(int i=0;i<tam;i++){
		cout<<"\n\nIMAGEN "<<i<<"\n";
		cout<<"\nCodigo: "<<img[i].codigo;
		cout<<"\nNombre: "<<img[i].nombre;
		cout<<"Extension: "<<img[i].extension;
		cout<<"Tamaño en bytes: "<<img[i].tamBytes;
		cout<<"\nPrecio: "<<img[i].precio;
}}
void mostrarBusqueda(struct inventario *img){
	//cout<<"\n\n*************\nENTRANDO\n******************\n";
	cout<<"\nCodigo: "<<img->codigo;
	cout<<"\nNombre: "<<img->nombre;
	cout<<"Extension: "<<img->extension;
	cout<<"Tamaño en bytes: "<<img->tamBytes;
	cout<<"\nPrecio: "<<img->precio;
	//cout<<"\n\n*************\nSALIENDO\n******************\n";
}
			
void buscar(struct inventario img[],int *c){
	int m=0;
	float b=0; //Numero a buscar
	char cad[50];//cadena a buscar
	int band=0; //band=1 si encuentra coincidencias
	do{
	band=0;//reinicio las coincidencias
	cout<<"\nBuscar por: ";
	cout<<"\n1)Codigo";
	cout<<"\n2)Nombre";
	cout<<"\n3)extension";
	cout<<"\n4)Tamanio en Bytes";
	cout<<"\n5)Precio";
	cout<<"\n6)Volver al menu principal\n";
	cin>>m;
	if(m==6) return;
	switch(m){
		case 1: 
			cout<<"\nQue CODIGO desea buscar?: ";
			cin>>b;
			cout<<"\nResultado: ";
			for(int i=0;i<*c;i++){
				if(b==img[i].codigo){
					band=1;
					cout<<"\n\nIMAGEN "<<i<<"\n";
					/*cout<<"\nCodigo: "<<img[i].codigo;
					cout<<"\nNombre: "<<img[i].nombre;
					cout<<"Extension: "<<img[i].extension;
					cout<<"Tamaño en bytes: "<<img[i].tamBytes;
					cout<<"\nPrecio: "<<img[i].precio;*/
					mostrarBusqueda(&img[i]);
			}}
			if(band==0) cout<<"\nNo se encontraron coincidencias";
			cout<<endl<<"\nPresione una tecla para continuar\n";
			getch();
			break;		
						
			case 2:
			do{
			cout<<"\nQue NOMBRE desea buscar? (no mas de 40 caracteres): ";
			fflush(stdin);
			fgets(cad,50,stdin);
			}while(strlen(cad)>40);
			
			cout<<"\nResultado: ";
			for(int i=0;i<*c;i++){
			if(strcmp(cad,img[i].nombre)==0){
			band=1;
			cout<<"\n\nIMAGEN "<<i<<"\n";
			mostrarBusqueda(&img[i]);
			}}
			if(band==0) cout<<"\nNo se encontraron coincidencias";
			cout<<endl<<"\nPresione una tecla para continuar\n";
			getch();
			break;
						
			case 3:
			do{
			cout<<"\nQue EXTENSION desea buscar? (no mas de 40 caracteres): ";
			fflush(stdin);
			fgets(cad,50,stdin);
			}while(strlen(cad)>40);
			cout<<"\nResultado: ";
			for(int i=0;i<*c;i++){
				if(strcmp(cad,img[i].extension)==0){
					band=1;
					cout<<"\n\nIMAGEN "<<i<<"\n";
					mostrarBusqueda(&img[i]);
			}}
			if(band==0) cout<<"\nNo se encontraron coincidencias";
			cout<<endl<<"\nPresione una tecla para continuar\n";
			getch();
			break;
						
			case 4: 
			cout<<"\nQue TAMANIO EN BYTES desea buscar? : ";
			cin>>b;
			cout<<"\nResultado: ";
			for(int i=0;i<*c;i++){
				if(b==img[i].tamBytes){
					band=1;
					cout<<"\n\nIMAGEN "<<i<<"\n";
					mostrarBusqueda(&img[i]);
			}}
			if(band==0) cout<<"\nNo se encontraron coincidencias";
			cout<<endl<<"\nPresione una tecla para continuar\n";
			getch();
			break;
						
			case 5: 
			cout<<"\nQue PRECIO desea buscar? : ";
			cin>>b;
			cout<<"\nResultado: ";
			for(int i=0;i<*c;i++){
				if(b==img[i].precio){
					band=1;
					cout<<"\n\nIMAGEN "<<i<<"\n";
					mostrarBusqueda(&img[i]);
			}}
			if(band==0) cout<<"\nNo se encontraron coincidencias";
			cout<<endl<<"\nPresione una tecla para continuar\n";
			getch();
			break;
			}
	}while(m!=6);
}
				
void eliminar(struct inventario img[],int *c){
	int m=0;
	do{
	cout<<"\nQue nro de imagen (entre 0 y "<<(*c)-1 <<") desea ELIMINAR? (Ingrese '-1' para salir)\n ingrese un valor: ";
	cin>>m;
	if(m==-1) return;
	}while(m>=(*c) or m<0);
					
	cout<<"\nELIMINANDO IMAGEN "<<m;
	for(int i=m; i<(*c)-1;i++){	//elimino una imagen y pongo la siguiente en su lugar, corro todas las imagenes a una posicion anterior
	img[i].codigo=img[i+1].codigo;
	strcpy(img[i].nombre,img[i+1].nombre);
	strcpy(img[i].extension,img[i+1].extension);
	img[i].tamBytes=img[i+1].tamBytes;
	img[i].precio=img[i+1].precio;
	}
	(*c)--;//decremento el nro de imagenes guardadas
	//cout<<"\nContenido de c: "<<*c<<"\n";
}
					
void modificar(struct inventario img[],int *c){
	int m=0;
	do{
		cout<<"\nQue nro de imagen (entre 0 y "<<(*c)-1 <<") desea modificar? (Ingrese '-1' para salir)\n ingrese un valor: ";
		cin>>m;
		if(m==-1) return;
	}while(m>=(*c) or m<0);
						
	cout<<"\nMODIFICANDO IMAGEN "<<m;
						
	cout<<"\nIngrese el codigo: ";
	cin>>img[m].codigo;
	cout<<"Ingrese el nombre: ";
	fflush(stdin);
	fgets(img[m].nombre,50,stdin);
	cout<<"Ingrese la extension: ";
	fflush(stdin);
	fgets(img[m].extension,50,stdin);
	cout<<"Ingrese el tamaño en bytes: ";
	cin>>img[m].tamBytes;
	cout<<"Ingrese el precio: ";
	cin>>img[m].precio;
	//cout<<"\nContenido de c: "<<*c<<"\n";
}
						
						
int main(int argc, char *argv[]) {
	int n=0;//nro para ingresar acciones
	int c=0;//cantidad de imagenes cargadas
		
	//struct inventario Imagen[0]={123,"playa\n",".cpp\n",12,24}; por que no anda???
	
	/*Imagen[0].codigo=123;
	strcpy(Imagen[0].nombre,"playa\n");
	strcpy(Imagen[0].extension,".cpp\n");
	Imagen[0].tamBytes=12;
	Imagen[0].precio=24;
							
	Imagen[1].codigo=0;
	strcpy(Imagen[1].nombre,"hola\n");
	strcpy(Imagen[1].extension,"0\n");
	Imagen[1].tamBytes=12;
	Imagen[1].precio=0;
							
	Imagen[2].codigo=12;
	strcpy(Imagen[2].nombre,"hola\n");
	strcpy(Imagen[2].extension,".cpp\n");
	Imagen[2].tamBytes=12;
	Imagen[2].precio=24;
							
	c=3;
	*/
	cout<<"Bienvenido!";
	do{
		cout<<"\n\nIngrese el nro de accion que desea realizar:";
		cout<<"\n1)Agregar";
		cout<<"\n2)Eliminar";
		cout<<"\n3)Modificar";
		cout<<"\n4)Buscar";
		cout<<"\n5)Mostrar";
		cout<<"\n6)Salir\n";
		cin>>n;
								
		switch(n){
			case 1: 
				cout<<"\nAGREGAR IMAGEN\n";
				agregar(Imagen,&c);
			break;

			case 2: 
				cout<<"\nELIMINAR IMAGEN\n";
				eliminar(Imagen,&c);
			break;
									
			case 3: 
				cout<<"\nMODIFICAR IMAGEN\n";
				modificar(Imagen,&c);
			break;
									
			case 4: 
				cout<<"\nBUSCAR IMAGEN\n";
				buscar(Imagen,&c);
			break;
									
			case 5: 
				if(c==0) cout<<"\nError No hay Imagenes en el Inventario";
				else {
					cout<<"\nMOSTRANDO";
					mostrar(Imagen,c);
				}	
			break;
	
			default: break;
		}//llave del switch	
	}while(n!=6);
return 0;
}
