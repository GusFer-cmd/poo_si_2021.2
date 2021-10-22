#include <iostream>
using namespace std;

struct Pessoa {
    string nome{""};
    int idade{0};

    Pessoa( string nome, int idade) : 
        nome{nome}, idade{idade} {
    }         

    friend ostream& operator<<(ostream& os, const Pessoa& pessoa) {
        os << "Nome: " << pessoa.nome << ", ";
        os << "Idade: " << pessoa.idade << " anos\n";    
    }
}; 

struct Moto {
    int power{1};
    int tempo{0};
    Pessoa* pessoa;
    Moto(int power, int tempo, Pessoa* pessoa = nullptr) : 
        power{power}, tempo{tempo}, pessoa{pessoa} {
    }      

    bool inserirPessoa(Pessoa* pessoa) {
        if(this->pessoa != nullptr) {
            cout << "Ja tem uma crianca\n";
            return false;
        }
        this->pessoa = pessoa;
        return true;
    }

    Pessoa* removerPessoa() {
        if(this->pessoa == nullptr) {
            cout << "Nao tem crianca\n";
            return nullptr;
        }
        Pessoa* pessoa = this->pessoa;
        this->pessoa = nullptr;
        return pessoa; 
    }

    void buy(int tempo) {
        if(this->tempo == 0) {
            cout << "Tempo acabou. Deseja comprar mais tempo?!\n";
        }
    }

    void drive(int tempo) {
        if(this->tempo > 0) {
            cout << "O tempo ainda não acabou, continue a dirigir\n";
        }
    }

    void honk(){
        cout << "Pem\n";
    }
};

int main() {
    Pessoa pessoa ("Gustavo", 7);
    
    Moto moto(3, 5, &pessoa );
    moto.pessoa->idade -= 1;
    
    cout << pessoa.idade << "\n";
    cout << moto.pessoa->idade << "\n";

return 0;
}