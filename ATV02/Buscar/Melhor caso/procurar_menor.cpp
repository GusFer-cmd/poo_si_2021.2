#include <iostream>
using namespace std;

int procurar_menor ( int vet[], int tam) {

int i, menor = vet[ 0 ];

    for (i = 0; i < 5; i++){
              if ( vet[ i ] < menor ){
                  menor = vet[ i ];
              }
          }

    cout << "Menor valor encontrado: " << menor << endl;
}

int main()
{
    int vetX[5], i;

    for (i = 0; i < 5; i++){
        cout << "Digite um valor: " << endl;
        cin >> vetX[i]; 
    }

    procurar_menor( vetX, 5 );          

return 0;
}