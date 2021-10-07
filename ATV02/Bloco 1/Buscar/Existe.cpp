#include <iostream>
using namespace std;

int existe ( int vet[], int tam) {

int i, num, ex = 0;

    cout << "Digite um valor que voce deseja verificar se existe na fila: " << endl;
    cin >> num;

    for (i = 0; i < tam; i++) {
        if ( num == vet[ i ] ) {
            ex = 1;
        }
    }
            if( ex == 1) {
                cout << "Numero digitado existe na fila " << endl;
            }
            else {
                cout << "Numero digitado nao existe " << endl;
            }
} 

int main ()
{

int vetX[ 5 ], i;

    for (i = 0; i < 5; i++) {
		    cout << "Digite um valor: " << endl;
			cin >> vetX[ i ];
	}
        
        existe ( vetX, 5);

return 0;
}