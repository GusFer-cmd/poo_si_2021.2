#include <iostream> 
#include <cstdlib>
using namespace std;

int embaralhar( int vet[], int tam) {

int i, j, aux;

    cout << "O vetor embaralhado: ";

    for (i = 0; i < tam; i++) {
        j = rand() % tam;
        aux = vet[ i ];
        vet[ i ] = vet [ j ];
        vet[ j ] = aux;
        cout << vet[ j ] << "  ";
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