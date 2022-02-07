#include <iostream> 
#include <cstdlib>
#include <vector>

using namespace std;

void embaralhar(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        int j = rand() % v.size();
        swap(v[i], v[j]);
    }
        for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
        }
    cout << endl;
}
  
int main() 
{
    vector<int> v(5);
    for (int i = 0; i < 5; i++) {
        cout << "Digite um valor: " << endl;
        cin >> v[i];
    }
    
    embaralhar(v);

    return 0;
}