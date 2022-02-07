#include <iostream>
#include <vector>

using namespace std;

bool existe(vector<int> v){

int i, num;
bool encontrado = 0;

    cout << "Digite um valor que voce deseja verificar se existe na fila: " << endl;
    cin >> num;

    for(i = 0; i < v.size(); i++){
        if(num == v[ i ]){
            encontrado = 1;
        }
    }

    if(encontrado == 1){
        cout << "Numero digitado existe na fila " << endl;
    } else {
        cout << "Numero digitado nao existe " << endl;
    }
}

int main(){

    vector<int> v(6);
    for (int i = 0; i < 6; i++){
        cout << "Digite um valor: " << endl;
        cin >> v[ i ];
    }

    existe(v);

    return 0;
}