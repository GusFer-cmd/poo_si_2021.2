#include <iostream>
using namespace std;

int main()
{

    int tamanho;
    cout << "Digite a quantidade de elementos do vetor: " << endl;
    cin >> tamanho;

    int array[ tamanho ];

    int i = 0;
    while ( i < tamanho){
        cout <<  "Digite o elemento do vetor " << i << ":" << endl;
        cin >> array[ i ];
        i = i + 1;
    }

    int numero;
    cout << "Digite um numero: " << endl;
    cin >> numero;

    int qtd = 0;

    i = 0;
    while ( i < tamanho){
        if( numero == array[ i ] ){
            qtd = qtd + 1;
        }
        i = i + 1;
    }

    cout << "Numero:  \n" << numero << endl;
    cout << "Quantidade encontrada: \n" << qtd << endl; 
}