#include <iostream>
#include <vector>

using namespace std;

vector<int> clonar(const vector<int>& v){ //Função que recebe como parametro um vetor
    
vector<int> vClone; //Declaração de variáveis
    for (int i = 0; i < v.size(); i++){ //Laço que percorre o vetor
        vClone.push_back(v[ i ]); //Adiciona o valor no vetor
    }
    return vClone;
}

int main(){

    vector<int> v(6); //Inicialização do vetor de 6 posições
    for (int i = 0; i < v.size(); i++){
        cout << "Digite um valor: " << endl;
        cin >> v[ i ]; //Recebe o valor digitado
    }

    cout << "O vetor clone: " << endl;
    vector<int> vClone = clonar(v); //Chamada da função
    for (int i = 0; i < vClone.size(); i++){ 
        cout << vClone[ i ] << " "; //Impressão
    }
   
    return 0;
}