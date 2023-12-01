#include<stdio.h>

struct equipo	//declaro una estructura
{
	char nombre[10];
	int id;
};

int main()
{
	struct equipo e;
	
	FILE *p,*q;
	p = fopen("two.txt", "w");
	printf("Ingrese nombre del equipamiento, ENTER y luego el id:\n");
	
	//	LEE DATOS DE TACLADO
	//	scanf(paramtreo1, parametro2, ....); 
	//

	scanf("%s %d", e.nombre, &e.id); //1ro lee caracteres hasta el primer espacio en blanco. guarda en e.nombre
									//2do lee un entero. guarda en e.id
	
	fprintf( p ,"%s %d", e.nombre, e.id);	//guarda los datos en el archivo
	fclose(p);
	
	q = fopen("two.txt", "r");	//abro el archivo
	
	do
	{
		//	LEE DATOS DE UN ARCHIVO
		//	fscanf(*archivo, paramtreo1, parametro2, ....); 		
		//
		
		fscanf(q,"%s %d", e.nombre, &e.id); //1ro lee caracteres hasta el primer espacio en blanco. guarda en e.nombre
											//2do lee un entero. guarda en e.id
		printf("%s %d", e.nombre, e.id);
	}
	while(!feof(q));
	
	fclose(q);
	
	return 0;
}
