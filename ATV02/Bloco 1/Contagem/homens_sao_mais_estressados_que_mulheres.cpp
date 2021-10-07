#include <iostream> 
#include <iomanip>
using namespace std;

float calcular_stress_medioH( int vet[], int tam) {

float somaH = 0; 
int i;
    
    for ( i = 0; i < tam; i++ ) {
        if ( vet[ i ] > 0) {
            somaH += vet[ i ];  
        }
    }
    
    return somaH / tam;
}

float calcular_stress_medioM( int vet[], int tam) {

float somaM = 0;
int i;
    
    for ( i = 0; i < tam; i++ ) {
        if ( vet[i] < 0) {
            somaM += vet[ i ];
        }   
    }
    
return somaM / tam;
}

int main()
{

int vetX[ 6 ], i;
float mediaH; 
float mediaM; 

    for ( i = 0; i < 6; i++ ) {
    cout << "Digite um valor: " << endl; 
    cin >> vetX[ i ];
    }
    
    mediaH = calcular_stress_medioH(vetX, 6);
    cout << "A media de stress dos homens: " << mediaH << endl; 

    mediaH = calcular_stress_medioM(vetX, 6);
    cout << setprecision(2);
    cout << "A media de stress das mulheres: " << mediaM << endl; 

return 0;
}