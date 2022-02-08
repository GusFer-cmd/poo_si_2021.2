#include <iostream>
#include <vector>

using namespace std;

int contar(vector<int> v){ //Função contar que recebe como parametro um vector

int num, qtd = 0; //Declaração de variáveis

    cout << "Digite um valor que voce desejar verificar se existe na fila: " << endl;
    cin >> num;

    for (int i = 0; i < v.size(); i++) { //Laço que percorre o vetor
        if( num == v[ i ] ) { //Condição que verifica se o numero digitado é igual ao numero da posição do vetor
            qtd = qtd + 1; //Incrementa a quantidade de vezes que o numero digitado aparece na fila
        }
    }

    cout << "Valor:  \n" << num << endl;
    cout << "Quantidade encontrada: \n" << qtd << endl;
}

int main(){

    vector<int> v(6); //Inicialização do vetor de 6 posições
    for (int i = 0; i < v.size(); i++){ //Laço que percorre o vetor
        cout << "Digite um valor: " << endl;
        cin >> v[ i ]; //Recebe o valor digitado
    }

    contar(v); //Chamada da função contar

    return 0;
}