#include <iostream> 
#include <cstdlib>
#include <vector>

using namespace std;

void embaralhar(vector<int>&v) {
    for (int i = 0; i < v.size(); i++) {
        int j = rand() % v.size();
        swap(v[i], v[j]);
    }
}
  
int main() 
{
    vector<int> v(10);
    for (int i = 0; i < v.size(); i++) {
        cout << "Digite um valor: " << endl;
        cin >> v[i];
    }
    
    embaralhar(v);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}