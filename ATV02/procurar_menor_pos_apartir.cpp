#include <iostream>
using namespace std;

int main()
{

int vetX[5];
int encontrado = 0, contador = 0;
int i, num, procurar_menor_pos_apos;
    
    for (i = 0; i < 5; i++) {
        cout << "Digite um valor: " << endl;
        cin >>vetX[i];
    }


    cout << "Digite um numero que voce deseja procurar: " << endl;
    cin >> num;

        for (i = 0; i < 5; i++) {
            if ( vetX[i] == num) {
                encontrado = 1;
                procurar_menor_pos_apos = i;
                contador++;
            }
        }
        
                if (encontrado == 0 ) {
                    cout << "Numero nao existe: " << endl;
                }
                else {
                    cout << "Numero " << num << " aparece " << contador << " x no vetor." << " E sua proxima posicao: " << procurar_menor_pos_apos << endl;
                }

    return 0;
}