#include <iostream>
#include <algorithm>

using namespace std;

//Struct então tudo é público
struct Pessoa {
    string nome; //Inicializando atributos
    int idade;

    //Construtor
    Pessoa( string nome = "", int idade = 0) : 
        nome{nome}, idade{idade} {
    }         

    //Destrutor	
    ~Pessoa() {
    
    }

    //Métodos

    //Getters

    int getIdade() {
        return this->idade;
    }

    string getNome() {
        return this->nome;
    }

    //Friend para print (Operador de saída). Não é um metodo da classe.
    friend ostream& operator<<(ostream& os, const Pessoa& pessoa) {
        os << "Nome: " << pessoa.nome << ", ";
        os << "Idade: " << pessoa.idade << " anos\n";    
        return os;
    }
}; 

//Função para print a criança 
void mostrar( Pessoa& pessoa ) {
        cout << pessoa.nome << " tem " << pessoa.idade << " anos " << endl; 
    }

//Nova classe
struct Moto {
    int power{1}; //Inicializando variáveis
    int tempo{0};
    Pessoa* pessoa; //Para não ter copia. (Troca objeto).
    Moto(int power, int tempo, Pessoa* pessoa = nullptr) :  //Construtor da moto
        power{power}, tempo{tempo}, pessoa{pessoa} {
    }      

    //Construtor de energia(power).
    Moto(int power) : 
        power{power} {
    }
    
    friend ostream& operator<<(ostream& os, const Moto& moto) { //Friend da moto
        os << "Potencia: " << moto.power << " \n";
        os << "Tempo: " << moto.tempo << " anos\n";    
    }

    bool inserirPessoa(Pessoa* pessoa) {
        if (this->pessoa != nullptr) {  //Usa "->" ponteiro
            cout << "Moto ocupada.\n";
            return false;
        } else {
        cout << "Crianca subiu na motoca" << endl;
        this->pessoa = pessoa; //Atribuição
        return true;
        }
    }

    Pessoa* removerPessoa() {
        if (this->pessoa == nullptr) {
            cout << "Moto disponivel\n";
            return nullptr;
        } else {
        cout << "Crianca foi removida da motoca. Moto disponivel" << endl;
        return exchange(this->pessoa, nullptr); //Replace, pra não perder o obj
        }
    }

    void buy(int tempo) {
        if(this->tempo == 0) {
            cout << "Tempo acabou. Compre mais tempo!\n";
        } else {
            this->tempo += tempo; //Incrementa
            cout << "Tempo adicionado com sucesso!\n";
        }   
    }

    void drive(int tempo) {
        if(this->pessoa != nullptr && this->pessoa->idade < 11) {
            cout << "Crianca esta na motoca" << endl;
        } else if (this->tempo == 0) {
            cout << "Tempo acabou. Compre mais tempo!" << endl;
        } else if (this->tempo >= tempo) {
            this->tempo -= tempo; //Decrementa
        } else {
            cout << "Tempo insuficiente" << endl;
        }
    }

    void honk(){
        if (this->pessoa == nullptr) {
            cout << "Sem piloto, sem buzina" << endl;
        } else
            cout << "P";
            for (int i = 0; i < this->power; i++) {
                cout << "e";
            }
            cout << "m\n";
        }
};

int main() {
    Pessoa pessoa ("Gustavo", 7);
    mostrar(pessoa);

    Pessoa pessoa2 ("Lucas", 8);

    Moto moto(3, 5, &pessoa);
    cout << "A potencia: " << moto.power << endl;
    cout << "O tempo: " << moto.tempo << endl;

    moto.drive(5);
    moto.honk();
    moto.buy(1);
    moto.removerPessoa();
    moto.inserirPessoa(&pessoa2);

    mostrar(pessoa2);

return 0;
}