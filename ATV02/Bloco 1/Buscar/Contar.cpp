#include <iostream>
#include <vector>

using namespace std;

vector<int> contar(vector<int>& v){

int num, qtd = 0, i = 0;

    cout << "Digite um valor que voce desejar verificar se existe na fila: " << endl;
    cin >> num;

    while ( i <= v.size() ) {
        if( num == v[ i ] ) {
            qtd = qtd + 1;
        }
        i = i + 1;
    }

    cout << "Valor:  \n" << num << endl;
    cout << "Quantidade encontrada: \n" << qtd << endl;
}

int main(){

    vector<int> v(6);
    for (int i = 0; i < 6; i++){
        cout << "Digite um valor: " << endl;
        cin >> v[ i ];
    }

    contar(v);

    return 0;
}