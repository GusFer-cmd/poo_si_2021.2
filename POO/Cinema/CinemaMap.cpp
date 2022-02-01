#include <iostream>
#include <map>
#include <memory>
#include <algorithm>
#include <vector>

using namespace std;

class Cliente {
    
    private:
    string id;
    string fone;

    public:
    Cliente(string id = "", string fone = "") :
        id{id}, fone{fone} {
    }

    string getId() {
        return this->id;
    }

    string getFone() {
        return this->fone;
    }


    friend ostream& operator<<(ostream& os, Cliente& cliente) {
        os << "Id: " << cliente.getId() << ", Fone: " << cliente.getFone() << endl;
        return os;
    }
};

class Sala{
    private:
    vector<shared_ptr<Cliente>> cadeiras;

public:
    Sala(int qtdCadeiras) : cadeiras{qtdCadeiras, nullptr} {
    }

    bool reservar(shared_ptr<Cliente> client, int ind) {
        if (this->cadeiras[ind] != nullptr || ind >= (int)this->cadeiras.size()) {
            cout << "Cadeira já reservada" << endl;
            return false;
        }

        this->cadeiras[ind] = client;
        cout << "Cadeira reservada" << endl;
        return true;
    }

    void cancelar(string id) {
        for (int i = 0; i < (int)this->cadeiras.size(); ++i) {
            if (this->cadeiras[i] != nullptr && this->cadeiras[i]->getId() == id) {
                this->cadeiras[i] = nullptr;
                cout << "Reserva cancelada" << endl;
                break;
            }
        }
    }

    friend ostream& operator<<(ostream& os, const Sala& s) {
        for (int i = 0; i < (int)s.cadeiras.size(); i++) {
            auto &cadeira = s.cadeiras[i];
            os << i << ":";
            if (cadeira != nullptr) {
                os << *cadeira;
            } else {
                os << "******";
            os << " || ";
            }
        }
        return os;
    }

};

int main () {

    Sala sala(5);

    sala.reservar(make_shared<Cliente>("123", "Pedro"), 0);
    sala.reservar(make_shared<Cliente>("456", "Gustavo"), 1);
    sala.reservar(make_shared<Cliente>("789", "Larissa"), 2);

    sala.cancelar("123");
    cout << "\n";

    cout << sala << endl;
    cout << "\n";
}