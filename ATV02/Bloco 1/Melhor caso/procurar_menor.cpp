#include <iostream>
#include <vector>

using namespace std;

int procurar_menor(vector<int> v, int size){

int i, menor = -1;

    for (i = 0; i < size; i++){
        if ( menor == -1 || v[ i ] < menor ){
            menor = v[ i ];
        }
    }

    cout << "Menor valor encontrado: " << menor << endl;
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

    procurar_menor(v, tam);

    return 0;
}