#include<stdio.h>

struct equipo
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
	scanf("%s %d", e.nombre, &e.id);
	fprintf(p,"%s %d", e.nombre, e.id);
	fclose(p);
	
	
	q = fopen("two.txt", "r");
	
	do
	{
		fscanf(q,"%s %d", e.nombre, &e.id);
		printf("%s %d", e.nombre, e.id);
	}
	while(!feof(q));
	
	fclose(q);
	
	return 0;
}
