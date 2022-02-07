#include <iostream>
#include <vector>

using namespace std;

char mais_homem_ou_mulher(vector<int> v, int size){

int i, homem = 0, mulher = 0, empate = 0;

    for (i = 0; i < size; i++) {
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

float calcular_stress_medio(vector<int> v, int size){

float soma = 0;
int i;

    for ( i = 0; i < size; i++ ) {
        soma += v[ i ];
    }
    
return soma / size;
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

    float media = calcular_stress_medio(v, tam);
    cout << "A media de stress: " << media << endl; 

    char HM = mais_homem_ou_mulher(v, tam);
    cout << "Na fila existe mais: " << HM << endl;

return 0;
}