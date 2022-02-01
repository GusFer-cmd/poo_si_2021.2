#include <iostream>

using namespace std;

int procurar_menor_pos_apartir ( int vet[], int tam) {

int i, num, PMPA;
int encontrado = 0, contador = 0;
    
    cout << "Digite um numero que voce deseja procurar: " << endl;
    cin >> num;

        for (i = 0; i < tam; i++) {
            if ( vet[ i ] == num) {
                encontrado = 1;
                PMPA = i;
                contador++;
            }
        }        
                if (encontrado == 0 ) {
                    cout << "Numero nao existe: " << endl;
                }
                else {
                    cout << "Numero " << num << " aparece " << contador << " x no vetor." << " E sua proxima posicao: " << PMPA << endl;
                }
}

int main()
{

int vetX[ 5 ], i;
   
    for (i = 0; i < 5; i++) {
        cout << "Digite um valor: " << endl;
        cin >> vetX[i];
    }

    procurar_menor_pos_apartir( vetX, 5);

return 0;
}