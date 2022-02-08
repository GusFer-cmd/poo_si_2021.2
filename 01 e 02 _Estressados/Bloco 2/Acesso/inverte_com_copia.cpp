#include <iostream>
#include <vector>

using namespace std;

void inverte_com_copia(const vector<int>& v){ //Função que recebe como parametro um vetor
int i, j, vetI[ i ]; //Declaração de variáveis

    cout << "Vetor invertido : ";
    for (i = 0, j = 5; i < 6 && j >= 0; i++, j--) { //Laço
        vetI[ i ] = v[ j ]; 
        cout << vetI[ i ] << " ";
    }
}

int main(){

    vector<int> v(6); //Inicialização do vetor de 6 posições
    for (int i = 0; i < v.size(); i++) {
        cout << "Digite um valor: " << endl;
        cin >> v[ i ]; // Recebe o valor digitado
    }
    
    inverte_com_copia(v); //Chamada da função
    
    return 0;
}