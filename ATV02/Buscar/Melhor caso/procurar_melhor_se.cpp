#include <iostream>
using namespace std;

int main()
{

int vetX[ 5 ];
int procurar_melhor_se = vetX[ 0 ];
int  i, pos = 0;

    for (i=0; i<5; i++){
        cout << "Digite um valor: " << endl;
        cin >> vetX[i];
    }

        for (i = 0; i < 5; i++) {
            if( vetX[ i ] < procurar_melhor_se && vetX[ i ] > 0 ) {
                procurar_melhor_se = vetX[ i ];
                pos = i;  
            }
        }

        cout << " O homem menos extressado esta na posicao: " << pos << endl;
                
return 0;
}