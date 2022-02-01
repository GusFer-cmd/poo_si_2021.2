#include <iostream>

using namespace std;

char mais_homem_ou_mulher(int vet[], int tam) {

int homem = 0, mulher = 0, empate = 0;
int i;
    
    for (i = 0; i < tam; i++) {
        if ( vet[i] > 0) {
            homem++;
        } 
        else if ( vet[i] < 0) {
            mulher++;
        }

            if ( homem > mulher ) {
                return 'H';
            } 
            else if ( homem < mulher) {
                return 'M';
            } 
            else if ( homem == empate ) {
                return 'E';
            }
    }
} 

float calcular_stress_medio( int vet[], int tam) {

float soma = 0; 
int i;
    
    for ( i = 0; i < tam; i++ ) {
        soma += vet[ i ];
    }
    return soma / tam;
}

int main()
{

int vetX[ 6 ], i;
float media;

    for (i = 0; i < 6; i++) {
    cout << "Insira um valor: " << endl;
    cin >> vetX[i];
    }

    media = calcular_stress_medio(vetX, 6);
    cout << "A media de stress: " << media << endl; 

    char HM = mais_homem_ou_mulher(vetX, 6);
    cout << "Na fila existe mais: " << HM << endl;

return 0;
}