#include <iostream>
#include <vector>
#include <list>
#include <memory>

using namespace std;

class Cliente {
private:  
    string id;
    string fone;

public:
    Cliente(string id = "", string fone = "") : //Construtor
        id{id}, fone{fone} {
    }

    //Métodos

    //Getters e Setters

    string getId() {
        return this->id;
    }

    string getFone() {
        return this->fone;
    }

    void setId(string id) {
        this->id;
    }

    void setFone(string fone) {
        this->fone;
    }

    friend ostream& operator<<(ostream& os, const Cliente& cliente) {
        os << "Id: " << cliente.id << ", Fone: " << cliente.fone << endl;
        return os;
    }
};

class Sala{
    vector<shared_ptr<Cliente>> cadeiras;
    list<shared_ptr<Cliente>> fila;

public:
    Sala(int qtdCadeiras) : cadeiras(qtdCadeiras, nullptr){ //Informar quantidade de cadeiras.
    }

    void entrar(const shared_ptr<Cliente>& cliente) {
        this->fila.push_back(cliente);
    }
    
    bool reservarCadeira(int indice) {
        if (indice < 0 || indice >= this->cadeiras.size()) {
            cout << "Cinema fechado\n";
            return false;
        }
        if (this->cadeiras[indice] != nullptr) { //Duas pessoas no mesmo lugar, não pode.
            cout << "Cadeira ja foi reservada, selecione outra que esteja disponivel\n";
            return false;
        }
        if (this->fila.empty()) {
            cout << "Fila vazia\n";
            return false;
        }
        this->cadeiras[indice] = this->fila.front();
        this->fila.pop_front();
        return true;
    }

    bool finalizarSessao(int indice) {
        if (indice < 0 || indice >= this->cadeiras.size()) {
            cout << "Cinema fechado\n";
            return false;
        }
        if (this->cadeiras[indice] == nullptr) {
            cout << "Cadeira vazia\n";
            return false;
        }
        this->cadeiras[indice] = nullptr; //Acabou a sessão
        cout << "O filme acabou, pode ir pra casa\n";
        return true;
    }    

    bool cancelar(string indice) {
        for (int i = 0; i < this->cadeiras.size(); i++) {
            if (this->cadeiras[i] != nullptr && this->cadeiras[i]->getId() == indice) {
                this->cadeiras[i] = nullptr;
                return true;
            }
        }
        return false;
    }

    friend ostream& operator<<(ostream& os, const Sala& s) {
        os << "Cadeiras: | ";
        for (int i = 0; i < (int) s.cadeiras.size(); i++) {
            auto& cadeira = s.cadeiras[i];
            os << i << ":" ;
            if (cadeira != nullptr) {
                os << *cadeira;
            } else {
                os << "-----"; //Cadeira vazia
            os << " | ";    
            }
        }
    os << "\nFila: | ";
    for (auto fila : s.fila) {
        os << *fila << " ";
    }
    return os;
    }

};

int main () {
    Sala sala(3);
    sala.entrar(make_shared<Cliente>("David - 10", "123"));
    sala.entrar(make_shared<Cliente>("Pedro - 11", "456"));
    sala.entrar(make_shared<Cliente>("Lucas - 12", "789"));
    sala.entrar(make_shared<Cliente>("Gustavo - 13", "101"));

    sala.reservarCadeira(0);
    sala.reservarCadeira(1);
    sala.reservarCadeira(2);
    sala.reservarCadeira(0); //Cadeira já reservada

    sala.cancelar("Pedro - 11");//Pedro cancelou sua reserva, cadeira 1 disponivel.

    sala.finalizarSessao(0);//Sessão do David acabou
    
    cout << sala << endl;

    return 0;
}