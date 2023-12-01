#include <stdio.h>
#include <iostream>
using namespace std;

int main () {
	char cad[50];
	int c=0;
	char cad1[]={"archivoDeEjemploMiLoco.txt"};
	
	FILE *fp;//declaro un puntero al archivo que deseo abrir
	
	fp = fopen(cad1, "w+"); //abro el archivo archivo-ejemplo.txt
	
	if (fp==NULL) {		////pregunta si el archivo se abro correctamente, si no, da mensaje de error
		fputs ("File error",stderr); 
		exit (1);
	}
	
	fputs("Este es un ejemplo en C.\n", fp); //escribo en el archivo
	
	cout<<"\nEscriba lo que desa guardar en el archivo\n";
	
	fgets(cad,50,stdin);
	fputs(cad, fp); //escribo en el archivo la cadena que ingresé dentro del programa
	
	fclose(fp);//cierro el archivo
	
	cout<<"\n\nMOSTRANDO EL ARCHIVO\n\n";
	
	fp = fopen(cad1,"r");
	
	while(1) {
		c = fgetc(fp); //Lee de a un caracter a la vez y lo guarda en la variable c
		if( feof(fp) ) {  // f es de File, eof es de End Of File. Pregunta si estoy en el final de archivo
			break ;
		}
		printf("%c", c);
	}
	
	fclose(fp);
	
	cout<<"\nFin del programa";
	
	return(0);
}

