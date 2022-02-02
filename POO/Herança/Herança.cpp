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
        cout << "Pokemon fugiu" << endl;
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
        os << pokemon.tipo << ":" << (pokemon.alive ? "vivo" : "morto");
        return os;
    }
};

class Pet : public Pokemon {
    string nome;

public:
    Pet(string nome, string tipo) : Pokemon(tipo), nome(nome) {
        cout << this->nome << " Saiu da pokebola" << endl;
    }

    virtual ~Pet() {
        cout << this->nome << " Entrou na pokebola" << endl;
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

class Meaow : public Pet {
    int vidas {7};

public:
    Meaow(string nome, int vidas = 7) : Pet(nome, "Meaow"), vidas(vidas) {
    }

    ~Meaow() {
    }

    virtual void meaow() const {
        cout << this->getNome() << "Meaow" << endl;
    }

    virtual void decolando() {
        if(this->vidas == 0) {
            cout << "Equipe rocket decolando de novo" << endl;
        } else if (this->vidas > 1){
            cout << "Equipe rocket pronta pra batalha" << endl;
        } else {
            this->vidas--;
            cout << "Equipe Rocket decolou" << endl;
            this->Pokemon::die();
        }
    }

    friend ostream& operator<<(ostream& os, const Meaow& meaow){
        const Pet* pet = &meaow;
        os << *pet << ":" << meaow.vidas;
        return os; 
    }
};

int main() {
    Meaow meaow {"Pikachu", 3};
    Pokemon& pokemon = meaow;
    pokemon.die();
    pokemon.die();
    pokemon.die();
    cout << pokemon << endl;

    Meaow meaow2 {"Onix", 7};
    cout << meaow2 << endl;
    meaow2.x1();
    meaow2.meaow();
    meaow2.die();



}