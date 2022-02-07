#include <iostream>
#include <vector>

using namespace std;

int procurar_menor_pos ( vector<int> v, int size ) {
    int i, posM = 0, menor = -1;
    
    for ( i = 0; i < size; i++) {
        if ( v[ i ] < menor){
            menor = v[ i ];
            posM = i + 1;
        }
    }
    
    cout << "O menor valor encontrado: " << menor << " e sua posicao: " << posM << endl;
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
    
    procurar_menor_pos( v, tam );

    return 0;
}