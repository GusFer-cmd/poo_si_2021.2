#include <iostream>
#include <vector>

using namespace std;

int contar(vector<int> v, int size){

int num;
int qtd = 0, i = 0;

    cout << "Digite um valor que voce desejar verificar se existe na fila: " << endl;
    cin >> num;

    while ( i <= size) {
        if( num == v[ i ] ) {
            qtd = qtd + 1;
        }
        i = i + 1;
    }

    cout << "Valor:  \n" << num << endl;
    cout << "Quantidade encontrada: \n" << qtd << endl;
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
    
    contar(v, tam);

    return 0;
}