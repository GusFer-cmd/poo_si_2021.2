#include <iostream>
#include <vector>

using namespace std;

float calcular_stress_medio(vector<float> v, int size){

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

    vector<float> v{};
    int a;

    for(int i = 0; i < tam; i++){
    cout << "Digite um valor: " << endl;
    cin >> a;
    v.push_back(a);
    }
    
    cout << "A media de stress: " << calcular_stress_medio(v, tam) << endl;

    return 0;
}