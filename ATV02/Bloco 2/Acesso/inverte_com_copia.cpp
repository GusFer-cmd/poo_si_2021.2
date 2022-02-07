#include <iostream>
#include <vector>

using namespace std;

int inverte_com_copia(vector<int> v, int size){
int i, j, vetI[ i ];

    cout << "Vetor invertido : ";
    for (i = 0, j = 5; i < 6 && j >= 0; i++, j--) {
        vetI[ i ] = v[ j ];
        cout << vetI[ i ] << " ";
    }
}

int main(){

    vector<int> v(6);
    for (int i = 0; i < v.size(); i++) {
        cout << "Digite um valor: " << endl;
        cin >> v[ i ];
    }
    
    inverte_com_copia(v, 6);
    
    return 0;
}