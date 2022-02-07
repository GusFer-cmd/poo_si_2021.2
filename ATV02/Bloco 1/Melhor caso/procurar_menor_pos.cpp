#include <iostream>
#include <vector>

using namespace std;

int procurar_menor_pos ( vector<int> v) {
    int i, posM = 0, menor = v[ 0 ];
    
    for ( i = 0; i < v.size(); i++) {
        if ( v[ i ] < menor){
            menor = v[ i ];
            posM = i + 1;
        }
    }
    
    cout << "O menor valor encontrado: " << menor << " e sua posicao: " << posM << endl;
}

int main(){

    vector<int> v(6);
    for (int i = 0; i < 6; i++){
        cout << "Digite um valor: " << endl;
        cin >> v[ i ];
    }

    procurar_menor_pos(v);

    return 0;
}