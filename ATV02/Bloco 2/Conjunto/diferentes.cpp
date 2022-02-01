#include <iostream>
#include <vector>

using namespace std;

vector<int> diferentes(const vector<int>&v){

    vector<int> rep {};
    bool dif = false;
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < rep.size(); j++){
            if (v[i] == rep[j] || v[i] * -1 == rep[j]){
                dif = true;
                break;
            }
        }
        if (dif == true){
            dif = false;
            continue;    
        } else {
            if (v[i] < 0) {
                rep.push_back(v[i] * -1);
            } else {
                rep.push_back(v[i]);
            }
        }
    }
    return rep;
}
 
int main(){

    vector<int> v(5);
    for (int i = 0; i < v.size(); i++) {
        cout << "Digite um valor: " << endl;
        cin >> v[i];
    }
    
    vector<int> rep = diferentes(v);
    for (int i = 0; i < rep.size(); i++){
        cout << rep[i] << endl;
    }

    return 0;
}