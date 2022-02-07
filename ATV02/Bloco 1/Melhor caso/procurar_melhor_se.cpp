#include <iostream>
#include <vector>

using namespace std;

int procurar_melhor_se(vector<int> v){ //Função que recebe como parametro um vetor

int i, procura = v[ 0 ], pos = 0; //Declaração de variáveis

        for (i = 0; i < v.size(); i++) { //Laço que percorre o vetor
            if( v[ i ] < procura && v[ i ] > 0 ) { 
                procura = v[ i ]; 
                pos = i + 1; //A posição do numero digitado é igual ao numero da posição do vetor mais 1 (Só pra ficar bonito)
                }
            }
            cout << "O homem menos extressado esta na posicao: " << pos << endl;
}

int main(){

    vector<int> v(6); //Inicialização do vetor de 6 posições
    for (int i = 0; i < v.size(); i++){
        cout << "Digite um valor: " << endl;
        cin >> v[ i ]; //Recebe o valor digitado
    }
    
    procurar_melhor_se(v); //Chamada da função

    return 0;
}