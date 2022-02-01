#include <iostream> 

using namespace std;

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

int vetX[ 5 ], i;
float media; 

    for ( i = 0; i < 5; i++ ) {
    cout << "Digite um valor: " << endl; 
    cin >> vetX[ i ];
    }
    
    media = calcular_stress_medio(vetX, 5);
    cout << "A media de stress: " << media << endl; 

return 0;
}