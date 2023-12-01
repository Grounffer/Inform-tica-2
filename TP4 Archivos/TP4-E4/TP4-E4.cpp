/*
EJERCICIO 4
Copie el código fuente de su ejercicio 2 del TP3 de estructuras. Añada a su programa la
funcionalidad para guardar en archivo el arreglo de estructuras y para mostrarlo luego.
Use las funciones fread y fwrite para la lectura y escritura del archivo binario.

size_t fread(void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);
size_t fwrite(const void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);

Comente su código fuente  para aclarar la funcionalidad de su programa.
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
	FILE *fp;
	int n=0;//nro para ingresar acciones
	int c=0;//cantidad de imagenes cargadas
	int total=0;
	
	//DATOS PARA GUARDAR DE EJEPLO SIN INGRESARLOS A MANO
	/*
	Imagen[0].codigo=123;
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
	//FIN DE DATOS DE EJEMPLO, comentar para omitir
	
	cout<<"Base de datos"<<" IMAGENES."<<"Bienvenido!";
	do{
		cout<<"\n\nIngrese el nro de accion que desea realizar:";
		cout<<"\n1)Agregar";
		cout<<"\n2)Eliminar";
		cout<<"\n3)Modificar";
		cout<<"\n4)Buscar";
		cout<<"\n5)Mostrar";
		cout<<"\n6)Guardar en un archivo";
		cout<<"\n7)recuperar datos del archivo";
		cout<<"\n8)Salir\n";
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
		case 6:
			cout<<"\nGUARDAR EN ARCHIVO\n";
			
			fp = fopen("Datos.bin", "wb");
			if(fp==NULL){
				cout<<"\n\nERROR AL ABRIR ARCHIVO";
				exit (1);
			}else{
				
				
			// fprint
			// Guarda datos de la secuencia y los almacena según el formato del parámetro en
			//	las ubicaciones señaladas por los argumentos adicionales. 
			//
			fprintf( fp ,"%d ", c); //guardo en el archivo la variable c, es la cant de estructuras cargadas
			
			//
			//	fwrite( void *estructura, tamaño en bytes, nro de veces que quiero guardar una estructura, archivo donde guardo)
			// 	(puntero de tipo void ya que no importa el timpo de archivo)
			//	devuelve el nro de veces que pudo escribir buffers
			//
			
			total = fwrite(&Imagen,sizeof(struct inventario),c,fp);
			
			//si el total de guardados es distinto a la cant de estructuras: ERROR
			if(total!=c) cout<<"\nERROR DE ESCRITURA"; 
			
			}
			fclose(fp);
			
		break;	
		case 7:
			cout<<"\nrecuperar datos de ARCHIVO\n";
			fp = fopen("Datos.bin", "rb");
			if(fp==NULL){
				cout<<"\n\nERROR AL ABRIR ARCHIVO";
				exit (1);
			}else{
				cout<<"\nLEYENDO ARCHIVO\n";
				
				// fscanf
				//  Lee datos de la secuencia y los almacena según el formato del parámetro en
				//	las ubicaciones señaladas por los argumentos adicionales. 
				//
				
				fscanf( fp ,"%d ", &c); //leo el primer nro, es la cant de estructuras guardadadas en el archivo, lo guardo en la variable c
				cout<<"\nc: "<<c<<"\n"; 
				
				fread(&Imagen,sizeof(struct inventario),c,fp);
				
				//MOSTRANDO CONTENIDO DE ESTRUCTURAS
				if(c==0) cout<<"\nError No hay Imagenes en el Inventario";
				else {
					cout<<"\nMOSTRANDO";
					mostrar(Imagen,c);
				}	
			}
			fclose(fp);
		break;
			
		default: break;
		}//llave del switch	
	}while(n!=8);
	return 0;
}

