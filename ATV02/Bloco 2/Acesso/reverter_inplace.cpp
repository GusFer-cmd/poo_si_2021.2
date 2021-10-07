# include <iostream>
using namespace std;

int reverter_inplace( int vet[], int tam ) {

int j = tam-1, i, aux;

    for ( i = 0; i < tam/2; i++ ) {
        aux = vet[ i ];
        vet[ i ] = vet[ j ];
        vet[ j ] = aux;
        j--;
    }
        cout << "Vetor invertido: ";
        
        for ( i = 0; i < tam; i++) {
            cout << vet[ i ] << "  ";
        }

} 

int main()
{

int vetX[ 6 ], i;

    for ( i = 0; i < 6; i++) {
        cout << "Digite um valor: " << endl;
        cin >> vetX[ i ];    
    }

    reverter_inplace( vetX, 6);

return 0;
}