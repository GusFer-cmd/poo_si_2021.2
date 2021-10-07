#include <iostream>
using namespace std;

int sortear(int vet[], int tam) {

int i; 

    for (i = 0; i < tam; i++) {
        srand(vet[ i ]);
        cout << "Sorteio: " << rand()%tam << endl;
    }
}

int main() 
{

int vetX[ 6 ], i;

    for (i = 0; i < 6; i++) {
        cout << "Digite um valor: " << endl;
        cin >> vetX[ i ];
    }

    sortear(vetX, 6);

return 0;
}