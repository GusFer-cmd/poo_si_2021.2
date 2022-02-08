#include <iostream>
#include <vector>

using namespace std;

vector<int> pegar_calmos(const vector<int>& v){ //Função que recebe como parametro um vetor

int i; //Declaração de variáveis
    for (i = 0; i < v.size(); i++ ) { //Laço que percorre o vetor
        if(v[ i ] > 0 && v[ i ] <= 10) 
        cout << v[ i ] << endl; //Impressão
    }
}

int main(){

    vector<int> v(6); //Inicialização do vetor de 6 posições
    for (int i = 0; i < v.size(); i++){ 
        cout << "Digite um valor: " << endl;
        cin >> v[ i ]; //Recebe o valor digitado
    }

    cout << " Homens calmos: " << endl; 
    pegar_calmos(v); //Chamada da função

    return 0;
}