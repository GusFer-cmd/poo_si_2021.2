#include <iostream>
#include <vector>

using namespace std;

void reverter_inplace(vector<int>& v){ //Função que recebe como parametro um

int j = v.size() - 1, i, aux; //Declaração de variáveis

    for(i = 0; i < v.size() / 2; i++){ //Laço
        aux = v[ i ]; 
        v[ i ] = v[ j ]; //Troca valores
        v[ j ] = aux; //Salva no auxiliar
        j--; //Decrementa
    }
        cout << "Vetor invertido: ";
        
        for(i = 0; i < v.size(); i++){ //Impressão
            cout << v[ i ] << "  ";
        }
}

int main(){

    vector<int> v(6); //Inicialização do vetor de 6 posições 
    for(int i = 0; i < v.size(); i++){
        cout << "Digite um valor: " << endl;
        cin >> v[ i ]; //Recebe o valor digitado
    }

    reverter_inplace(v); //Chamada da função

    return 0;
}