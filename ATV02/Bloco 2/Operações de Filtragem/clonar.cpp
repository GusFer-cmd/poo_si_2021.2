#include <iostream>
#include <vector>

using namespace std;

vector<int> clonar(const vector<int>& v){
    
vector<int> vClone;
    for (int i = 0; i < v.size(); i++){
        vClone.push_back(v[ i ]);
    }
    return vClone;
}

int main(){

    vector<int> v(6);
    for (int i = 0; i < 6; i++){
        cout << "Digite um valor: " << endl;
        cin >> v[ i ];
    }

    cout << "O vetor clone: " << endl;
    vector<int> vClone = clonar(v);
    for (int i = 0; i < vClone.size(); i++){
        cout << vClone[ i ] << endl;
    }
   
    return 0;
}