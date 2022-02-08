#include <iostream>
#include <vector>

using namespace std;

int procurar_menor_pos_apartir(vector<int> v){ //Função que recebe como parametro um vector

int i, num, PMPA, encontrado = 0, contador = 0; //Declaração de variáveis

    cout << "Digite um numero que voce deseja procurar: " << endl;
    cin >> num;

        for (i = 0; i < v.size(); i++) { //Laço
            if ( v[ i ] == num) { //Condição que verifica se o valor da posição do vetor é igual ao numero digitado pelo usuario
                encontrado = 1; //Se o valor da posição do vetor for igual ao numero digitado pelo usuario, o valor de encontrado recebe 1
                PMPA = i + 2;
                contador++; //Contador que conta quantas vezes o numero digitado aparece no vetor
            } 
        }

        if(encontrado == 0){ 
            cout << "Numero nao existe: " << endl;
        } else {
            cout << "Numero " << num << " aparece " << contador << " x no vetor." << " E sua proxima posicao: " << PMPA << endl;
        }
}

int main(){

    vector<int> v(6); //Inicialização do vetor de 6 posições
    for(int i = 0; i < v.size(); i++){
        cout << "Digite um valor: " << endl;
        cin >> v[ i ]; //Recebe o valor digitado
    }

    procurar_menor_pos_apartir(v); //Chamada da função

    return 0;
}