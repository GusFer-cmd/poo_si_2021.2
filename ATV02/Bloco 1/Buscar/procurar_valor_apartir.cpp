#include <iostream>
#include <vector>

using namespace std;

int procurar_valor_apartir(vector<int> v, int size){

int i, num, Pos = 0, encontrado = 0, contador = 0;

    cout << "Digite um numero que voce deseja procurar: " << endl;
    cin >> num;

        for(i = 0; i < size; i++){
            if(num == v[i]){
                encontrado = 1;
                Pos = i + 1;
                contador++;
            }
        }

        if(encontrado == 0){
            cout << "Numero nao existente" << endl;
        } else {
            cout << "Numero " << num << " aparece " << contador << "x no vetor." << " E sua proxima posicao " << Pos << endl;
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

    procurar_valor_apartir(v, tam);

    return 0;
}