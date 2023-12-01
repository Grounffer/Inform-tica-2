#include<stdio.h>
#include<stdlib.h> 

/*
	fseek( archivo, bytes que nos desplazamos, desde donde me muevo );
		
	fseek( fp, 9, SEEK_SET );
	
	SEEK_SET	Principio del archivo
	SEEK_CUR	Posicion actual del puntero
	SEEK_END	Final del archivo
*/

int main(){  
	FILE *fp;  
	if ( (fp=fopen("cursando.txt","w+")) != NULL ) {  
		
		fputs("Cursamos Química.", fp);/*Se escribe en el archivo*/
		
		fseek( fp, 9, SEEK_SET ); /*Se mueve el "cursor" a donde hace falta*/
		fputs("Informática II.", fp);/*Se corrige*/
		
		fseek( fp, 0, SEEK_SET ); /*Se rebobina el archivo*/
		while( !feof(fp) ) /*Se lee el archivo y se muestra*/
			fprintf(stdout, "%c", fgetc(fp));
		
	} else { printf("Error al abrir el archivo.");
		exit(1); 
	}
	fclose(fp);  
	return 0;
} 

