#include <iostream>
using namespace std;

int main()
{

    int vetX[5];
	int  i, num, procurar_valor_apartir;
    int encontrado = 0, contador = 0;
	
		for (int i = 0; i < 5; i++) {
			cout << "Digite um valor: " << endl;
			cin >> vetX[i];
		}
	
	cout << "Digite um numero que voce deseja procurar: " << endl;
	cin >> num;
	
			for (int i = 0; i < 5; i++) {
				if (vetX[ i ] == num) {
					encontrado = 1;
					procurar_valor_apartir = i;
            		contador++;
        	}
				}
	        
				if (encontrado == 0) {
		        	cout << "Numero nao existente" << endl;
	        	}
	        	else {
		        	cout << "Numero " << num << " aparece " << contador << "x no vetor." << " E sua proxima posicao: " << procurar_valor_apartir << endl;
	       		}

return 0;
}