#include <iostream>
#include <vector>

using namespace std;

vector<int> procurar_valor_apartir(vector<int>& v){

int i, num, pos = 0, encontrado = 0, contador = 0;

    cout << "Digite um numero que voce deseja procurar: " << endl;
    cin >> num;

    for(i = 0; i < v.size(); i++){
        if(num == v[ i ]){
            encontrado = 1;
            pos = i + 1;
            contador++;
        }
    }

    if(encontrado == 1){
        cout << "Numero " << num << " aparece " << contador << "x no vetor." << " E sua proxima posicao " << pos << endl;
    } else {
        cout << "Numero digitado nao existe " << endl;
    }
}

int main(){

    vector<int> v(6);
    for (int i = 0; i < 6; i++){
        cout << "Digite um valor: " << endl;
        cin >> v[ i ];
    }

    procurar_valor_apartir(v);

    return 0;
}