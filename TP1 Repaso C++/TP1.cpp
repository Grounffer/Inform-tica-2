#include <math.h>
#include <iostream>
using namespace std;

void llenarVec(int vec[],int n){
	for(int i=0;i<n;i++){
		cout<<"Ingrese ["<<i<<"]: ";
		cin>>vec[i];
}}
void mostrarVec(int vec[],int n){
	cout<<"\nLos elementos del vector son:\n";
	for(int i=0;i<n;i++){
		cout<<vec[i]<<" ";
}}
void llenarMat(int mat[10][10],int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		cout<<"Ingrese ["<<i<<"]["<<j<<"]: ";
		cin>>mat[i][j];
}}}
void mostrarMat(int mat[10][10],int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<mat[i][j]<<"\t";
		}
		cout<<"\n";
}}
void suma(int a[10][10],int b[10][10],int n,int m){
	int resultado[10][10];
	cout<<"\nMatriz resultado:\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			resultado[i][j]=a[i][j]+b[i][j];
			cout<<resultado[i][j]<<"\t";
	}cout<<"\n";
}}
void resta(int a[10][10],int b[10][10],int n,int m){
	int resultado[10][10];
	cout<<"\nMatriz resultado:\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			resultado[i][j]=a[i][j]-b[i][j];
			cout<<resultado[i][j]<<"\t";
		}cout<<"\n";
}}
void producto(int a[10][10],int vec[10],int fila,int col){
	int resultado[10][10];
	cout<<"\nMatriz resultado:\n";	
	for(int i=0;i<fila;i++){
		for(int j=0;j<col;j++){
			resultado[i][j]=a[i][0]*vec[j];
			cout<<resultado[i][j]<<"\t";
		}cout<<"\n";
}}
	
int main(int argc, char *argv[]) {
	int Acol=0,Afila=0,Bcol=0,Bfila=0,tam=0,a[10][10],b[10][10],c[10],n=0,norma=0;
	do{
		cout<<"\n\nIngrese el nro de accion que desea realizar: ";
		cout<<"\n1)Ingresar la matriz A";
		cout<<"\n2)Ingresar la matriz B";
		cout<<"\n3)Ingresar un vector";
		cout<<"\n4)Sumar/restar las matrices";
		cout<<"\n5)Multiplicar una matriz con el vector";
		cout<<"\n6)Calcular la norma del vector";
		cout<<"\n7) salir\n\n";
		cin>>n;
		
		switch(n){
		
		case 1:
			
			do{
			cout<<"\nfilas? (Debe ser un valor del 1 al 10)\n";
			cin>>Afila;
			}while(Afila<1 or Afila>10);
			do{
				cout<<"\nNro de Columnas? (Debe ser un valor del 1 al 10)\n";
				cin>>Acol;
			}while(Acol<1 or Acol>10);
			cout<<"\n";
			llenarMat(a,Afila,Acol);
			cout<<"\nMatriz A: \n\n";
			mostrarMat(a,Afila,Acol);
			break;
			
		case 2:
			
			do{
			cout<<"\nfilas? (Debe ser un valor del 1 al 10)\n";
			cin>>Bfila;
			}while(Bfila<1 or Bfila>10);
			do{
				cout<<"\nColumnas? (Debe ser un valor del 1 al 10)\n ";
				cin>>Bcol;
			}while(Bcol<1 or Bcol>10);
			cout<<"\n";
			llenarMat(b,Bfila,Bcol);
			cout<<"\nMatriz B: \n\n";
			mostrarMat(b,Bfila,Bcol);
			break;
			
		case 3:
			do{
			cout<<"\nIngrese el tamaño de su vector (Debe ser un valor del 1 al 10)\n";
			cin>>tam;
			}while(tam<1 or tam>10);
			llenarVec(c,tam);
			mostrarVec(c,tam);			
			break;
			
		case 4:
			if((Acol==Bcol) and (Afila==Bfila)){
				do{
					cout<<"\nQue desea hacer?\n";
					cout<<"\n1)Matriz A + Matriz B";
					cout<<"\n2)Matriz A - Matriz B";
					cout<<"\n3)Matriz B - Matriz A";
					cout<<"\n4)Salir\n\n";
					cin>>n;
					switch(n){
						case 1: suma(a,b,Acol,Afila); break;
						case 2: resta(a,b,Acol,Afila); break;
						case 3: resta(b,a,Acol,Afila); break;
						default: {if(n!=4)cout<<"\nError: Debe ingresar un valor del 1 al 4\n";}
					}
				}while(n!=4);
			}else{
				cout<<"\nError: Para sumar o restar matrices deben ser de igual dimension\n";
			}
		break;
		
		case 5:
				do{
					cout<<"\nQue desea hacer?\n";
					cout<<"\n1)Matriz A x Vector";
					cout<<"\n2)Matriz B x Vector";
					cout<<"\n3)Salir\n\n";
					cin>>n;
					switch(n){
					case 1: 
						if(Acol==1)producto(a,c,Afila,tam); 
						else {cout<<"\nError: Debe ingresar una matriz y un vector, la matriz debe tener 1 columna\n";
								n=3;}
					break;
					case 2: if(Bcol==1)producto(b,c,Bfila,tam);
						else {cout<<"\nError: Debe ingresar una matriz y un vector, la matriz debe tener 1 columna\n";
								n=3;}
					break;
					default: {if(n!=3)cout<<"\nError: Debe ingresar un valor del 1 al 3\n";}
					}
				}while(n!=3);
		break;
		
		case 6:
			if(tam>0){
			for(int i=0;i<tam;i++){
				norma+=c[i]*c[i];
			}
			cout<<"\nLa Norma del vector es: "<<sqrt(norma)<<"\n";
			}else{cout<<"\nError: Debe ingresar un vector valido\n";}
		break;
		
		default:
			if(n!=7) cout<<"\nError: Debe ingresar un valor del 1 al 7\n";
		}
		
	}while(n!=7);
	
	
	return 0;
}


