#include <iostream>
#include <vector>

using namespace std;

float calcular_stress_medioH(vector<float> v, int size){
    
float somaH = 0;
int i;
    for (i = 0; i < size; i++) {
        if (v[i] > 0) {
            somaH += v[i];
        }
    }
return somaH / size;
}

float calcular_stress_medioM(vector<float> v, int size){

float somaM = 0;
int i;
    for (i = 0; i < size; i++) {
        if (v[i] < 0) {
            somaM += v[i];
        }
    }
return somaM / size;
}

int main(){

    int tam = 0;
    cout << "Digite o tamanho do vetor: " << endl;
    cin >> tam;

    vector<float> v{};
    int a;

    for (int i = 0; i < tam; i++) {
        cout << "Digite um valor: " << endl;
        cin >> a;
        v.push_back(a);
    }

    float mediaH = calcular_stress_medioH(v, tam);
    cout << "A media de stress dos homens: " << mediaH << endl;

    float mediaM = calcular_stress_medioM(v, tam);
    cout << "A media de stress das mulheres: " << mediaM << endl;

    return 0;
}