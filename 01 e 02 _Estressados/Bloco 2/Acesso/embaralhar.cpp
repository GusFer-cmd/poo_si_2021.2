#include <iostream> 
#include <cstdlib>
#include <vector>

using namespace std;

void embaralhar(vector<int> v) { //Função que recebe como parametro um vetor
    for (int i = 0; i < v.size(); i++) { //Laço
        int j = rand() % v.size(); //Randomiza a posição do vetor
        swap(v[i], v[j]); //Troca os valores 
    }
        for (int i = 0; i < v.size(); i++) { //Impressão
        cout << v[i] << " ";
        }
    cout << endl;
}
  
int main() 
{
    vector<int> v(5); //Inicialização do vetor de 5 posições
    for (int i = 0; i < v.size(); i++) {
        cout << "Digite um valor: " << endl;
        cin >> v[i]; //Recebe o valor digitado
    }
    
    embaralhar(v); //Chamada da função

    return 0;
}