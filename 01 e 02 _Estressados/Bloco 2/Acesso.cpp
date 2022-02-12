#include <iostream>
#include <vector>

using namespace std;

int sorteio(const vector<int>& v){ //Função que recebe como parametro um vetor
    
    int s = rand() % v.size(); //Sorteia
    int num = v[ s ]; //Numero sorteado

    return num;
}

void reverter_inplace(vector<int>& v){ //Função que recebe como parametro um

int j = v.size() - 1, i, aux; //Declaração de variáveis

    for(i = 0; i < v.size() / 2; i++){ //Laço
        aux = v[ i ]; 
        v[ i ] = v[ j ]; //Troca valores
        v[ j ] = aux; //Salva no auxiliar
        j--; //Decrementa
    }
        cout << "Vetor invertido: ";
        
        for(i = 0; i < v.size(); i++){ //Impressão
            cout << v[ i ] << "  ";
        }
}

void ordenar(vector<int>& v){

    int j = 0;
    for(j = 0; j < v.size() - 1; j++){ //Executar o for várias vezes
         
    int i;
    //Percorre o vetor
        for(i = 0; i < v.size() - 1; i++){
            if(v[ i ] > v[ i + 1 ]){ //Caso elemento seja maior realiza a troca
                int aux = v[ i + 1 ];//Armazena no aux para não perder o valor
                v[ i + 1 ] = v[ i ]; //Troca os valores
                v[ i ] = aux; 
            }
        }
    }   
}

void inverte_com_copia(const vector<int>& v){ //Função que recebe como parametro um vetor
int i, j, vetI[ i ]; //Declaração de variáveis

    cout << "Vetor invertido : ";
    for (i = 0, j = 5; i < 6 && j >= 0; i++, j--) { //Laço
        vetI[ i ] = v[ j ]; 
        cout << vetI[ i ] << " ";
    }
}

void embaralhar(vector<int> v) { //Função que recebe como parametro um vetor
    for (int i = 0; i < v.size(); i++) { //Laço
        int j = rand() % v.size(); //Randomiza a posição do vetor
        swap(v[i], v[j]); //Troca os valores 
    }
        for (int i = 0; i < v.size(); i++) { //Impressão
        cout << v[i] << " ";
        }
    cout << endl;
}

int main(){

    vector<int> v(6); //Declaração de vetor
    for(int i = 0; i < v.size(); i++){ //Laço
        cout << "Digite um valor: " << endl;
        cin >> v[ i ]; //Recebe os valores
    }

    int num = sorteio(v); //Chama a função sorteio
    cout << "Numero sorteado: " << num << endl;

    reverter_inplace(v); //Chama a função reverter_inplace
    ordenar(v); //Chama a função ordenar
    inverte_com_copia(v); //Chama a função inverte_com_copia
    embaralhar(v); //Chama a função embaralhar
    
    return 0;
}