#include <iostream>
using namespace std;

int main(){

    int Array[4] = {80, 2, -70, -8};
    int achei = 0;
    int X, P;

    cin >> X;
        
        for (int i = 0;i < 4; i++){
            if (Array[i] == X){
                achei = 1;
            }
        }

        if (achei == 0){
            cout << "Numero nao encontrado" << endl;
        }
        else{
            cout << "Numero encontrado" << endl;
        }
