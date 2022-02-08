#include <iostream>
#include <vector>

using namespace std;

bool existe(vector<int> v){ //Booleando existir 

int i, num; //Declaração de variáveis
bool encontrado = 0;

    cout << "Digite um valor que voce deseja verificar se existe na fila: " << endl;
    cin >> num;

    for(i = 0; i < v.size(); i++){ //Laço que percorre o vetor
        if(num == v[ i ]){ //Condição que verifica se o numero digitado é igual ao numero da posição do vetor
            encontrado = 1; //Se o numero digitado for igual ao numero da posição do vetor, o valor de encontrado recebe 1
        }
    }

    if(encontrado == 1){
        cout << "Numero digitado existe na fila " << endl;
    } else {
        cout << "Numero digitado nao existe " << endl;
    }
}

int main(){

    vector<int> v(6); //Inicialização do vetor de 6 posições
    for (int i = 0; i < v.size(); i++){ //Percorre o vetor
        cout << "Digite um valor: " << endl;
        cin >> v[ i ]; //Recebe o valor digitado
    }

    existe(v); //Chamada da função existe

    return 0;
}