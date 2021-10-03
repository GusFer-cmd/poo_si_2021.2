#include <iostream>
using namespace std;

int main()
{
    int vetX[5];
    int menor = vetX[ 0 ], i;

    for (i = 0; i < 5; i++){
        cout << "Digite um valor: " << endl;
        cin >> vetX[i]; 
    }
          
          for (i = 0; i < 5; i++){
              if ( vetX[i] < menor ){
                  menor = vetX[i];
              }
          }
    
    cout << "Menor valor encontrado: " << menor << endl;

return 0;
}