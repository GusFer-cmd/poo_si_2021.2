#include <iostream>
#include <vector>

using namespace std;

int procurar_valor_apartir(vector<int> v, int pos){ //Função que recebe como parametro um vetor

int i, num, encontrado = 0, contador = 0; //Declaração de variáveis

    cout << "Digite um numero que voce deseja procurar: " << endl;
    cin >> num;

    for(i = pos + 1; i < v.size(); i++){ //Laço
        if(num == v[ i ]){ //verifica se o numero digitado é igual ao numero da posição do vetor
            encontrado = 1; //Se o numero digitado for igual ao numero da posição do vetor, o valor de encontrado recebe 1
            contador++; //Incrementa
        }
    }

    if(encontrado == 1){
        cout << "Numero " << num << " aparece " << contador << "x no vetor." << " E sua proxima posicao " << pos << endl;
    } else {
        cout << "Numero digitado nao existe " << endl;
    }
    return -1;
}

int main(){

    vector<int> v(6); //Inicialização do vetor de 6 posições
    for (int i = 0; i < v.size(); i++){ //Percorre o vetor
        cout << "Digite um valor: " << endl;
        cin >> v[ i ]; //Recebe o valor digitado
    }

    procurar_valor_apartir(v, 1); //Chamada da função

    return 0;
}