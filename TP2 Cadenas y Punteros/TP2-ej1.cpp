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
	int t=0;
	
		cout<<"\nIngrese el texto\n";
		fgets(cad,1000,stdin);
		t=tamano(cad);
		
	cout<<"La longitud de la cadena es: "<<t;
	return 0;
}

