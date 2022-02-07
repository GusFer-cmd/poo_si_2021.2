#include <iostream>
#include <vector>

using namespace std;

vector<int> pegar_calmos(const vector<int>& v){

int i;
    for (i = 0; i < v.size(); i++ ) {
        if(v[ i ] > 0 && v[ i ] <= 10)
        cout << v[ i ] << endl;
    }
}

int main(){

    vector<int> v(6);
    for (int i = 0; i < 6; i++){
        cout << "Digite um valor: " << endl;
        cin >> v[ i ];
    }

    cout << " Homens calmos: " << endl;
    pegar_calmos(v);

    return 0;
}