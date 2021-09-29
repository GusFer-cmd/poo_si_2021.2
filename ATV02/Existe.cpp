#include <iostream>
using namespace std;

int set_existe( int x[], int tam, int num) {
    int ex = 0;
    int i;

    for (i = 0; i < num; i++) {
        if (x[i] == num) {
            ex = 1;
        }
    }

return ex;
} 

void set_array( int vetor[], int tam, int num) {

    int i;
    for (i = 0; i < tam; i++) {
        cout << "Digite o elemento do vetor: " << i << endl;
        cin >> vetor[i];
    }
} 

int main(){

    int tam = 0;
    cout << "Digite o tamando da fila: \n";
    cin >> tam; 

    int stress[tam];
    int prest = 0;
    int i; 

set_array(stress, tam, prest);

    for ( i = 0; i < tam; i++) {
        int num = 0;
        cout << "Digite o valor que voce deseja verificar se existe na fila: ";
        cin >> num; 

        prest = set_existe( stress, tam, num);
            if (prest == 1) {
                cout << "Pessoa existente na fila \n" << endl; 
            } 
            else {
                cout << "Pessoa nao existente na fila" << endl;
            }
                break;
    }

}