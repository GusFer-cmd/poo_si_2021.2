#include <iostream> 
#include <cstdlib>
#include <vector>

using namespace std;

int sorteio(const vector<int>& v) {
    int tam = v.size();
    int s = rand() % tam;

    int num = v[s];

    return num;
} 

int main() {

    vector<int> v(5);
    for(int i = 0; i < v.size(); i++) {
        cout << "Digite um valor: " << endl;
        cin >> v[i];
    }

    int num = sorteio(v);
    cout << "O numero sorteado foi: " << num << endl; 

}