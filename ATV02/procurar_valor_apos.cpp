#include <iostream>
using namespace std;

int main(){

    int vetX[] = {-2, 9, 89, -65, -2, 32};
	int n = sizeof(vetX) / sizeof(vetX[ 0 ]);
	int num, procurar_valor;
    int encontrado = 0;
	int contador = 0;
	
	cout << "Tamanho do vetor: " << n << endl;

    cout << "Digite um numero que voce deseja procurar: " << endl;
	cin >> num;
	
	for (int i = 0; i < n; i++) {
		if (vetX[ i ] == num) {
			encontrado = 1;
			procurar_valor = i;
            contador++;
        }
	}
	        if (encontrado == 0) {
		        cout << "Numero nao existente" << endl;
	        }
	        else {
		        cout << "Numero " << num << " aparece " << contador << "x no vetor." << " Na posicao: " << procurar_valor << endl;
	        }
return 0;
}