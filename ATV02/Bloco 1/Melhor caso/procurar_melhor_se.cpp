#include <iostream>
#include <vector>

using namespace std;

int procurar_melhor_se(vector<int> v, int size){

int i, procura = v[0], pos = 0;

        for (i = 0; i < size; i++) {
            if( v[ i ] < procura && v[ i ] > 0 ) {
                procura = v[ i ];
                pos = i + 1;  
                }
            }
            cout << "O homem menos extressado esta na posicao: " << pos << endl;
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
    
    procurar_melhor_se(v, tam);

    return 0;
}