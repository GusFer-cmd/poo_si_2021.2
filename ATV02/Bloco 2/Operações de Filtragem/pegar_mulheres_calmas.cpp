#include <iostream>

using namespace std;

int pegar_mulheres_calmas ( int vet[], int tam) {

int i;

    for (i = 0; i < tam; i++ ) {
        if(vet[ i ] < 0 && vet[ i ] >= - 10)
        cout << vet[ i ] << endl;
    }
} 

int main() 
{

int vetX[ 6 ], i;

    for (i = 0; i < 6; i++) {
        cout << "Digite um valor: " << endl;
        cin >> vetX[ i ];
    }

    cout << " Mulheres calmas: " << endl;
    pegar_mulheres_calmas(vetX, 6);

return 0;
}