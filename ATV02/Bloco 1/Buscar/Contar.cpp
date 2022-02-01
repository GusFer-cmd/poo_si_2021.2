#include <iostream>

using namespace std;

int contar( int vet[], int tam ) {

int num;
int qtd = 0, i = 0;

    cout << "Digite um valor que voce desejar verificar se existe na fila: " << endl;
    cin >> num;

    while ( i <= 5) {
        if( num == vet[ i ] ) {
            qtd = qtd + 1;
        }
        i = i + 1;
    }

    cout << "Valor:  \n" << num << endl;
    cout << "Quantidade encontrada: \n" << qtd << endl; 
}

int main()
{
    
int vetX[ 5 ], i;
    
    for (i = 0; i < 5; i++) {
			cout << "Digite um valor: " << endl;
			cin >> vetX[ i ];
		}

    contar( vetX, 5);

return 0;
}