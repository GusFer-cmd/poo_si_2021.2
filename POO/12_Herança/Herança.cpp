#include <iostream>

using namespace std;

class Pokemon {
    string tipo;
    bool alive {true};

public:
    Pokemon(string tipo = "Pokemon nao registrado na pokedesk") : tipo(tipo) {
        cout << "Pokemon encontrado" << endl;
    }

    virtual ~Pokemon() {
    }

    virtual bool isAlive() const { 
        return alive; 
    }

    virtual void die() {
        alive = false;
    }

    virtual string getTipo() const {
        return tipo;
    }

    friend ostream& operator<<(ostream& os, const Pokemon& pokemon) {
        os << pokemon.tipo << ":" << (pokemon.alive ? "vivo" : "retornou para o seu treinador");
        return os;
    }
};

class Pet : public Pokemon {
    string nome;

public:
    Pet(string nome, string tipo) : Pokemon(tipo), nome(nome) {
        cout << this->nome << " saiu da pokebola" << endl;
    }

    virtual ~Pet() {
    }

    virtual void x1() const {
        if (this->isAlive()) {
            cout << this->nome << " Pronto para a batalha" << endl;
        } else {
            cout << this->nome << " Nao esta pronto para a batalha" << endl;
        }
    }

    virtual string getNome() const {
        return nome;
    }

    friend ostream& operator<<(ostream& os, const Pet& pet){
        const Pokemon& pokemon = pet;
        os << pet.nome << ":" << pokemon;
        return os; 
    }
};

class Batalha : public Pet {
    int vidas {7};

public:
    Batalha(string nome, int vidas = 7) : Pet(nome, ""), vidas(vidas) {
    }

    ~Batalha() {
    }

    virtual void ataque() {
        if(this->vidas == 0) {
            cout << "Pokemom esta fora de combate" << endl;
        } else if (this->vidas > 1){
            cout << "Pokemom tomou um ataque" << endl;
        } else {
            this->vidas--;
            cout << "O pokemom retornou para o seu treinador" << endl;
            this->Pokemon::die();
        }
    }

    friend ostream& operator<<(ostream& os, const Batalha& batalha){
        const Pet* pet = &batalha;
        os << *pet << ":" << batalha.vidas;
        return os; 
    }
};

int main() {
    Batalha batalha {"Pikachu", 3};
    Pokemon& pokemon = batalha;
    cout << pokemon << endl;
    cout << batalha << endl;

    Batalha batalha2 {"Onix", 2};
    cout << batalha2 << endl;
    batalha.x1();
    batalha2.x1();
    
    batalha.ataque();
    batalha2.ataque();
    batalha2.ataque();
    batalha.ataque();
    batalha2.die();
    cout << batalha2 << endl;
    cout << batalha << endl;
    
}