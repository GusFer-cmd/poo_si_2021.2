#include <iostream> 
#include <cstdlib>
using namespace std;

int embaralhar( int vet[], int tam) {

int i, aux;

    for (i = 0; i < 3; i++) {
        aux = vet[ i ];
        vet[ i ] = vet[5 - i];
        vet[ 5 - 1 ] = aux;
    }
        for (i = 0; i < tam; i++) {
            cout << vet[ i ] << "  ";
        }
}
  
int main() 
{

int vetX[ 6 ], i;

    for (i = 0; i < 6; i++) {
        cout << "Digite um valor: " << endl;
        cin >> vetX[ i ];
    }

    embaralhar(vetX, 6);

return 0;
}