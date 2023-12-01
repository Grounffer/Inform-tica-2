/*
EJERCICIO 5
Copie el código fuente de su ejercicio 3 del TP3 de estructuras. Añada a su programa la
funcionalidad para guardar en archivo el arreglo de estructuras y para mostrarlo luego.
Use las funciones fread y fwrite para la lectura y escritura del archivo binario.
size_t fread(void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);
size_t fwrite(const void *ptr, size_t size_of_elements, size_t number_of_elements, FILE
*a_file);
Comente su código fuente  para aclarar la funcionalidad de su
	programa e indicar si guarda ambas funciones en un mismo archivo o en archivos
	separados.
*/
#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

const int TMAX =5;

struct SENSOR{
	char marca[50];
	char tipo[50];
	char unid_med[50];
};

struct SENSOR sen1={"sony","distancia","m"};
struct SENSOR sen2={"philco","termico","°c"};
struct SENSOR sen3={"sanyo","presion","bar"};

struct MEDICION{
	char fecha[50];
	char hora[50];
	struct SENSOR sens_usado;
	float val_med=0;
	char coment[50];
}mediciones[TMAX];

void agregar(struct MEDICION med[],int *c);
void mostrar(struct MEDICION med[],int *c);
void modificar(struct MEDICION med[],int *c);
void buscar(struct MEDICION med[],int *c);
void mostrarBusqueda(struct MEDICION *med);
void eliminar(struct MEDICION med[],int *c);
void mostrarSensores();


int main(int argc, char *argv[]) {
	FILE *fp;
	int n=0;//nro para ingresar acciones
	int c=0;//cantidad de mediciones cargadas
	int total=0;
	
	//DATOS PARA GUARDAR DE EJEPLO SIN INGRESARLOS A MANO
	/*
	strcpy(mediciones[0].fecha,"12 01 2002");
	strcpy(mediciones[0].hora,"09:38:02");
	mediciones[0].sens_usado = sen1;
	mediciones[0].val_med=123;
	strcpy(mediciones[0].coment,"hola hola");
	
	strcpy(mediciones[1].fecha,"07 01 1998");
	strcpy(mediciones[1].hora,"10:38:02");
	mediciones[1].sens_usado = sen3;
	mediciones[1].val_med=111;
	strcpy(mediciones[1].coment,"Buenas tardes");
	c=2;
	*/
	
	/*
	strcpy(mediciones[12].fecha,"fechaaaa");
	strcpy(mediciones[12].hora,"horaaaa");
	mediciones[12].sens_usado = sen3;
	mediciones[12].val_med=12;
	strcpy(mediciones[12].coment,"12");
	c=13;
	*/
	
	//FIN DE DATOS DE EJEMPLO, comentar para omitir
	
	cout<<"Bienvenido!";
	do{
		cout<<"\n\nOPCIONES";
		cout<<"\n1)Agregar mediciones";
		cout<<"\n2)Eliminar mediciones";
		cout<<"\n3)Modificar mediciones";
		cout<<"\n4)Buscar mediciones";
		cout<<"\n5)Mostrar mediciones";
		cout<<"\n6)Mostrar SENSORES";
		cout<<"\n7)Guardar en un archivo";
		cout<<"\n8)recuperar datos del archivo";
		cout<<"\n9)Salir\n";
		cout<<"\nIngrese el nro de accion que desea realizar:";
		cin>>n;
		
		switch(n){
		case 1: 
			cout<<"\nAGREGAR MEDICION\n";
			agregar(mediciones,&c);
			break;
			
		case 2: 
			if(c==0) cout<<"\nError No hay mediciones realizadas";
			else {
				cout<<"\nELIMINAR MEDICION\n";
				//eliminar(Imagen,&c);
			}
			break;
			
		case 3: 
			if(c==0) cout<<"\nError No hay mediciones realizadas";
			else{	cout<<"\nMODIFICANDO";	modificar(mediciones,&c); }	
			break;
			
		case 4: 
			if(c==0) cout<<"\nError No hay mediciones realizadas";
			else {
				cout<<"\nBUSCAR MEDICION\n";
				buscar(mediciones,&c);
			}
			break;
		case 5: 
			if(c==0) cout<<"\nError No hay mediciones realizadas";
			else {
				cout<<"\nMOSTRANDO MEDICIONES";
				mostrar(mediciones,&c);
			}	
			break;
		case 6: cout<<"\nMOSTRANDO SENSORES"; mostrarSensores();
		break;
		case 7:
			cout<<"\nGUARDAR EN ARCHIVO\n";
			
			fp = fopen("Datos TP4-e5-V2.bin", "wb");
			if(fp==NULL){
				cout<<"\n\nERROR AL ABRIR ARCHIVO";
				exit (1);
			}else{
				
				
				// fprint
				// Guarda datos de la secuencia y los almacena según el formato del parámetro en
				//	las ubicaciones señaladas por los argumentos adicionales. 
				//
				fprintf( fp ,"%d ", c); //guardo en el archivo la variable c, es la cant de estructuras cargadas
				
				// "%d " dejo un espacio luego del entero para que no se mezcle con lo siguiente que guarde
				
				//
				//	fwrite( void *estructura, tamaño en bytes, nro de veces que quiero guardar una estructura, archivo donde guardo)
				// 	(puntero de tipo void ya que no importa el timpo de archivo)
				//	devuelve el nro de veces que pudo escribir buffers
				//
				
				total = fwrite(&mediciones,sizeof(struct MEDICION),c,fp);
				
				//si el total de guardados es distinto a la cant de estructuras: ERROR
				if(total!=c) cout<<"\nERROR DE ESCRITURA"; 
				
			}
			fclose(fp);
			
			break;	
		case 8:
			cout<<"\nrecuperar datos de ARCHIVO\n";
			fp = fopen("Datos TP4-e5-V2.bin", "rb");
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
				//cout<<"\nc: "<<c<<"\n"; 
				//cout<<"\n-----------------c: "<<c<<"\n";
				
				fread(&mediciones,sizeof(struct MEDICION),c,fp);
				
				//MOSTRANDO CONTENIDO DE ESTRUCTURAS
				if(c==0) cout<<"\nError No hay Imagenes en el Inventario";
				else {
					cout<<"\nMOSTRANDO";
					for(int i=0;i<c;i++){
						cout<<"\n\n------------MEDICION "<<i<<"-------------\n";
						cout<<"\nFecha: "<<mediciones[i].fecha;
						cout<<"\nHora: "<<mediciones[i].hora;
						cout<<"\nSENSOR: ";
						cout<<"\n\tMarca: "<<mediciones[i].sens_usado.marca;
						cout<<"\n\tTipo: "<<mediciones[i].sens_usado.tipo;
						cout<<"\n\tUnidad de medida: "<<mediciones[i].sens_usado.unid_med;
						cout<<"\n\nValor medido: "<<mediciones[i].val_med;
						cout<<"\nComentarios: "<<mediciones[i].coment;
					}
				}	
			}
			fclose(fp);
			break;
		default: break;
		}//llave del switch	
	}while(n!=9);
	return 0;
}

void agregar(struct MEDICION med[],int *c){
	
	int m=0;
	if(*c<=TMAX){
		cout<<"\nINGRESANDO MEDICION "<<*c;
		cout<<"\nIngrese la fecha: ";
		fflush(stdin);
		fgets(med[*c].fecha,50,stdin);
		cout<<"Ingrese la hora: ";
		fflush(stdin);
		fgets(med[*c].hora,50,stdin);
		
		do{
			cout<<"\nQue nro de sensor desea cargar?";
			cout<<"\n1) Sensor 1";
			cout<<"\n2) Sensor 2";
			cout<<"\n3) Sensor 3";
			cout<<"\nIngrese un valor: ";
			cin>>m;
		}
		while(m<1 or m>3);
		switch(m){
		case 1:	med[*c].sens_usado = sen1;	break;
		case 2:	med[*c].sens_usado = sen2;  break;
		case 3: med[*c].sens_usado = sen3;	break;
		default: break;
		}
		cout<<"Ingrese El valor medido: ";
		cin>>med[*c].val_med;
		cout<<"Ingrese un comentario: ";
		fflush(stdin);
		fgets(med[*c].coment,50,stdin);
		
		(*c)++;//Aumento la cant de mediciones ingresadas
	}
	else{
		cout<<"\nERROR No hay espacio";
	}
}
void mostrar(struct MEDICION med[],int *c){ 	
	for(int i=0;i<*c;i++){
		cout<<"\n\n------------MEDICION "<<i<<"-------------\n";
		cout<<"\nFecha: "<<med[i].fecha;
		cout<<"\nHora: "<<med[i].hora;
		cout<<"\nSENSOR: ";
		cout<<"\n\tMarca: "<<med[i].sens_usado.marca;
		cout<<"\n\tTipo: "<<med[i].sens_usado.tipo;
		cout<<"\n\tUnidad de medida: "<<med[i].sens_usado.unid_med;
		cout<<"\n\nValor medido: "<<med[i].val_med;
		cout<<"\nComentarios: "<<med[i].coment;
	}}
	
void mostrarSensores(){ 	
	cout<<"\n\nSENSOR 1: ";
	cout<<"\n\tMarca: "<<sen1.marca;
	cout<<"\n\tTipo: "<<sen1.tipo;
	cout<<"\n\tUnidad de medida: "<<sen1.unid_med;
	cout<<"\n\nSENSOR 2: ";
	cout<<"\n\tMarca: "<<sen2.marca;
	cout<<"\n\tTipo: "<<sen2.tipo;
	cout<<"\n\tUnidad de medida: "<<sen2.unid_med;
	cout<<"\n\nSENSOR 3: ";
	cout<<"\n\tMarca: "<<sen3.marca;
	cout<<"\n\tTipo: "<<sen3.tipo;
	cout<<"\n\tUnidad de medida: "<<sen3.unid_med;
}	
void modificar(struct MEDICION med[],int *c){
	int m=0;
	int n=0;
	do{
		cout<<"\nQue nro de MEDICION (entre 0 y "<<(*c)-1 <<") desea modificar? (Ingrese '-1' para salir)\ningrese un valor: ";
		cin>>m;
		if(m==-1) return;
	}while(m>=(*c) or m<0);
	
	cout<<"\nINGRESANDO MEDICION "<<m;
	cout<<"\nIngrese la fecha: ";
	fflush(stdin);
	fgets(med[m].fecha,50,stdin);
	cout<<"Ingrese la hora: ";
	fflush(stdin);
	fgets(med[m].hora,50,stdin);
	
	do{
		cout<<"\nQue nro de sensor desea cargar?";
		cout<<"\n1) Sensor 1";
		cout<<"\n2) Sensor 2";
		cout<<"\n3) Sensor 3";
		cout<<"\nIngrese un valor: ";
		cin>>n;
	}
	while(n<1 or n>3);
	switch(n){
	case 1:	med[m].sens_usado = sen1;	break;
	case 2:	med[m].sens_usado = sen2;  break;
	case 3: med[m].sens_usado = sen3;	break;
	default: break;
	}
	cout<<"Ingrese El valor medido: ";
	cin>>med[m].val_med;
	cout<<"Ingrese un comentario: ";
	fflush(stdin);
	fgets(med[m].coment,50,stdin);
	
}
				
void mostrarBusqueda(struct MEDICION *med){
	cout<<"\nFecha: "<<med->fecha;
	cout<<"Hora: "<<med->hora;
	cout<<"SENSOR: ";
	cout<<"\n\tMarca: "<<med->sens_usado.marca;
	cout<<"\n\tTipo: "<<med->sens_usado.tipo;
	cout<<"\n\tUnidad de medida: "<<med->sens_usado.unid_med;
	cout<<"\n\nValor medido: "<<med->val_med;
	cout<<"\nComentarios: "<<med->coment;
}
					
void buscar(struct MEDICION med[],int *c){
	int m=0;
	float b=0; //Numero a buscar
	int p=0; //nro de sensor a buscar
	char cad[50];//cadena a buscar
	int band=0; //band=1 si encuentra coincidencias
	do{
		band=0;//reinicio las coincidencias
		cout<<"\nBuscar por: ";
		cout<<"\n1)fecha";
		cout<<"\n2)Sensor";
		cout<<"\n3)Valor medido";
		cout<<"\n4)Volver al menu principal\n";
		cin>>m;
		if(m==4) return;
		switch(m){
			
		case 1:
			do{
				cout<<"\nQue FECHA desea buscar?: ";
				fflush(stdin);
				fgets(cad,50,stdin);
			}while(strlen(cad)>40);
			
			cout<<"\nResultado: ";
			for(int i=0;i<*c;i++){
				if(strcmp(cad, med[i].fecha )==0){
					band=1;
					cout<<"\n\nMEDICION "<<i<<"\n";
					mostrarBusqueda(&med[i]);
				}}
			if(band==0) cout<<"\nNo se encontraron coincidencias";
			cout<<endl<<"\nPresione una tecla para continuar\n";
			getch();
			break;
		case 2:
			do{
				cout<<"\nQue SENSOR desea buscar? (1,2 o 3): ";
				cin>>p;
			}while(p<1 or p>3);
			
			switch(p){
			case 1:
				cout<<"\nResultados para SENSOR 1: ";
				for(int i=0;i<*c;i++){
					if( strcmp(med[i].sens_usado.marca,sen1.marca)==0 and strcmp(med[i].sens_usado.tipo,sen1.tipo)==0  and strcmp(med[i].sens_usado.unid_med,sen1.unid_med)==0 ){
						band=1;
						cout<<"\n\nMEDICION "<<i<<"\n";
						mostrarBusqueda(&med[i]);
					}}
				if(band==0) cout<<"\nNo se encontraron coincidencias";
				cout<<endl<<"\nPresione una tecla para continuar\n";
				getch();
				break;
			case 2:
				cout<<"\nResultados para SENSOR 2: ";
				for(int i=0;i<*c;i++){
					if( strcmp(med[i].sens_usado.marca,sen2.marca)==0 and strcmp(med[i].sens_usado.tipo,sen2.tipo)==0  and strcmp(med[i].sens_usado.unid_med,sen2.unid_med)==0 ){
						band=1;
						cout<<"\n\nMEDICION "<<i<<"\n";
						mostrarBusqueda(&med[i]);
					}}
				if(band==0) cout<<"\nNo se encontraron coincidencias";
				cout<<endl<<"\nPresione una tecla para continuar\n";
				getch();
				break;
			case 3:
				cout<<"\nResultados para SENSOR 3: ";
				for(int i=0;i<*c;i++){
					if( strcmp(med[i].sens_usado.marca,sen3.marca)==0 and strcmp(med[i].sens_usado.tipo,sen3.tipo)==0  and strcmp(med[i].sens_usado.unid_med,sen3.unid_med)==0 ){
						band=1;
						cout<<"\n\nMEDICION "<<i<<"\n";
						mostrarBusqueda(&med[i]);
					}}
				if(band==0) cout<<"\nNo se encontraron coincidencias";
				cout<<endl<<"\nPresione una tecla para continuar\n";
				getch();
				break;
			default: break;
			}
			break;			
		case 3:
			do{
				cout<<"\nQue VALOR MEDIDO desea buscar?: ";
				cin>>b;
			}while(b>40);
			
			cout<<"\nResultado: ";
			for(int i=0;i<*c;i++){
				if(b==med[i].val_med){
					band=1;
					cout<<"\n\nMEDICION "<<i<<"\n";
					mostrarBusqueda(&med[i]);
				}}
			if(band==0) cout<<"\nNo se encontraron coincidencias";
			cout<<endl<<"\nPresione una tecla para continuar\n";
			getch();
			break;
		}
	}while(m!=4);
}
void eliminar(struct MEDICION med[],int *c){		
	int m=0;
	do{
		cout<<"\nQue nro de MEDICION (entre 0 y "<<(*c)-1 <<") desea ELIMINAR? (Ingrese '-1' para salir)\n ingrese un valor: ";
		cin>>m;
		if(m==-1) return;
	}while(m>=(*c) or m<0);
	
	cout<<"\nELIMINANDO MEDICION "<<m;
	for(int i=m; i<(*c)-1;i++){	//elimino una medicion y pongo la siguiente en su lugar, corro todas las MEDICIONES a una posicion anterior
		strcpy(med[i].fecha,med[i+1].fecha);
		strcpy(med[i].hora,med[i+1].hora);
		med[i].sens_usado = med[i+1].sens_usado;
		med[i].val_med=med[i+1].val_med;
		strcpy(med[i].coment,med[i+1].coment);	
	}
	(*c)--;//decremento el nro de MEDICIONES guardadas
}
