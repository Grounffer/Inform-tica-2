/*EJERCICIO 6
	Cree una matriz de caracteres para almacenar N cadenas de longitud M = 150. Ud. debe
	definir el valor tanto para N como para M como constantes en su programa.
	En la matriz debe tener almacenada N cadenas con el siguiente formato:
	- M A R C A - M O D E L O - N ° S E R I E -
	Debe almacenar la marca, modelo y número de serie de algunos productos. Note que
	cada cadena está separada por un guión ( - )
	Ejemplos de algunas cadenas posibles a almacenar:
	“-samsung-s23-44231-”
	“-motorola-G stylus-08977-”
	“-Samsung-S20-S8493874-”
	“-FIAT-Palio-5234523-”
	“-Platinum-Biblioteca tres estantes-BP435-”
	Debe desarrollar un programa que muestre un menú de opciones para buscar datos por
	marca, modelo o número de serie
*/	
#include <conio.h>
#include <iostream>
using namespace std;


int longitud(char *a){
	int cont=0;	
	while(*a!='\0' and *a!='\n' and cont<1000000){
		//cout<<"["<<cont<<"]\t"<<*a<<" ()\n"; //muestra cada elemento que recorre
		cont++;
		a++;
	}
	//cout<<"\nLongitud de la cadena: "<<cont<<"\n";
	return (cont);
}
	
	int busco(char cad1[],char cad2[]){  //busco cad 1 en cad 2
		
		int k=0; //coincidencias, y es el subindice con el que comparo los elementos de las cads
		int i=0,j=0;
		int l1=longitud(cad1);		
		int l2=longitud(cad2);
		
		for (i=0;i<=l2-l1;i++) {
			//cout<<"\nestoy en ["<<i<<"] "<<cad2[i];
			for (j=i,k=0; k<l1 and cad2[j]==cad1[k]; j++, k++){
				//cout<<"\n	comparo: "<<cad2[j]<<" -- "<<cad1[k];
			}
			if (k==l1) return 1;
		}
		return 0;
	}

int main(int argc, char *argv[]) {
	
	const int N=5,M=150;
	char cad[M],cadAux[M];
	int n=0;
	char mat[N][M]={"-samsung-s23-44231-",
					"-motorola-G stylus-08977-",
					"-FIAT-Palio-5234523-",
					"-samsung-S20-S8493874-",
					"-Platinum-Biblioteca tres estantes-BP435-"};
	
	cout<<"\nLista de productos:\n";
	for(int t=0;t<N;t++){
		puts(mat[t]);
	}
	
	cout<<"\nIngrese el nro de accion que desea ralizar:";
	cout<<"\n1)Buscar por Marca";
	cout<<"\n2)Buscar por Modelo";
	cout<<"\n3)Buscar por Numero de serie\n";
	cin>>n; //scanf("%d",&n); 
	getchar(); 
	//cin o scanf solo leen el numero, no el enter(salto de linea), por lo que queda en el búfer de entrada
	//y al llegar a fgets lo toma como entrada y salta a la siguiente linea, al agregar getchar() estoy limpiando el búfer
	
	switch(n){
		case 1:{
			cout<<"\nBuscando por marca\nIngrese la marca que desea buscar: ";
			fgets(cad,150,stdin);
			
			cout<<"\nCoincidencias: \n";
			for(int t=0;t<N;t++){
				
				for(int i=0;i<N and mat[t][i]!='-';i++){
					
				}
				
			if(busco(cad,mat[t])==1) puts(mat[t]);
			}
		break;
		}
	}
	
	return 0;
}

