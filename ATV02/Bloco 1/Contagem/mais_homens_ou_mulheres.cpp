#include <iostream>
#include <vector>

using namespace std;

char mais_homem_ou_mulher(vector<int> v){

int i, homem = 0, mulher = 0, empate = 0;

    for (i = 0; i < v.size(); i++) {
        if ( v[i] > 0) {
            homem++;
        } else if ( v[i] < 0) {
            mulher++;
        }
            if ( homem > mulher ) {
                return 'H';
            } else if ( homem < mulher) {
                return 'M';
            } else if ( homem == empate ) {
                return 'E';
            }
    }
}

float calcular_stress_medio(vector<int> v){

    float soma = 0, media = 0;
    int i;

    for ( i = 0; i < v.size(); i++ ) {
        soma += v[ i ];
        media = soma / v.size();
    }
    return media;
}

int main(){

    vector<int> v(6);
    for (int i = 0; i < 6; i++){
        cout << "Digite um valor: " << endl;
        cin >> v[ i ];
    }

    float media = calcular_stress_medio(v);
    cout << "A media de stress: " << media << endl; 

    char HM = mais_homem_ou_mulher(v);
    cout << "Na fila existe mais: " << HM << endl;

return 0;
}