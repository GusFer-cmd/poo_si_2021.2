#include <iostream>
#include <vector>

using namespace std;

int procurar_menor_pos_apartir(vector<int> v, int size){

int i, num, PMPA, encontrado = 0, contador = 0;

    cout << "Digite um numero que voce deseja procurar: " << endl;
    cin >> num;

        for (i = 0; i < size; i++) {
            if ( v[ i ] == num) {
                encontrado = 1;
                PMPA = i + 2;
                contador++;
            } 
        }

        if(encontrado == 0){
            cout << "Numero nao existe: " << endl;
        } else {
            cout << "Numero " << num << " aparece " << contador << " x no vetor." << " E sua proxima posicao: " << PMPA << endl;
        }
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

    procurar_menor_pos_apartir(v, tam);

    return 0;
}