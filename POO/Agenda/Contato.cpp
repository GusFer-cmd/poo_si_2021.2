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
    Fone(string id = "", string numero = "") : //Construtor
        id{id}, numero{numero} {
    }    

    //Métodos	
    //Getters

    string getNumero() {
        return this->numero;
    }

    string getId() {
        return this->id;
    }

    static bool validar(string numero) { //Validar número de telefone
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

    //Friend
    friend ostream& operator<<(ostream& os, Fone& fone) {
        os << fone.id << ": " << fone.numero << "]" << endl;
        return os;
    }
};

class Contato {
private:
    string name;
    vector<Fone> fones;    

    bool numeroRepetido(Fone fone) { //Verificar se número se repete
        for (int i = 0; i < (int)this->fones.size(); i++) {
            if ((this->fones[i].getId() == fone.getId()) && (this->fones[i].getNumero() == fone.getNumero())) {
                return true;
            }
        }
        return false;
    }    

public:
    Contato(string name = "") : //Construtor
        name{name} {
    }

    void addFone(Fone fone) { //Adicionar número
        if (fone.validar != nullptr) {
            if (numeroRepetido(fone)){ //Verificar numero repetido
                cout << "Numero repetido" << endl;
                return;
            }
            this->fones.push_back(fone);//Add fone
                cout << "Numero adicionado\n";
        } else {
            cout << "Numero invalido" << endl;
        }
    }

    void removerFone(int indice){ //Remover número
        if (indice < 0 || indice >= (int)this->fones.size()) {
            return;
        }
        this->fones.erase(this->fones.begin() + indice);
        cout << "Numero removido" << endl;
        return;
    }

    //Metodos
    //Getters

    vector<Fone> getFones(){
        return this->fones;
    }

    string getNome(){
        return this->name;
    }

    //Friend
    friend ostream& operator<<(ostream& os, Contato& contato) {
        os << contato.name << " ";
        for (int i = 0; i < (int)contato.fones.size(); i++) {
            auto fone = contato.fones[i];
            os << "[" << i << ":" << fone;
        }
        return os;
    }
};

int main()
{
    Contato contato("Joao");
    contato.addFone(Fone("oi", "8808"));
    contato.addFone(Fone("casa", "3250"));
    cout << "\n";

    Contato contato2("Ellen");
    contato2.addFone(Fone("tim", "9186"));
    contato2.addFone(Fone("casa", "3234"));
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