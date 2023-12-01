/*EJERCICIO 5
Cree una matriz de caracteres para almacenar N cadenas de longitud M. Ud. debe definir
el valor tanto para N como para M como constantes en su programa.
El programa debe permitir el ingreso por teclado de las N cadenas y almacenarlas en la
matriz.
Luego el programa debe mostrar para cada cadena:
? Su longitud (use la función creada en el ejercicio 1)
? Indicar cuál es la cadena de menor longitud y cuál la de menor longitud
? Indicar cuál es la cadena que tiene mayor cantidad de caracteres especiales.
*/
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

	int caracteres(char *i){
	
		//cout<<"\nLcadena enviada a la funcion es:"<<i<<" \n";
		int cont=0;
		
		while(*i!='\0'){
			//cout<<"\n estoy en el elemento: "<<*i;
			if((*i<'A' or *i>'Z') and (*i<'a' or *i>'z') and (*i<'0' or *i>'9') and (*i!='\n')){
				//cout<<"\nSUMO UN SIMBOLO: "<<*i;
				cont++;
			}
			i++;
		}
		return cont;
	}
	
	int main(int argc, char *argv[]) {
		
		const int N=4,M=100;
		int t=0; 	//subindice que uso para recorrer las cadenas
		int E=0; 	//subindice de la cadena con mas caracteres especiales
		int L=0; 	//subindice de la cadena con mayor longitud
		int l=0; 	//subindice de la cadena con menor longitud
		int tam=0,esp=0;
		char mat[N][M];
		
		for(t=0;t<N;t++){
			cout<<"Ingrese la cadena nro "<<t<<" : ";
			fgets(mat[t],100,stdin);
		}
		
		for(t=0;t<N;t++){
			
			cout<<"\nCADENA "<<t;
			tam=longitud(mat[t]);
			esp=caracteres(mat[t]); //cantidad de caracteres especiales de la matriz con subindice t
			
			cout<<"\nLongitud: "<<tam;
			cout<<"\nCaracteres especiales: "<<esp<<endl;
			if(tam<longitud(mat[l])) l=t;
			if(tam>longitud(mat[L])) L=t;
			if(esp>caracteres(mat[E])) E=t;
		}		
		
		cout<<"\nLa cadena con menor longitud es la nro: "<<l;
		cout<<"\nLa cadena con mayor longitud es la nro: "<<L;
		cout<<"\nLa cadena con mas caracteres especiales es la nro: "<<E;
		
		return 0;
	}
	
	
