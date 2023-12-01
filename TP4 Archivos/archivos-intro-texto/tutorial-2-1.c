#include <stdio.h>

int main () {
	FILE *fp;
	int c;
	
	fp = fopen("compara_cadenas.c","r");
	
	while(1) {
		c = fgetc(fp); // LEE DE A UN CARACTER A LA VEZ 
		if( feof(fp) ) { //FEOF FILE EOF END OF FILE 
			break ; // SI ES FIN DE ARCHIVO, SALE DEL BUCLE
		}
		printf("%c", c); // IMPRIME CARACTER
	}
	
	fclose(fp);
	
	return(0);
}
