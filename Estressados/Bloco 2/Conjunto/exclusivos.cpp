#include <iostream>
#include <vector>

using namespace std;

void exclusivos(const vector<int>& v){ //Função que recebe como parametro um

int i, j; //Declaração de variáveis

    bool exist; //Booleano
    for (i = 0; i < v.size(); i++) { //Laço que percorre o vetor
        exist = false; 
        for (j = 0; j < i; j++) { //Laço que percorre o vetor
            if(v[ i ] == v[ j ]){ //Se o valor do vetor for igual ao valor do vetor j
                exist = true; //Se encontrar o valor, o booleano é true
                break; //Para o laço
            }     
        }    
        if(exist == false) { //Se o booleano for false
            cout << v[ i ] << endl; //Impressão
        }
    }
}

int main(){

    vector<int> v(6); //Inicialização do vetor de 6 posições
    for (int i = 0; i < v.size(); i++) {
        cout << "Digite um valor: ";
        cin >> v[ i ]; //Recebe o valor digitado
    }

    exclusivos(v); //Chamada da função
    // 1 3 4 3 -2 -2 
    // 1 3 4 -2

    return 0;

}