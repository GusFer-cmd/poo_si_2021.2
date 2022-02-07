#include <iostream>
#include <vector>

using namespace std;

char mais_homem_ou_mulher(vector<int> v){ //Função que recebe como parametro um vector

int i, homem = 0, mulher = 0, empate = 0; //Declaração de variáveis

    for (i = 0; i < v.size(); i++) { //Laço que percorre o vetor
        if ( v[i] > 0) { //Condição que verifica se o valor da posição do vetor é maior que 0 (homens).
            homem++; //Incremeta homens
        } else if ( v[i] < 0) { //Condição que verifica se o valor da posição do vetor é menor que 0 (mulheres).
            mulher++; //Incremeta mulheres
        }
            if ( homem > mulher ) { //Casos
                return 'H';
            } else if ( homem < mulher) {
                return 'M';
            } else if ( homem == empate ) {
                return 'E';
            }
    }
}

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

    float media = calcular_stress_medio(v); //Chamada da função
    cout << "A media de stress: " << media << endl; 

    char HM = mais_homem_ou_mulher(v); //Chamada da função
    cout << "Na fila existe mais: " << HM << endl;

return 0;
}