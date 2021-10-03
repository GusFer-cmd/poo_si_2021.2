#include <iostream>
using namespace std;

int main()
{

    int tamanho;
    cout << "Digite a quantidade de elementos da fila: " << endl;
    cin >> tamanho;

    int vetX[ tamanho ];

    int i {};
    while ( i < tamanho){
        cout <<  "Digite o elemento do vetor " << i << ":" << endl;
        cin >> vetX[ i ];
        i = i + 1;
    }

    int numero;
    cout << "Digite um valor que voce desejar verificar se existe na fila: " << endl;
    cin >> numero;

    int qtd {};

    i = 0;
    while ( i < tamanho){
        if( numero == vetX[ i ] ){
            qtd = qtd + 1;
        }
        i = i + 1;
    }

    cout << "Valor:  \n" << numero << endl;
    cout << "Quantidade encontrada: \n" << qtd << endl; 

return 0;
}