#include <iostream>
using namespace std;

int procurar_valor_apartir( int vet[], int tam) {

int i, num;
int Pos = 0, encontrado = 0, contador = 0;

    cout << "Digite um numero que voce deseja procurar: " << endl;
	cin >> num;
	
			for (int i = 0; i < tam; i++) {
				if (vet[ i ] == num) {
					encontrado = 1;
					Pos = i;
            		contador++;
        	}
				}
	        
				if (encontrado == 0) {
		        	cout << "Numero nao existente" << endl;
	        	}
	        	else {
		        	cout << "Numero " << num << " aparece " << contador << "x no vetor." << " E sua proxima posicao: " << Pos << endl;
	       		}
}

int main()
{

int vetX[5];
int  i;
 
	
		for (int i = 0; i < 5; i++) {
			cout << "Digite um valor: " << endl;
			cin >> vetX[i];
		}
	
	procurar_valor_apartir( vetX, 5 );

return 0;
}