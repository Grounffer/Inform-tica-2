#include<stdio.h>  
#include<stdlib.h>  
/*Este programa permite saber el largo de un archivo de texto*/
int main(){  
	FILE *fp;  
	int largo;
	if ( (fp=fopen("ArchivoTell.txt","r")) != NULL ) {
		
		fseek( fp, 0, SEEK_END ); 
		
		largo = ftell(fp);
		
	} else { printf("Error al abrir el archivo");
		exit(1);
	}
	fclose(fp);  
	printf("El largo del archivo de texto es: %d", largo);
}  
	
