#include <iostream>
#include <algorithm>
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

void mostrar( Pessoa& pessoa ) {
        cout << pessoa.nome << " tem " << pessoa.idade << " anos " << endl; 
    }

struct Moto {
    int power{1};
    int tempo{0};
    Pessoa* pessoa;
    Moto(int power, int tempo, Pessoa* pessoa = nullptr) : 
        power{power}, tempo{tempo}, pessoa{pessoa} {
    }      

    friend ostream& operator<<(ostream& os, const Moto& moto) {
        os << "Potencia: " << moto.power << " \n";
        os << "Tempo: " << moto.tempo << " anos\n";    
    }

    bool inserirPessoa(Pessoa* pessoa) {
        if(this->pessoa != nullptr) {
            cout << "Ja tem uma crianca na motoca.\n";
            return false;
        }
        this->pessoa = pessoa;
        return true;
    }

    Pessoa* removerPessoa() {
        if(this->pessoa == nullptr) {
            cout << "Nao tem crianca.\n";
            return nullptr;
        }
        return exchange(this->pessoa, nullptr);
    }

    void buy(int tempo) {
        if(this->tempo == 0) {
            cout << "Tempo acabou. Compre mais tempo!\n";
        } else {
            this->tempo += tempo;
            cout << "Tempo adicionado com sucesso!\n";
        }   
        
        cout << this->tempo << " minutos\n"; 
    }

    void drive(int tempo) {
        if(this->tempo > 0) {
            cout << "O tempo ainda nao acabou, continue a dirigir!\n";
        }
    }

    void honk(){
        if (this->power == 0) {
            cout << "Pem\n";
        } else {
            cout << "Peem\n";
        }
    }
};

int main() {
    Pessoa pessoa ("Gustavo", 7);
    mostrar(pessoa);

    Pessoa pessoa2 ("Lucas", 8);

    Moto moto(3, 5, &pessoa);
    cout << "A potencia: " << moto.power << endl;
    cout << "O tempo: " << moto.tempo << endl;

    moto.drive(4);
    moto.honk();
    moto.buy(1);
    moto.inserirPessoa(&pessoa2);

return 0;
}