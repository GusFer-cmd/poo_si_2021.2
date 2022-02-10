#include <iostream>
#include <map>
#include <memory>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

class Cliente {
    
private:
    string id;
    string fone;

public:
    Cliente(string id = "", string fone = "") : //Construtor do cliente
        id{id}, fone{fone} {
    }

    //Metodos
    //Getters
    string getId() const {
        return this->id;
    }

    string getFone() const {
        return this->fone;
    }

    //Friend
    friend ostream& operator<<(ostream& os, Cliente& cliente) {
        os << "Id: " << cliente.id << ", Fone: " << cliente.fone << endl;
        return os;
    }
};

class Sala{
private:
    map<int, shared_ptr<Cliente>> cadeiras;
    
public:

    Sala(){}; //Construtor de inicialização da sala

    bool validarCliente(string id){ //Verifica se o cliente existe
        for (auto it = this->cadeiras.begin(); it != this->cadeiras.end(); ++it){ //Percorre o mapa
            if (it->second->getId() == id){ //Compara
                return true;
            }
        }
        return false;
    }

    bool reservarCadeira(const shared_ptr<Cliente>& cliente, int indice){ //Reserva uma cadeira
        auto it = cadeiras.find(indice);
    
        if (it != cadeiras.end()){ //Verifica se a cadeira está ocupada
            cout << "Cadeira ocupada\n";
            return false;
        }

        if (validarCliente(cliente->getId())){ //Não pode reservar uma cadeira que já está reservada
            cout << "Cliente ja tem uma reserva\n";
            return false;
        }

        cadeiras[indice] = cliente; //Reserva a cadeira
        cout << "Cadeira reservada\n";
        return true;
    }

    bool cancelar(string id){ //Cancela uma reserva
        for (auto it = this->cadeiras.begin(); it != this->cadeiras.end(); ++it){
            if (it->second->getId() == id){
                cadeiras.erase(it);
                cout << "Reserva cancelada\n";
                return true;
            }
        }
    }
    //Friend
    friend ostream& operator<<(ostream& os, const Sala& sala){
        os << "Cadeiras: " << endl;
        for (auto it = sala.cadeiras.begin(); it != sala.cadeiras.end(); ++it){
            os << it->first << ": " << *(it->second) << endl; 
            os << " | ";
        }
        os << "]";
        return os;
    }
};

int main () {
 Sala cinema;

    while(true) {
    string line;
    getline(cin, line);
    stringstream ss(line);
    string cmd;
    ss >> cmd;
    
        if (cmd == "exit") {
            break;
        } else if (cmd == "show") {
            cout << cinema << endl;
        } else if (cmd == "reservar") {
            string fone{};
            string id{};
            int indice{};
            ss >> fone >> id >> indice;
            cinema.reservarCadeira(make_shared<Cliente>(fone, id), indice);
        } else if (cmd == "cancelar") {
            string id{};
            ss >> id;
            cinema.cancelar(id);
        }
    }
}