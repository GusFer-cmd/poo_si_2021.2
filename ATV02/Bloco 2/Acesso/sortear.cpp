#include <iostream>
#include <cstdlib>
using namespace std;

int sortear(int vet[], int tam) {

int i; 

    cout << "Sorteio: ";
    for (i = 0; i < tam; i++) {
        srand(vet[ i ]);
    }
    cout << rand() % tam << "  ";
}

int main() 
{

int vetX[ 6 ] = { 68, 23, -80, -2, 5, -10};

    sortear(vetX, 6);

return 0;
}