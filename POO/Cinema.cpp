#include <iostream>
#include <vector>
#include <list>
#include <memory>

using namespace std;

class Cliente {
    public:
    string id;
    string fone;

    Cliente(string id = "", string fone = "") :
        id{id}, fone{fone} {
    }

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
    Sala(int qtdCadeiras) : cadeiras(qtdCadeiras, nullptr){
    }

    void entrar(const shared_ptr<Cliente>& cliente) {
        this->fila.push_back(cliente);
    }
    
    bool chamarCadeira(int indice) {
        if (indice < 0 || indice >= this->cadeiras.size()) {
            cout << "Cinema fechado\n";
            return false;
        }
        if (this->cadeiras[indice] != nullptr) {
            cout << "Cadeira reservada\n";
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
        this->cadeiras[indice] = nullptr;
        return true;
    }    

    friend ostream& operator<<(ostream& os, const Sala& s) {
        os << "Cadeiras: | ";
        for (int i = 0; i < (int) s.cadeiras.size(); i++) {
            auto& cadeira = s.cadeiras[i];
            os << i << ":" ;
            if (cadeira != nullptr) {
                os << *cadeira;
            } else {
                os << "-----";
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
    sala.entrar(make_shared<Cliente>("David", "123"));
    sala.entrar(make_shared<Cliente>("Pedro", "456"));
    sala.entrar(make_shared<Cliente>("Lucas", "789"));
    sala.entrar(make_shared<Cliente>("Gustavo", "101112"));

    sala.chamarCadeira(0);
    sala.chamarCadeira(1);
    sala.chamarCadeira(2);
    sala.chamarCadeira(0);

    sala.finalizarSessao(0);
    sala.finalizarSessao(1);

    cout << sala << endl;

    return 0;
}