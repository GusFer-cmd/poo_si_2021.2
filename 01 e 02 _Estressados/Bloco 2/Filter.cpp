#include <iostream>
#include <vector>

using namespace std;

vector<int> clonar(const vector<int>& v){
    vector<int> vClone{}; //Declara um vetorClone.
    for (int i = 0; i < v.size(); i++) { //Laço
        vClone.push_back(v[i]); //Adiciona o valor no vetor
    }
    return vClone; //Retorna o vetor
}

vector<int> pegar_homens(const vector<int>& v){
    vector<int> homens{}; //Declara um vetor homens.
    for (int i = 0; i < v.size(); i++) { //Laço
        if (v[i] > 0) { //Condição
            homens.push_back(v[i]); //Adiciona o valor no vetor
        }
    }
    return homens; //Retorna o vetor
}

vector<int> pegar_calmos( const vector<int>& v){
    vector<int> calmos{}; //Declara um vetor calmos.
    for (int i = 0; i < v.size(); i++) { //Laço
        if (v[i] > 0 && v[i] <= 10) { //Condição
            calmos.push_back(v[i]); //Adiciona o valor no vetor
        }
    }
    return calmos; //Retorna o vetor
}

vector<int> pegar_mulheres_calmas(const vector<int>& v){
    vector<int> mulheres_calmas{}; //Declara um vetor mulheres_calmas.
    for (int i = 0; i < v.size(); i++) { //Laço
        if (v[i] < 0 && v[i] >= -10) { //Condição
            mulheres_calmas.push_back(v[i]); //Adiciona o valor no vetor
        }
    }
    return mulheres_calmas; //Retorna o vetor
}

int main(){

    vector<int> v(6); //Inicialização do vetor de 6 posições
    for (int i = 0; i < 6; i++){
        cout << "Digite um valor: " << endl;
        cin >> v[ i ]; //Recebe o valor digitado
    }

    vector<int> vClone = clonar(v); //Chama a função clonar e atribui o retorno ao vetor vClone.
    vector<int> homens = pegar_homens(v); //Chama a função pegar_homens e atribui o retorno ao vetor homens.
    vector<int> calmos = pegar_calmos(v); //Chama a função pegar_calmos e atribui o retorno ao vetor calmos.
    vector<int> mulheres_calmas = pegar_mulheres_calmas(v); //Chama a função pegar_mulheres_calmas e atribui o retorno ao vetor mulheres_calmas.

    return 0;
}