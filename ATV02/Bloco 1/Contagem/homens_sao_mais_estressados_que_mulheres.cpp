#include <iostream>
#include <vector>

using namespace std;

float calcular_stress_medioH(vector<int> v){
    
float somaH = 0, mediaH = 0;
int i;
    for (i = 0; i < v.size(); i++) {
        if (v[i] > 0) {
            somaH += v[i];
            mediaH = somaH / v.size();
        }
    }
return mediaH;
}

float calcular_stress_medioM(vector<int> v){

float somaM = 0, mediaM = 0;
int i;
    for (i = 0; i < v.size(); i++) {
        if (v[ i ] < 0) {
            somaM += v[i];
            mediaM = somaM / v.size();
        }
    }
return mediaM;
}

int main(){

    vector<int> v(6);
    for (int i = 0; i < 6; i++){
        cout << "Digite um valor: " << endl;
        cin >> v[ i ];
    }

    float mediaH = calcular_stress_medioH(v);
    cout << "A media de stress dos homens: " << mediaH << endl;

    float mediaM = calcular_stress_medioM(v);
    cout << "A media de stress das mulheres: " << mediaM << endl;

    return 0;
}