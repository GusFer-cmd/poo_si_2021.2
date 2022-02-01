#include <iostream>

using namespace std;

int clonar(int vet[], int tam, int vetClone[]) {

int i;

    cout << "O vetor clone: ";

    for (i = 0; i < tam; i++) {
        vetClone[ i ] = vet[ i ];
        cout << vetClone[ i ] << "  ";
    }
}

int main()
{

int vetX[ 6 ], vetClonado[ 6 ], i;

    for (i = 0; i < 6; i++) {
        cout << "Digite um valor: " << endl;
        cin >> vetX[ i ];
    }   

    clonar(vetX, 6, vetClonado);

return 0;
}