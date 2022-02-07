#include <iostream>
#include <vector>

using namespace std;

void ordenar(vector<int>& v){

    int j = 0;
    for(j = 0; j < v.size() - 1; j++){ //Executar o for várias vezes
         
    int i;
    //Percorre o vetor
        for(i = 0; i < v.size() - 1; i++){
            if(v[ i ] > v[ i + 1 ]){ //Caso elemento seja maior realiza a troca
                int aux = v[ i + 1 ];//Armazena no aux para não perder o valor
                v[ i + 1 ] = v[ i ]; //Troca os valores
                v[ i ] = aux; 
            }
        }
    }   
}

int main(){

    vector<int> v(5);
    for (int i = 0; i < v.size(); i++) { //Laço
        cout << "Digite um valor: " << endl;
        cin >> v[ i ]; //Recebe o valor digitado
    }

    cout << "Vetor ordenado: ";
    ordenar(v); //Chamada da função
    for (int i = 0; i < v.size(); i++) { //Impressão
        cout << v[ i ] << " "; 
    }
    
    return 0;
}