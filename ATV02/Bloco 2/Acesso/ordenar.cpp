#include <iostream>

using namespace std;

void ordenar( int vet[], int tam) {

int i;

    for(i = 0; i < tam - 1; i++) {
        if(vet[ i ] > vet[ i + 1 ] ) {
            int aux = vet[ i + 1 ];
            vet[ i + 1 ] = vet[ i ];
            vet[ i ] = aux;
        }
    }  
}

void imprimir( int vet[], int tam) {
    
int i;  

    cout << "Vetor ordenado: "; 
    for(i = 0; i < tam; i++) {
        cout << vet[ i ] << "  ";
    }
}

int main()
{

int vetX[ 3 ], i;

    for(i = 0; i < 3; i++) {
        cout << "Digite um valor: " << endl;
        cin >> vetX[ i ];
    }

    ordenar(vetX, 3);
    imprimir(vetX, 3);

return 0;
}