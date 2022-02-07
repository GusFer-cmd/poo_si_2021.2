#include <iostream>
#include <vector>

using namespace std;

int existe(vector<int> v, int size){

int i, num, encontrado = 0;

    cout << "Digite um valor que voce deseja verificar se existe na fila: " << endl;
    cin >> num;

    for(i = 0; i < size; i++){
        if(num == v[i]){
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
    
        int tam = 0;
        cout << "Digite o tamanho do vetor: " << endl;
        cin >> tam;
    
        vector<int> v{};
        int a;
    
        for(int i = 0; i < tam; i++){
            cout << "Digite um valor: " << endl;
            cin >> a;
            v.push_back(a);
        }
    
        existe(v, tam);
    
        return 0;



}