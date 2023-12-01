#include<stdio.h>  
#include<stdlib.h>  
int main(){  
	FILE *fp;  
	unsigned char a = 255, b;
	char c;
	
	if ( (fp=fopen("ArchivoR.bin","wb+")) != NULL ) {  
		
		fwrite(&a, sizeof(unsigned char), 1, fp);/*Se escribe el valor de a como unsigned char*/
		
		rewind(fp);/*rebobinamos*/
		fread(&b,sizeof(unsigned char), 1, fp);/*Se lee el valor almacenado, como unsigned char*/
		
		rewind(fp);/*rebobinamos*/
		fread(&c,sizeof(char), 1, fp);/*Se lee el valor almacenado, como char con signo*/
	}else exit(1);
	
	printf("Valores enteros equivalentes\n");
	printf("Original unsigned char a:%d\nunsigned char b:%d"
		   "\nchar c:%d",a,b,c);
	fclose(fp);  
} 
