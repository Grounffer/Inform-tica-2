#include <stdio.h>
#include <string.h>
#define MAX 20

typedef struct asignatura {
	char nombre[MAX];
	int id;
}Asignatura;

int main(int argc, char *argv[]) {
	FILE *fp;
	
	Asignatura info;
	strcpy(info.nombre, "Informática II");
	info.id = 5634; 
	
	//escribiendo en el archivo
	fp = fopen("Archivo.bin", "wb");
	if (fp != NULL) {
		printf("Apertura exitosa");		
		/*Se carga la estructura de una vez*/
		fwrite (&info, sizeof(Asignatura), 1, fp);
		
		printf("\nSe ha terminado de escribir Archivo.bin con fwrite usando estructuras...");	
	} else  printf("Problemas al abrir el archivo.");
	fclose(fp);
	
	//leyendo el archivo
	if ((fp = fopen("Archivo.bin", "rb")) != NULL){
		printf("\n\nApertura exitosa");	
		
		fread (&info, sizeof(Asignatura), 1, fp);			
		printf("\nSe ha terminado de leer Archivo.bin con fread usando estructuras...");	
		
	} else  printf("Problemas al abrir");
	fclose(fp);	
	printf ("\n\nAsignatura leída de Archivo.bin: ");
	printf ("\nID:%d\nNombre: %s",info.id, info.nombre);
	
	return 0;
}

