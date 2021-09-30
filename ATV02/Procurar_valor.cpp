#include <iostream>
using namespace std;

int main(){
	
    int vetX[4] = {-2, 9, 89, -65};
	int num, procurar_valor;
    int encontrado = 0;
	
    cout << "Digite um numero que voce deseja procurar: " << endl;
	cin >> num;
	
	for (int i = 0; i < 4; i++) {
		if (vetX[i] == num){
			encontrado = 1;
			procurar_valor = i;
		}
	}
	
	if (encontrado == 0){
		cout << "Numero nao existente" << endl;
	}
	else{
		cout << "Numero existente na posicao " << procurar_valor << endl;
	}

return 0;
}