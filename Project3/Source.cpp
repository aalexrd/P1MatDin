#include "Header.h"
int main(){
	cout<<"Digite las dimensiones de la matriz\nx: ";
	int x;
	cin>>x;
	cout<<"\ny: ";
	int y;
	cin>>y;
	Metodo m(x,y);
	m.llenarMatriz();
	m.mostrar();
	return 0;
}