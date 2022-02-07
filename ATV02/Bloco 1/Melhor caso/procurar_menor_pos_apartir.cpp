#include <iostream>
#include <vector>

using namespace std;

int procurar_menor_pos_apartir(vector<int> v){

int i, num, PMPA, encontrado = 0, contador = 0;

    cout << "Digite um numero que voce deseja procurar: " << endl;
    cin >> num;

        for (i = 0; i < v.size(); i++) {
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

    vector<int> v(6);
    for(int i = 0; i < 6; i++){
        cout << "Digite um valor: " << endl;
        cin >> v[ i ];
    }

    procurar_menor_pos_apartir(v);

    return 0;
}