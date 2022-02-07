#include <iostream>
#include <vector>

using namespace std;

int procurar_melhor_se(vector<int> v){

int i, procura = v[ 0 ], pos = 0;

        for (i = 0; i < v.size(); i++) {
            if( v[ i ] < procura && v[ i ] > 0 ) {
                procura = v[ i ];
                pos = i + 1;  
                }
            }
            cout << "O homem menos extressado esta na posicao: " << pos << endl;
}

int main(){

    vector<int> v(6);
    for (int i = 0; i < 6; i++){
        cout << "Digite um valor: " << endl;
        cin >> v[ i ];
    }
    
    procurar_melhor_se(v);

    return 0;
}