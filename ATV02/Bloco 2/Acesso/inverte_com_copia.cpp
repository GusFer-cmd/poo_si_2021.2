#include <iostream>
using namespace std;

int inverter_com_copia( int vet[], int tam) {

int i, j, vetI[ i ];

        cout << "O vetor invertido: ";
        for (i = 0, j = 5; i < 6 && j >= 0; i++, j--) {
            vetI[ i ] = vet[ j ];
            cout << vetI[ i ] << "  ";
        }
} 

int main()
{

int vetX[ 6 ], vetI[ 6 ], i, j;

    for (i = 0; i < 6; i++) {
        cout << "Digite um valor: " << endl;
        cin >> vetX[ i ];
    }

    inverter_com_copia( vetX, 6);

return 0;
}