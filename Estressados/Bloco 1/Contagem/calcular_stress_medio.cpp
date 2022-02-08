#include <iostream>
#include <vector>

using namespace std;

float calcular_stress_medio(vector<int> v){ //Função que recebe como parametro um vector

    float soma = 0, media = 0; //Declaração de variáveis
    int i;

    for ( i = 0; i < v.size(); i++ ) { //Laço que percorre o vetor
        soma += v[ i ]; //Soma o valor da posição do vetor
        media = soma / v.size(); //Media é igual a soma dividido pelo tamanho do vetor
    }
    return media;
}

int main(){

    vector<int> v(6); //Inicialização do vetor de 6 posições
    for (int i = 0; i < v.size(); i++){ //Laço que percorre o vetor
        cout << "Digite um valor: " << endl;
        cin >> v[ i ]; //Recebe o valor digitado
    }

    cout << "A media de stress: " << calcular_stress_medio(v) << endl; //Chamada da função

    return 0;
}