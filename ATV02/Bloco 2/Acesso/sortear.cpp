#include <iostream> 
#include <cstdlib>
#include <vector>

using namespace std;

int sorteio(const vector<int>& v){ //Função que recebe como parametro um vetor
    
    int s = rand() % v.size(); //Sorteia
    int num = v[ s ]; //Numero sorteado

    return num;
} 

int main() {

    vector<int> v(5); //Inicialização do vetor de 5 posições
    for(int i = 0; i < v.size(); i++) {
        cout << "Digite um valor: " << endl;
        cin >> v[ i ]; //Recebe o valor digitado
    }

    int num = sorteio(v); //Chamada da função
    cout << "O numero sorteado foi: " << num << endl;  //Impressão

}