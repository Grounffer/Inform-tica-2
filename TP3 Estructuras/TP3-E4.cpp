/*EJERCICIO 4 - Intersecci�n de funciones
Se deber�n almacenar los puntos de una funci�n arbitraria: y=f(x), utilizando
un arreglo de �n� estructuras de tipo punto. El arreglo representar� y
contendr� los �n� puntos de la funci�n, tomando un rango para x de -5 a +5
dividido en 100 valores.
El usuario deber� ingresar los par�metros que representen una l�nea en el
plano, una funci�n lineal, los par�metros que ingresa ser�an pendiente y
ordenada al origen.
El programa indicar� al usuario si la l�nea corta o no a la funci�n almacenada y
si lo hace m�s de una vez en el rango de x de -5 a +5*/
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

