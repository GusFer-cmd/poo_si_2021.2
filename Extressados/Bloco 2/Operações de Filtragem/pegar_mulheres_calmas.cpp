#include <iostream>
#include <vector>

using namespace std;

vector<int> pegar_mulheres_calmas(const vector<int>& v){ //Função que recebe como parametro um vetor
    
int i; //Declaração de variáveis
    for (i = 0; i < v.size(); i++){ //Laço que percorre o vetor
        if (v[ i ] < 0 && v[ i ] >= -10){ //Condição que verifica se o valor da posição do vetor é menor que 0 (mulheres) e maior ou igual a -10 (calmas).
            cout << v[ i ] << endl;
        }
    }
}

int main(){

    vector<int> v(5); //Inicialização do vetor de 5 posições
    for (int i = 0; i < 5; i++){
        cout << "Digite um valor: " << endl;
        cin >> v[ i ]; //Recebe o valor digitado
    }
    cout << " Mulheres calmas: " << endl; 
    pegar_mulheres_calmas(v); //Chamada da função

    return 0;
}