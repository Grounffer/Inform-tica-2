/*
Lectura y escritura de a un caracter / byte a la vez.
Funciones usadas
fopen
fclose
fputc
fgetc

*/

#include<stdio.h>

int main()
{
	FILE *fp;
	char ch;
	
	// apertura o creación de archivo
	fp = fopen("one.txt", "w");
	printf("Ingrese texto:\n");
	
	while( ch != EOF) {
		
		ch = getchar();
		putc(ch, fp);
	}
	
	fclose(fp);
	
	ch = 'a'; 
	
	printf("Procedemos a mostrar el contenido del archivo creado:\n");
	
	fp = fopen("one.txt", "r");
	
	do{
		ch = getc(fp);
		printf("%c",ch);
	
	}while( ch != EOF);
		
	
	
	// closing the file pointer
	fclose(fp);
	
	return 0;
}
