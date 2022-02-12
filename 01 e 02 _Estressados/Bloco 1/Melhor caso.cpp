#include <iostream>
#include <vector>

using namespace std;

int procurar_menor(vector<int> v){
    int menor = v[0];
    for (int i = 0; i < v.size(); i++){ //Laço
        if (v[i] < menor){ //Condição
            menor = v[i]; //Elemento menor
        }
    }
    return menor; //Retorna o menor elemento
}

int procurar_pos_menor(vector<int> v){
    int menor = v[0];
    int pos = 0;
    for (int i = 0; i < v.size(); i++){ //Laço
        if (v[i] < menor){ //Condição
            menor = v[i]; //Elemento menor
            pos = i; //Posição do menor elemento
        }
    }
    return pos; //Retorna a posição do menor elemento
}

int procurar_pos_menor_apartir(vector<int> v, int inicio){
    int menor = v[inicio];
    int pos = 0;
    for (int i = inicio; i < v.size(); i++){ //Laço
        if (v[i] < menor){ //Condição
            menor = v[i]; //Elemento menor
            pos = i; //Posição do menor elemento
        }
    }
    return pos; //Retorna a posição do menor elemento
}

int procuar_melhor_pos_se(vector<int> v){
    int menor = v[0];
    int pos = 0;
    for (int i = 0; i < v.size(); i++){ //Laço
        if (v[i] < menor && v[i] >= 0){ //Condição (Homem > 0)
            menor = v[i]; //Elemento menor
            pos = i; //Posição do menor elemento
        }
    }
}

int main(){
    vector<int> v(6); //Inicialização do vetor de 6 posições
    for (int i = 0; i < v.size(); i++){
        cout << "Digite um valor: " << endl;
        cin >> v[ i ]; //Recebe o valor digitado
    }
    cout << "O menor elemento e: " << procurar_menor(v) << endl;
    cout << "A posicao do menor elemento e: " << procurar_pos_menor(v) << endl;
    cout << "A posicao do menor elemento e: " << procurar_pos_menor_apartir(v, 2) << endl;
    cout << "A posicao do menor elemento e: " << procuar_melhor_pos_se(v) << endl;

return 0;
}