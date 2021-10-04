#include <iostream>
using namespace std; 

int procurar_menor_pos ( int vet[], int tam ) {
int i, posM = 0;
int menor = vet[ 0 ];
        
        for ( i = 0; i < tam; i++) {
            if ( vet[ i ] < menor){
                menor = vet[ i ];
                posM = i;
            }
        }
    
        cout << "O menor valor encontrado: " << menor << " e sua posicao: " << posM << endl;
}

int main(){

int vetX[ 4 ], i;

    for ( i = 0; i < 4; i++) {
        cout << "Digite um valor" << endl;
        cin >> vetX[i];
    }

    procurar_menor_pos( vetX, 4 );

    return 0;
}