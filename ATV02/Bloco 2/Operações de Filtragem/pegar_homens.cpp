#include <iostream>

using namespace std;

int pegar_homens ( int vet[], int tam) {

int i;

    for (i = 0; i < tam; i++) {
        if (vet[ i ] > 0) {
            cout << "Homem: " << vet[ i ] << endl;
        }
    }

}

int main() 
{

int vetX[ 6 ], i;

    for (i = 0; i < 6 ; i++) {
        cout << "Digite um valor: " << endl;
        cin >>vetX[ i ];
    }
    
    pegar_homens(vetX, 6);

return 0;
}