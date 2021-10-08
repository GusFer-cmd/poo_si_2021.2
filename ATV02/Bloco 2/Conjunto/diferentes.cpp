#include <iostream>
using namespace std;

int diferentes( int vet[], int tam) {

int i, j;

    bool exist;
    for (i = 0; i < tam; i++) {
        exist = false;
        for (j = 0; j < i; j++) {
            if(vet[i] == vet[j]){
                exist = true;
                break;
            }
                if(vet[i] < 0){ //Laço para verificar os números negativos
                    exist = true;
                    break;
                }     
        }    
        if(exist == false) {
            cout << vet[ i ] << endl;
        }
    }
}

int main()
{

int vetX[ 6 ], i;

    for( i = 0; i < 6; i++) {
        cout << "Digite um valor: ";
        cin >> vetX[i];
    }

    diferentes(vetX, 6);

return 0;
}