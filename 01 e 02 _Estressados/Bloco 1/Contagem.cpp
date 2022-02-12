#include <iostream>
#include <vector>

using namespace std;

float calcular_stress_medio(vector<int> v){
    float media, contador;
    for(int i = 0; i < v.size(); i++){ //Laço
        contador += v[i]; //Soma os elementos do vetor
        media = contador / v.size(); //Divide a soma pelo tamanho do vetor
    }
    return media;
}

string mais_homens_ou_mulheres(vector<int> v){
    int homens = 0;
    int mulheres = 0;
    for(int i = 0; i < v.size(); i++){ //Laço
        if(v[i] >= 0){ //Se o elemento for maior ou igual a 0
            homens++; //Incrementa 
        }
        else{ //Se o elemento for menor que 0
            mulheres++; //Incrementa 
        }
    }
    if(homens > mulheres){ //Se o número de homens for maior que o de mulheres
        return "Homens"; //Retorna "Homens"
    }
    else{ //Se o número de homens for menor que o de mulheres
        return "Mulheres"; //Retorna "Mulheres"
    } 
    if(homens = mulheres){
        return "Empate";
    }
}

string qual_metade_eh_mais_estressada(vector<int> v){
    int metade1 = 0;
    int metade2 = 0;
    for(int i = 0; i < v.size() / 2; i++){ //Laço
        metade1 += v[i]; //Soma os elementos da primeira metade
    }

    for(int i = v.size() / 2; i < v.size(); i++){ //Laço
        metade2 += v[i]; //Soma os elementos da segunda metade
    }

    if(metade1 > metade2){ //Se a primeira metade for maior que a segunda
        return "Primeira metade";
    }
    else{
        return "Segunda metade"; //Se a segunda metade for maior que a primeira
    }
    if(metade1 = metade2){ //Se as duas metades forem iguais
        return "Empate";
    }
}

string homens_sao_mais_estressados_que_mulheres(vector<int> v){
    int homens = 0, mulheres = 0, media1, media2;
    
    for(int i = 0; i < v.size(); i++){ //Laço
        if(v[i] >= 0){ //Se o elemento for maior ou igual a 0
            homens++; //Incrementa 
            media1 = homens / v.size(); //Calcula a média de homens
        }
        else{ //Se o elemento for menor que 0
            mulheres++; //Incrementa 
            media2 = mulheres / v.size(); //Calcula a média de mulheres
        }
    }
    if(media1 > media2){ //Se o número de homens for maior que o de mulheres
        return "Homens"; //Retorna "Homens"
    }
    else{ //Se o número de homens for menor que o de mulheres
        return "Mulheres"; //Retorna "Mulheres"
    } 
    if(media1 = media2){
        return "Empate";
    }
}

int main(){

    vector<int> v(6);
    cout << "Digite os valores do vetor: " << endl;
    for(int i = 0; i < v.size(); i++){
        cout << "Digite um valor: " << endl;
        cin >> v[i];
    }

    cout << "A media do vetor e: " << calcular_stress_medio(v) << endl;
    cout << "O mais estressado e: " << mais_homens_ou_mulheres(v) << endl;
    cout << "A metade mais estressada e: " << qual_metade_eh_mais_estressada(v) << endl;
    cout << "Homens sao mais estressados que mulheres: " << homens_sao_mais_estressados_que_mulheres(v) << endl;

    return 0;
}