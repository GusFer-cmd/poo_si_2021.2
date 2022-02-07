#include <iostream>
#include <vector>

using namespace std;

void exclusivos(vector<int>& v){

int i, j;

    bool exist;
    for (i = 0; i < v.size(); i++) {
        exist = false;
        for (j = 0; j < i; j++) {
            if(v[i] == v[j]){
                exist = true;
                break;
            }     
        }    
        if(exist == false) {
            cout << v[ i ] << endl;
        }
    }
}

int main(){

    vector<int> v(6);
    for (int i = 0; i < v.size(); i++) {
        cout << "Digite um valor: ";
        cin >> v[ i ];
    }

    exclusivos(v);
    // 1 3 4 3 -2 -2 
    // 1 3 4 -2

    return 0;

}