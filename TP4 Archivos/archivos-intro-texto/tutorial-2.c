#include <stdio.h>

int main () {
	FILE *fp, *archivo2;
	
	fp = fopen("archivo.txt", "w");
	archivo2 = fopen("file.txt", "w");
		
	fputs("COMPROBAR QUE SE SOBREESCRIBE Este es un ejemplo en C.\n\n", fp);
	fputs("Guardamos caracteres en un archivo llamado.", fp);
	
	fputs("Escribo en archivo2.", archivo2);
	
	
	fclose(fp);
	fclose(archivo2);
	
	return(0);
}
