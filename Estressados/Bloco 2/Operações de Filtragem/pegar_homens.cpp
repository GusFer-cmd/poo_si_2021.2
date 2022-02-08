#include <iostream>
#include <vector>

using namespace std;

vector<int> pegar_homens(const vector<int>& v){ //Função que recebe como parametro um vetor

int i; //Declaração de variáveis

    for (i = 0; i < v.size(); i++) { //Laço que percorre o vetor
        if (v[ i ] > 0) { //Condição que verifica se o valor da posição do vetor é maior que 0 (homens).
            cout << "Homem: " << v[ i ] << endl;
        }
    }
}

int main(){

    vector<int> v(6); //Inicialização do vetor de 6 posições
    for (int i = 0; i < 6; i++){
        cout << "Digite um valor: " << endl;
        cin >> v[ i ]; //Recebe o valor digitado
    }

    pegar_homens(v); //Chamada da função

    return 0;
}