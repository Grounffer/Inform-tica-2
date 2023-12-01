/*EJERCICIO 3
Dado el ingreso de una cadena, debe crear un programa donde indique la cantidad de
palabras, dígitos, símbolos especiales (caracteres que no son letras ni números, incluye
los espacios).
Ejemplo:
Ingrese un texto: BZRP Music Sessions #36
Salida del programa
Cantidad de palabras: 4
Dígitos: 2
Caracteres especiales: 4
*/

#include <iostream>
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

int main(int argc, char *argv[]) {
	
	char cad[1000];
	char *i=cad;
	int palabras=0,digitos=0,simbolos=0;
	
	int tamA=0;
	
	do{
		cout<<"\nIngrese el PRIMER TEXTO (con máximo 100 caracteres)\n";
		fgets(cad,1000,stdin);
		tamA=tamano(cad);
	}while(tamA>100);
	
	while(*i!='\0'){
		
		//cout<<"\n estoy en el elemento: "<<*i;
		
		if((*i<'A' or *i>'Z') and (*i<'a' or *i>'z') and (*i<'0' or *i>'9') and (*i!='\n')){
			//cout<<"\nSUMO UN SIMBOLO: "<<*i;
			simbolos++;
		}
		if(*i>='0' and *i<='9'){
			//cout<<"\nSUMO UN DIGITO: "<<*i;
			digitos++;
		}		
	i++;
	}

	cout<<"\nCaracteres especiales: "<<simbolos;
	cout<<"\nDigitos: "<<digitos;

	i=cad; //reinicio el puntero para contar las palabras
	
	//cout<<"\nEl elemento al que apunta i es: "<<*i;

	while(*i!='\0' and *i!='\n'){
		while(*i!='\n' and *i!=' ' and *i!='\0'){
			i++;
		}
		palabras++;
		i++;
	}
	
	cout<<"\nPalabras: "<<palabras;
	
	return 0;
}

