#include <iostream>
using namespace std;

int procurar_valor( int vet[], int tam) {

int i, num, PV = 0, encontrado = 0;

    cout << "Digite um numero que voce deseja procurar: " << endl;
	cin >> num;

    for (int i = 0; i < tam; i++) {
		if (vet[ i ] == num) {
			encontrado = 1;
			PV = i;
		}
	}
			if (encontrado == 0) {
		        cout << "Numero nao existente" << endl;
	        }
	        else {
		        cout << "Numero existente na posicao " << procurar_valor << endl;
	        }
}

int main()
{
	
	int vetX[ 4 ], i;
 
	for ( i = 0; i < 4; i++) {
        cout << "Digite um valor" << endl;
        cin >> vetX[ i ];
    }

	procurar_valor( vetX, 4 );
	
return 0;
}