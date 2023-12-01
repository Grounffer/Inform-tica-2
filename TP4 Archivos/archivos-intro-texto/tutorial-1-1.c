#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	FILE *fp;
	fp = fopen ( "file.txt", "r" );     // ABRIR archivo
	
	if (fp==NULL) { //revisar que se abrio OK el archivo 
		// int fputs(const char *str, FILE *stream)
		fputs ("File error",stderr); 
		exit (1);
	}
	
	
	fclose ( fp ); // CERRAR archivo 
	
	return 0;
}
