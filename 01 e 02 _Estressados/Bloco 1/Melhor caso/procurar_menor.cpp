#include <iostream>
#include <vector>

using namespace std;

int procurar_menor(vector<int> v){ //Função que recebe como parametro um vetor

int i, menor = v[ 0 ]; //Declaração de variáveis

    for (i = 0; i < v.size(); i++){ //Laço
        if ( menor == v[ 0 ] || v[ i ] < menor ){ //Condição
            menor = v[ i ]; //Atribui o menor valor ao elemento i do vetor
        }
    }

    cout << "Menor valor encontrado: " << menor << endl;
}

int main(){

    vector<int> v(6); //Inicialização do vetor de 6 posições
    for (int i = 0; i < v.size(); i++){
        cout << "Digite um valor: " << endl;
        cin >> v[ i ]; //Recebe o valor digitado
    }

    procurar_menor(v); //Chamada da função

    return 0;
}