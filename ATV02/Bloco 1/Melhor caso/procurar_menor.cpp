#include <iostream>
#include <vector>

using namespace std;

int procurar_menor(vector<int> v){

int i, menor = v[ 0 ];

    for (i = 0; i < v.size(); i++){
        if ( menor == v[ 0 ] || v[ i ] < menor ){
            menor = v[ i ];
        }
    }

    cout << "Menor valor encontrado: " << menor << endl;
}

int main(){

    vector<int> v(6);
    for (int i = 0; i < 6; i++){
        cout << "Digite um valor: " << endl;
        cin >> v[ i ];
    }

    procurar_menor(v);

    return 0;
}