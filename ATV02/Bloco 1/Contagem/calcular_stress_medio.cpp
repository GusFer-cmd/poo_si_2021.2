#include <iostream>
#include <vector>

using namespace std;

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

    cout << "A media de stress: " << calcular_stress_medio(v) << endl;

    return 0;
}