#include <iostream>
#include <vector>

using namespace std;

int procurar_menor_pos ( vector<int> v) { //Função que recebe como parametro um vetor
    int i, posM = 0, menor = v[ 0 ]; //Declaração de variáveis
    
    for ( i = 0; i < v.size(); i++) { //Laço
        if ( v[ i ] < menor){ //Condição
            menor = v[ i ]; //Atribui o menor valor ao elemento i do vetor
            posM = i + 1; //Posição
        }
    }
    
    cout << "O menor valor encontrado: " << menor << " e sua posicao: " << posM << endl;
}

int main(){

    vector<int> v(6); //Inicialização do vetor de 6 posições
    for (int i = 0; i < v.size(); i++){
        cout << "Digite um valor: " << endl;
        cin >> v[ i ]; //Recebe o valor digitado
    }

    procurar_menor_pos(v); //Chamada da função

    return 0;
}