#include <iostream>
#include <memory>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

class Fone {
    private:
        string numero;
        string id;

    public:
    Fone(string id = "", string numero = "") :
        id{id}, numero{numero} {
    }    

        string getNumero() {
            return this->numero;
        }

        string getId() {
            return this->id;
        }

        static bool validar(string numero) {
            int indice = 0;
            for ( int i = 0; i < 9; i++){
                indice += numero[i] * (10 - 1);
            }
            if (indice % 11 == 0 || indice % 11 == 1) {
                if (numero[9] == 0) {
                    return true;
                } else {
                    return false;
                }
            } else {
                if (numero[9] == (11 - (indice % 11))) {
                    return true;
                } else {
                    return false;
                }
            }
        }

    friend ostream& operator<<(ostream& os, Fone& fone) {
        os << fone.getId() << ": " << fone.getNumero() << "]" << endl;
        return os;
    }
};

class Contato {
    private:
    string name;
    vector<Fone> fones;    

    bool numeroRepetido(Fone fone) {
        for (int i = 0; i < (int)this->fones.size(); i++) {
            if ((this->fones[i].getId() == fone.getId()) && (this->fones[i].getNumero() == fone.getNumero())) {
                return true;
            }
        }
        return false;
    }    

    public:
    Contato(string name = "") :
        name{name} {
    }

    void addFone(Fone fone) {
        if (fone.validar != nullptr) {
            if (numeroRepetido(fone)){
                cout << "Numero repetido" << endl;
                return;
            }
            this->fones.push_back(fone);
                cout << "Numero adicionado\n";
        } else {
            cout << "Numero invalido" << endl;
        }
    }

    void removerFone(int indice){
        if (indice < 0 || indice >= (int)this->fones.size()) {
            return;
        }
        this->fones.erase(this->fones.begin() + indice);
        cout << "Numero removido" << endl;
        return;
    }

    vector<Fone> getFones(){
        return this->fones;
    }

    string getNome(){
        return this->name;
    }

    friend ostream& operator<<(ostream& os, Contato& contato) {
        os << contato.getNome() << " ";
        for (int i = 0; i < (int)contato.fones.size(); i++) {
            auto fone = contato.fones[i];
            os << "[" << i << ":" << fone << endl;
        }
        return os;
    }
};

int main()
{
    Contato contato("Joao");
    contato.addFone(Fone("oi", "8808"));
    contato.addFone(Fone("casa", "323431"));
    cout << "\n";

    Contato contato2("Ellen");
    contato2.addFone(Fone("tim", "9186"));
    contato2.addFone(Fone("casa", "323431"));
    cout << "\n";

    Contato contato3("Lucas");
    contato3.addFone(Fone("vivo", "9374"));
    contato3.removerFone(0);
    cout << "\n";

    Contato contato4("Maria");
    contato4.addFone(Fone("Telegram", "8808"));
    cout << "\n";

    cout << contato << endl;
    cout << contato2 << endl;
    cout << contato3 << endl;
    cout << contato4 << endl;

    return 0;
}    