/*EJERCICIO 4 - Intersección de funciones
Se deberán almacenar los puntos de una función arbitraria: y=f(x), utilizando
un arreglo de “n” estructuras de tipo punto. El arreglo representará y
contendrá los “n” puntos de la función, tomando un rango para x de -5 a +5
dividido en 100 valores.
El usuario deberá ingresar los parámetros que representen una línea en el
plano, una función lineal, los parámetros que ingresa serían pendiente y
ordenada al origen.
El programa indicará al usuario si la línea corta o no a la función almacenada y
si lo hace más de una vez en el rango de x de -5 a +5*/
#include <iostream>
using namespace std;

const int n=3; 

struct PUNTOS {
	float x=0;
	float y=0;
}punto[n];

int main(int argc, char *argv[]) {
	float m,c;
	//la funcion sera y=x^(2)
	//punto[]={x,y};
	punto[0]={0,0};
	punto[1]={2,4};
	punto[2]={-1,1};
	cout<<"Ingrese el valor de la pendiente: ";
	cin>>m;
	cout<<"\nIngrese el valor de la Ord al origen: ";
	cin>>c;
	for(int i=0;i<3;i++){
		if(punto[i].y==m*(punto[i].x)+c)cout<<"\nIntersecta en x="<<punto[i].x<<" y en y="<<punto[i].y;
	}
	
	return 0;
}

