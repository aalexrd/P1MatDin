#include <iostream>
using namespace std;
class Metodo{
private:
	int valor;
	int fila;
	int col;
	int **matriz;
public:
	Metodo(int x, int y):fila(x), col(y){
		matriz = new int*[fila];
		if (fila){
			matriz[0] = new int[fila * col];
			for (int i = 1; i < fila; i++)
				matriz[i] = matriz[0] + i * col;
		}
		for (int i=0; i<x;i++)
			for (int j=0; j<x;j++)
				matriz[i][j]=0;
	}
	~Metodo(){
		if (fila) delete [] matriz[0];
        delete [] matriz;
	}
	void setMatriz(int x, int y, int val){
		matriz[x][y]=val; }
	void setX(int x){
		fila=x; }
	void setY(int y){
		col=y; }
	int getMatriz(int x, int y){
		return this->matriz[x][y]; }
	void llenarMatriz(){
		int numero;
		cout<<"Llene la matriz en las posiciones: \n";
		for (int i=0; i<fila;i++){
			for (int j=0; j<col;j++){
				cout<<"["<<i<<"]"<<"["<<j<<"]: ";
				cin>>numero;
				setMatriz(i,j,numero);
				cout<<endl;
			}
		}
	}
	void mostrar(){
		int vector[10]={0};
		for (int i=0; i<fila;i++){
			for (int j=0; j<col;j++){
				int valor=getMatriz(i,j);
				int digitos = log10((float)valor) + 1; //numero de digitos
				for (int k = digitos - 1; k > 0; k--) {
					int divisor = pow((float)10, k);
					int digito = valor / divisor; //extrae un digito
					valor -= digito * divisor; //le quito el digito al valor
					vector[digito]+=1; //guarda cuantas veces esta el digito
				}
				vector[valor]+=1;
			}
		}
		for (int i=0; i<10;i++){
				cout<<i<<"  ";
				if(i==9)
					cout<<endl;
		}
		for (int i=0; i<10;i++){
			cout<<vector[i]<<"  ";
				if(i==9)
					cout<<endl;
		}
		system("pause");
	}
};
