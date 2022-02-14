#include <iostream>
#include <vector>

using namespace std;

vector<int> diferentes(const vector<int>&v){ //Função que recebe como parametro um

    vector<int> rep {}; //Declaração de variáveis.
    
    bool found = false; //Booleano
    for (int i = 0; i < v.size(); i++){ //Laço "i"
        for (int j = 0; j < rep.size(); j++){ //Laço "j"
            if (v[ i ] == rep[ j ] || v[ i ] * -1 == rep[ j ]){  //(*-1 é o modulo)
                found = true; //Se encontrar o valor, o booleano é true
                break;
            }
        }
        if (found == true){ //Se o booleano for true
            found = false; //Zera o booleano     
        } else {
            if (v[ i ] < 0) { //Condição que verifica se o valor da posição do vetor é menor que 0 (mulheres).
                rep.push_back(v[ i ] * -1); 
            } else {
                rep.push_back(v[ i ]); //Adiciona o valor no vetor
            }
        }
    }
    return rep;
}
 
int main(){

    vector<int> v(5); //Inicialização do vetor de 5 posições
    for (int i = 0; i < v.size(); i++) {
        cout << "Digite um valor: " << endl;
        cin >> v[ i ]; //Recebe o valor digitado
    }
    
    vector<int> rep = diferentes(v); //Chamada da função
    for (int i = 0; i < rep.size(); i++){
        cout << rep[ i ] << endl; //Impressão
    }

    // 1 -2 -2 3 5
    // 1 2 3 5
    return 0;
}