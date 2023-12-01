#include <iostream>
using namespace std;

class Cadena{
private:
public:
	int flongitud(char *A) {
		int longitud = 0;
		while (*A != '\0') {
			longitud++;
			A++;
		}
		return longitud;
	}
	void concatenar(char cadena1[], char cadena2[], char cadena3[]){
		int i, j;
		int longitud1 = flongitud(cadena1);
		int longitud2 = flongitud(cadena2);
		for(i=0; i<longitud1; i++){
			cadena3[i]=cadena1[i];
		};
		for(j=0; j<longitud2; j++){
			cadena3[j+longitud1]=cadena2[j];
		};
	}
	void copiar(char cadena1[], char cadena2[]){
		int i;
		int longitud1 = flongitud(cadena1);
		for(i=0; i<longitud1; i++){
			cadena2[i]=cadena1[i];
		};
	}
	void especiales(char A[]){
		char *pA=A;
		int palabras=0, digitos=0, especial=0, i=0;
		while(*pA!='\0'){
			if(*pA!=' ' and *pA!='\0' and i==0){
				palabras=1;
				i=1;
			}
			if(*pA==' ' and (*(pA-1)!=' ' and (*(pA+1)!='\0' and *(pA+1)!=' ')) and i==1){
				palabras++;
			}
			else if(*pA>='0' and *pA<='9'){
				digitos++;
			}
			else if((*pA<'A' or *pA>'Z') and (*pA<'a' or *pA>'z') and *pA!=' '){
				especial++;
			}
			if(*pA == ' ' and *pA!='\0'){
				especial++;
			}
			pA++;
		}
		printf("Cantidad de palabras: %d\n", palabras);
		printf("Cantidad de digitos: %d\n", digitos);
		printf("Cantidad de caracteres especiales: %d\n", especial);
	}
	void espejar(char A[]){
		int i, n;
		char aux;
		char *pA=A;
		n=flongitud(A);
		for(i=0; i<n; i++){
			while(*pA!='\0'){
				if(*pA<*(pA+1)){
					aux=*pA;
					*pA=*(pA+1);
					*(pA+1)=aux;
				}
				pA++;
			}
			pA=A;
		}
		fputs(A, stdout);
	}
	Cadena(){
		cout<<"Se ha creado un objeto\n";
	}
};

int main() {
	Cadena miCadena;
	char cadena1[] = "Hola";
	char cadena2[] = " Mundo";
	char cadena3[50];
	char cadena4[50];
	miCadena.especiales(cadena2);
	cout<< "Longitud de cadena 1: "<<miCadena.flongitud(cadena1) << endl;
	miCadena.copiar(cadena1, cadena4);
	cout<< "Cadena copiada: " << cadena4 << endl;
	miCadena.concatenar(cadena1, cadena2, cadena3);
	cout << "Cadena concatenada: " << cadena3 << endl;
	miCadena.espejar(cadena1);
}

