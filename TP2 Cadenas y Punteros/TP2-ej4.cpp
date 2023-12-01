/*EJERCICIO 4
	Debe imprimir una cadena al revés usando punteros. Es
	decir, debe ordenar los caracteres de una cadena de forma decreciente usando
	punteros.
	Ejemplo:
	Ingrese un texto: zapato
	La cadena al revés es: ztpoaa
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
	
	char pal[1000],aux;
	
	//DECLARO LOS PUNTEROS i Y j
	char *i=pal; //es como decir i=0 , pal[i]=pal[0] apunta al primer elemento
	char *j=&pal[1]; //tambien se puede hacer asi char *j=pal+1; //apunta al segundo elemento de pal 
	
	int tama=0;
	
	do{
		cout<<"\nIngrese el PRIMER TEXTO (con máximo 100 caracteres)\n";
		fgets(pal,1000,stdin);
		tama=tamano(pal);
	}while(tama>100);
	
	cout<<"\nEl tamano es: "<<tama<<"\n";
	//cout<<"\nCadena Ingresada: "<<pal<<"\n";
	
	//ORDENAMIENTO
	
	while(*i!='\0' /*and *i!=' ' and *i!='\n'*/){ //mientras el contenido a lo q apunta i no sea fin de cadena
		
		//cout<<"\nLa cadena queda: "<<pal<<"\n";
		
		while(*j!='\0'){
			//cout<<"\nEstoy en\ni: "<<*i;
			//cout<<"\nj: "<<*j<<"\n";
			if(*j>*i){
				aux=*j;
				*j=*i;
				*i=aux;
				//cout<<"INTERCAMBIO "<<*i<<" con "<<*j<<"\n";;
			}
		j++;
		}
	j=i+1; //declaro j como la posicion de i pero aumentado
	i++;
	}
	
	cout<<"\nRESULTADO: "<<pal;
	
	return 0;
}

