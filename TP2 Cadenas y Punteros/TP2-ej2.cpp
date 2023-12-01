/*EJERCICIO 2
Escriba un programa en C para concatenar, o enlazar, dos cadenas de caracteres
ingresadas por una persona a través del teclado.
Use la función longitud creada en el ejercicio 1.
La cadena resultante será una tercera cadena donde deberemos haber copiado el
contenido de las cadenas a concatenar.
*/
#include <iostream>
#include <conio.h>
using namespace std;

int tamano(char *a){
	int cont=0;	
	while(*a!='\0' and *a!='\n' and cont<1000000){
		//cout<<"["<<cont<<"]\t"<<*a<<" ()\n"; //muestra cada elemento que recorre
		cont++;
		a++;
	}
	//cout<<"\nLongitud de la cadena: "<<cont<<"\n";
	return (cont);
}

void concat(char *a,char *b,char *destino,int tamA,int tamB ){
	int i=0;
	//cout<<"\n\nCOMIENZA A CONCATENAR\n\n";
	for(i=0;i<tamA;i++){
		//cout<<"A ["<<i<<"]\t"<<*a<<" ()\n";
		destino[i]=*a;
		a++;
	}
	for(i=tamA;i<tamA+tamB;i++){ //i comienza en la posicion siguiente a la q terminó en el for anterior, donde terminó en un i<tamA
		//cout<<"B ["<<i<<"]\t"<<*b<<" ()\n";
		destino[i]=*b;
		b++;
	}
	destino[tamA+tamB]='\0'; //agrego el fin de cadena en la ultima posicion
}
	
int main(int argc, char *argv[]) {

	char cad[1000],cad2[1000],destino[2000];
	
	int tamA=0,tamB=0;
		
	do{
		cout<<"\nIngrese el 1er texto (con máximo 100 caracteres)\n";
		fgets(cad,1000,stdin);
		tamA=tamano(cad);
	}while(tamA>100); 
		
	do{
		cout<<"\nIngrese el 2do texto (con máximo 100 caracteres)\n";
		fgets(cad2,1000,stdin);
		tamB=tamano(cad2);
	}while(tamB>100);
	
	concat(cad,cad2,destino,tamA,tamB);
	
	cout<<"\nLa cadena concatenada es: "<<destino;
	cout<<"\nSu tamaño es: "<<tamano(destino)<<"\n";
	
	return 0;
}

