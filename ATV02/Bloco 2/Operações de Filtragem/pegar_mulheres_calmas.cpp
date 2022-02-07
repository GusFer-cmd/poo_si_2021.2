#include <iostream>
#include <vector>

using namespace std;

int pegar_mulheres_calmas(vector<int>& v){
    
int i;
    for (i = 0; i < v.size(); i++){
        if (v[ i ] < 0 && v[ i ] >= -10){
            cout << v[ i ] << endl;
        }
    }
}

int main(){

    vector<int> v(5);
    for (int i = 0; i < 5; i++){
        cout << "Digite um valor: " << endl;
        cin >> v[ i ];
    }
    cout << " Mulheres calmas: " << endl;
    pegar_mulheres_calmas(v);

    return 0;
}