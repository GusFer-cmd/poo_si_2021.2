#include <iostream>
#include <vector>

using namespace std;

int ordenar(vector<int>& v){

int i;

    for(i = 0; i < v.size() - 1; i++) {
        if(v[ i ] > v[ i + 1 ] ) {
            int aux = v[ i + 1 ]; //Auxiliar recebe o valor do vetor[ i + 1 ], (guardando o elemento.)
            v[ i + 1 ] = v[ i ];
            v[ i ] = aux;
        }
    }  
}

int main(){

    vector<int> v(3);
    for (int i = 0; i < 3; i++) {
        cout << "Digite um valor: " << endl;
        cin >> v[i];
    }
    
    ordenar(v);
    for (int i = 0; i < 3; i++) {
        cout << v[i] << " ";
    }
    
    return 0;

}