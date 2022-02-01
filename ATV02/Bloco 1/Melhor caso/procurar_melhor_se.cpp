#include <iostream>

using namespace std;

int procurar_melhor_se ( int vet[], int tam) {

int procura = vet[ 0 ], pos = 0;
int i;

    for (i = 0; i < tam; i++) {
        if( vet[ i ] < procura && vet[ i ] > 0 ) {
            procura = vet[ i ];
            pos = i + 1;  
            }
        }

        cout << " O homem menos extressado esta na posicao: " << pos << endl;
}

int main()
{

int vetX[ 5 ], i;

    for (i = 0; i < 5; i++) {
        cout << "Digite um valor: " << endl;
        cin >> vetX[ i ];
    }

    procurar_melhor_se ( vetX, 5 );

return 0;
}