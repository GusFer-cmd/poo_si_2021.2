#include <iostream>
#include <vector>

using namespace std;

void reverter_inplace(vector<int>& v){

int j = v.size() - 1, i, aux;

    for(i = 0; i < v.size()/2; i++){
        aux = v[ i ];
        v[ i ] = v[ j ];
        v[ j ] = aux;
        j--;
    }
        cout << "Vetor invertido: ";
        
        for(i = 0; i < v.size(); i++){
            cout << v[ i ] << "  ";
        }
}

int main(){

    vector<int> v(6);
    for(int i = 0; i < v.size(); i++){
        cout << "Digite um valor: " << endl;
        cin >> v[ i ];
    }

    reverter_inplace(v);

    return 0;
}