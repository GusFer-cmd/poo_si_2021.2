#include <iostream>
#include <vector>

using namespace std;

vector<int> abandonados(const vector<int>& v){

vector<int> vJ{};
vector<int> vI{};

bool found = false;
    for(int i = 0; i < v.size(); i++){
        for (int j = 0; j < vJ.size(); j++){
            if (v[ i ] == vJ[ j ]){
                found = true;
                vI.push_back(v[i]);
                break;
            }
        }
    
        if (found == true){
            found = false;
        } else{
            vJ.push_back(v[i]);
        }
    }
    return vI;
}

int main() {

    vector<int> v(7);
    for (int i = 0; i < v.size(); i++) {
        cout << "Digite um valor: " << endl;
        cin >> v[ i ];
    }

    vector<int> aban = abandonados(v);
    for (int i = 0; i < aban.size(); i++) {
        cout << aban[ i ] << endl;
    }
}