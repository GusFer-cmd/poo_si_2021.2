#include <iostream>
using namespace std;

int main()
{

int vetX[4];
int menor = vetX[0], i, posM = 0;

    for ( i = 0; i < 4; i++) {
    cout << "Digite um valor" << endl;
    cin >> vetX[i];
    }

        for ( i = 0; i < 4; i++) {
            if ( vetX[i] < menor){
                menor = vetX[i];
                posM = i;
            }
        }

    cout << "O menor valor encontrado: " << menor << " e sua posicao: " << posM << endl;

return 0;
}