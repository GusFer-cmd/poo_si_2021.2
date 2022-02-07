#include <iostream>
#include <vector>

using namespace std;

int procurar_valor(vector<int> v){

int i, num, pos = 0, encontrado = 0;

    cout << "Digite um numero que voce deseja procurar: " << endl;
    cin >> num;

    for(i = 0; i < v.size(); i++){
        if(num == v[ i ]){
            encontrado = 1;
            pos = i + 1;
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

    vector<int> v(6);
    for (int i = 0; i < 6; i++){
        cout << "Digite um valor: " << endl;
        cin >> v[ i ];
    }

    procurar_valor(v);

    return 0;
}