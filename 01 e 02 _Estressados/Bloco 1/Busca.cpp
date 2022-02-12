#include <iostream>
#include <vector>

using namespace std;


bool existe(vector<int> v, int x) {
    for (int i = 0; i < v.size(); i++) { //Laço 
        if (v[i] == x) { //Se o elemento existir
            return true; //Retorna true
        }
    }
    return false; //Se não existir, retorna false
}

int contar(vector<int> v, int x) {
    int cont = 0; //Inicializa variável
    for (int i = 0; i < v.size(); i++) { //Laço
        if (v[i] == x) { //Se o elemento existir
            cont++; //Incrementa o contador
        }
    }
    return cont; //Retorna o contador
}

int procurar(vector<int> v, int x) {
    for (int i = 0; i < v.size(); i++) { //Laço
        if (v[i] == x) { //Se o elemento existir
            return i; //Retorna o índice
        }
    }
    return -1; //Se não existir, retorna -1
}

int procurar_apartir(vector<int> v, int x, int inicio){
    for (int i = inicio; i < v.size(); i++) { //Laço dado o inicio
        if (v[i] == x) { //Se o elemento existir
            return i; //Retorna o índice
        }
    }
    return -1; //Se não existir, retorna -1
}

int main(){

    vector<int> v(6); //Inicialização do vetor de 6 posições
    for (int i = 0; i < v.size(); i++) { //Laço
        cout << "Digite um valor: " << endl;
        cin >> v[ i ]; //Recebe o valor digitado
    }

    cout << "Existe o elemento? " << existe(v, 2) << endl;
    cout << "Quantos elementos existem? " << contar(v, 2) << endl;
    cout << "A posicao do elemento e: " << procurar(v, 2) << endl;
    cout << "A posicao do elemento e: " << procurar_apartir(v, 2, 2) << endl;

return 0;
}