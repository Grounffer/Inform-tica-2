#include <iostream>
#include <ctime>
#include <string.h>
using namespace std;

class Sensores{
private:
	char marca[20];
	char tipo[20];
	char unidadMedida[10];
	
public:
	void setSensor();
	void getSensor();
};

class Medicion:public Sensores{
	
private:
	time_t hora;
	struct tm *informacion;
	char texto[50][100];
	int valor;
	char comentarios[200];
	
public:
	void setFechaHora(int);
	void getFechaHora(int);
	void setMedicion();
	void getMedicion();
};

class Lista:public Medicion{
private:
	int cant = 0;
	
public:
	void AgregarMedicion(class Lista lista[], int);
	void EliminarMedicion(class Lista lista[], int, int);
	void MostrarMedicion(class Lista lista[], int);
	void GuardarEnArchivo(class Lista lista[], int, FILE *archivo);
	void LeerArchivo(FILE *archivo);
};


int main() {
	
	int cantidad = 0, menu = 0, seleccion = 0;
	FILE *archivoMediciones;
	const int total = 50;
	Lista Mediciones[total];
	
	do{
		printf("\nMenú:\n1) Agregar medición.\n2) Eliminar medición. \n3) Mostrar mediciones. \n4) Guardar en archivo. \n5) Leer archivo diario. \n6) Salir. ");
		cin >> menu ;
		getchar();
		
		switch(menu){
			
		case 1:
			if(cantidad < total){
				Mediciones[cantidad].AgregarMedicion(Mediciones, cantidad);
				cantidad++;
			}
			else{
				cout << "\nSe superaron la cantidad total de mediciones. \n" ;
			}
			break;
			
		case 2:
			printf("Que medicion desea eliminar? (de 0 a %d)", cantidad-1);
			cin >> seleccion ;
			getchar();
			
			Mediciones[0].EliminarMedicion(Mediciones, cantidad, seleccion);
			cantidad--;
			break;
			
		case 3:
			Mediciones[0].MostrarMedicion(Mediciones, cantidad);
			break;
		case 4:
			Mediciones[0].GuardarEnArchivo(Mediciones, cantidad, archivoMediciones);
			break;
		case 5:
			Mediciones[0].LeerArchivo(archivoMediciones);
			break;
			
		default:
			break;
			
		}//switch
		
	} while(menu > 0 && menu < 6);
	
	
	
	
	return 0;
}

void Sensores::setSensor(){
	
	char setMarca[20], setTipo[20], setUnidad[10];
	
	cout << "\nIngrese la marca del sensor " ;
	fgets( setMarca , 20, stdin);
	
	cout << "Ingrese el tipo del sensor " ;
	fgets( setTipo , 20, stdin);
	
	cout << "Ingrese la unidad del sensor " ;
	fgets( setUnidad , 10, stdin);
	
	strcpy(marca, setMarca);
	strcpy(tipo, setTipo);
	strcpy(unidadMedida, setUnidad);
	
}

void Sensores::getSensor(){
	
	cout <<"Marca: " << marca;
	cout <<"Tipo: " << tipo;
	cout <<"Unidad: " << unidadMedida;
}
void Medicion::setFechaHora(int i){
	
	time_t setHora;
	struct tm *setInformacion;
	
	time(&setHora);
	setInformacion = localtime(&setHora);
	
	hora = setHora;
	informacion = setInformacion;
	
	strftime(texto[i], 100, "Fecha y hora: %d-%m-%Y %X\n", informacion);
}

void Medicion::getFechaHora(int i){
	
	printf("%s", texto[i]);
	
}
void Medicion::setMedicion(){
	
	int setValor;
	char setComentarios[200];
	
	cout << "Ingrese Valor de la medicion ";
	cin >> setValor ;
	getchar();
	
	cout << "Ingrese los comentarios de la medicion ";
	fgets(setComentarios, 200, stdin);
	
	valor = setValor;
	strcpy(comentarios, setComentarios);
}

void Medicion::getMedicion(){
	
	cout << "Valor de la medicion: " << valor << endl;
	cout << "Comentarios: "<< comentarios;
}

void Lista::AgregarMedicion(class Lista lista[],int i){
	
	lista[i].setSensor();
	lista[i].setFechaHora(i);
	lista[i].setMedicion();
}

void Lista::EliminarMedicion(class Lista lista[], int cant, int seleccion){
	
	int i=0;
	for(i=seleccion ; i <= cant ; i++){
		lista[i] = lista[i+1];
	}//eliminar medicion moviendo una medicion un lugar hacia atras
	printf("\nMedicion %d Eliminada correctamente\n", i);
}

void Lista::MostrarMedicion(class Lista lista[], int cant){
	
	for (int i=0; i<cant ; i++) {
		printf("\nMedicion[%d]:\n", i+1);
		lista[i].getSensor();
		lista[i].getFechaHora(i);
		lista[i].getMedicion();
	}
}

void Lista::GuardarEnArchivo(class Lista lista[], int total, FILE *archivo){
	
	int i = 0;
	time_t horaActualAux;
	struct tm *fechaActualAux;
	char textoAux[100];
	
	time(&horaActualAux);
	fechaActualAux = localtime(&horaActualAux);
	strftime(textoAux, 100, "%d-%m-%Y.bin", fechaActualAux);
	
	
	archivo = fopen(textoAux, "wb");
	if(archivo != NULL){
		printf("\nArchivo abierto correctamente!!\n");
	}
	else{
		printf("Archivo no abrio correctamente!!\n");
		exit(1);
	}
	while( i != total){
		fwrite(&lista[i], sizeof(class Lista), 1, archivo);
		i++;
	}
	
	fclose(archivo);
	printf("\nArchivo guardado correctamente!!\n");
}

void Lista::LeerArchivo(FILE *archivo){
	
	int i = 0;
	const int leer = 1;
	Lista listabinaria;
	
	time_t horaActualAux;
	struct tm *fechaActualAux;
	char textoAux[100];
	
	time(&horaActualAux);
	fechaActualAux = localtime(&horaActualAux);
	strftime(textoAux, 100, "%d-%m-%Y.bin", fechaActualAux);
	
	
	archivo = fopen(textoAux, "rb");
	if(archivo != NULL){
		printf("\nArchivo abierto correctamente!!\n");
	}
	else{
		printf("Archivo no abrio correctamente!!\n");
		exit(1);
	}
	rewind(archivo);
	while( (fread(&listabinaria, sizeof(class Lista), leer, archivo)) == leer){
		printf("\nMedicion[%d]:\n", i+1);
		listabinaria.getSensor();
		listabinaria.getFechaHora(i);
		listabinaria.getMedicion();
		i++;
	}
	fclose(archivo);
}
