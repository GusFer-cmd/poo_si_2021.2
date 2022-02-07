#include <iostream>
#include <vector>

using namespace std;

float calcular_stress_medioH(vector<int> v){ //Função que recebe como parametro um vector(Homens).
    
float somaH = 0, mediaH = 0; //Declaração de variáveis
int i;
    for (i = 0; i < v.size(); i++) { //Laço que percorre o vetor
        if (v[ i ] > 0) { //Condição que verifica se o valor da posição do vetor é maior que 0 (homens).
            somaH += v[ i ]; //Soma o valor da posição do vetor
            mediaH = somaH / v.size(); //Media é igual a soma dividido pelo tamanho do vetor
        }
    }
return mediaH;
}

float calcular_stress_medioM(vector<int> v){ //Função que recebe como parametro um vector(Mulheres).

float somaM = 0, mediaM = 0; //Declaração de variáveis
int i;
    for (i = 0; i < v.size(); i++) { //Laço que percorre o vetor
        if (v[ i ] < 0) { //Condição que verifica se o valor da posição do vetor é menor que 0 (mulheres).
            somaM += v[i];  //Soma o valor da posição do vetor
            mediaM = somaM / v.size(); //Media é igual a soma dividido pelo tamanho do vetor
        }
    }
return mediaM;
}

int main(){

    vector<int> v(6); //Inicialização do vetor de 6 posições
    for (int i = 0; i < v.size(); i++) { //Laço que percorre o vetor
        cout << "Digite um valor: " << endl;
        cin >> v[ i ]; //Recebe o valor digitado
    }

    float mediaH = calcular_stress_medioH(v); //Chamada da função
    cout << "A media de stress dos homens: " << mediaH << endl;

    float mediaM = calcular_stress_medioM(v); //Chamada da função
    cout << "A media de stress das mulheres: " << mediaM << endl;

    return 0;
}