#include <iostream>
#include <vector>

using namespace std;

int procurar_valor(vector<int> v){ //Função que recebe como parametro um vetor

int i, num, pos = 0, encontrado = 0; //Declaração de variáveis

    cout << "Digite um numero que voce deseja procurar: " << endl;
    cin >> num;

    for(i = 0; i < v.size(); i++){ //Laço que percorre o vetor
        if(num == v[ i ]){ //Condição que verifica se o numero digitado é igual ao numero da posição do vetor
            encontrado = 1; //Se o numero digitado for igual ao numero da posição do vetor, o valor de encontrado recebe 1
            pos = i + 1; //A posição do numero digitado é igual ao numero da posição do vetor mais 1 (Só pra ficar bonito)
        }
    }

    if(encontrado == 1){
        cout << "Numero existente aparece na posicao " << pos << endl;
    } else {
        cout << "Numero nao existente" << endl;
        return -1;
    }
}

int main(){

    vector<int> v(6); //Inicialização do vetor de 6 posições
    for (int i = 0; i < v.size(); i++){ //Percorre o vetor
        cout << "Digite um valor: " << endl;
        cin >> v[ i ]; //Recebe o valor digitado
    }

    procurar_valor(v); //Chamada da função

    return 0;
}