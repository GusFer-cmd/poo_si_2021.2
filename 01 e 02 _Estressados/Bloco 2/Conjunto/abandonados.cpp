#include <iostream>
#include <vector>

using namespace std;

vector<int> abandonados(const vector<int>& v){ //Função que recebe como parametro um

vector<int> vJ{}; //Declaração de variáveis, dois vetores.
vector<int> vI{};

bool found = false; //Booleano para verificar se o valor já foi adicionado.
    for(int i = 0; i < v.size(); i++){ //Laço "i"
        for (int j = 0; j < vJ.size(); j++){ //Laço "j"
            if (v[ i ] == vJ[ j ]){ //Se o valor do vetor for igual ao valor do vetor j
                found = true; //Se encontrar o valor, o booleano é true
                vI.push_back(v[i]); //Adiciona o valor no vetor I
                break; //Para o laço
            }
        }
    
        if (found == false){ //Se o booleano for false
            vJ.push_back(v[i]); //Adiciona o valor no vetor J
        } else {
            found = false; //Zera o booleano
        }
    }
    return vI;
}

int main() {

    vector<int> v(7); //Inicialização do vetor de 7 posições
    for (int i = 0; i < v.size(); i++) {
        cout << "Digite um valor: " << endl;
        cin >> v[ i ]; //Recebe o valor digitado
    }

    vector<int> aban = abandonados(v); //Chamada da função
    for (int i = 0; i < aban.size(); i++) { 
        cout << aban[ i ] << endl; //Impressão
    }

    return 0;
}