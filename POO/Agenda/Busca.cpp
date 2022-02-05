#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

class Fone {
private:
    string numero;
    string id;

public:
    Fone(string id = "", string numero = "") : //Construtor de Fone
        id{id}, numero{numero} {
    }    

    //Metodos
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

    //Friend (Operador de saída)
    friend ostream& operator<<(ostream& os, Fone& fone) {
        os << fone.getId() << ": " << fone.getNumero() << "]" << endl;
        return os;
    }
};

class Contato {
private:
    string name;
    vector<Fone> fones;    

    bool numeroRepetido(Fone fone) { //Verificar se o número já existe
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

    void addFone(Fone fone) { //Adicionar numero
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

    void removerFone(int indice){ //Remover um numero
        if (indice < 0 || indice >= (int)this->fones.size()) {
            return;
        }
        this->fones.erase(this->fones.begin() + indice);
        cout << "Numero removido" << endl;
        return;
    }

    //Getters
    vector<Fone> getFones(){
        return this->fones;
    }

    string getNome(){
        return this->name;
    }

    //Friend (Operador de saída)
    friend ostream& operator<<(ostream& os, Contato& contato) {
        os << contato.getNome() << " ";
        for (int i = 0; i < (int)contato.fones.size(); i++) {
            auto fone = contato.fones[i];
            os << "[" << i << ":" << fone;
        }
        return os;
    }
};

class Agenda{
private:
    vector<Contato> contatos;

    int encontrarPos(string name) { //Retorna posição do contato e retorna -1
        for (int i = 0; i < (int)this->contatos.size(); i++) {
            if (this->contatos[i].getNome() == name) {
                return i;
            }
        }
        return -1;
    }

    bool existe(string name) { //Verifica se existe pelo nome
        for (int i = 0; i < (int)this->contatos.size(); i++) {
            if (this->contatos[i].getNome() == name) {
                return true;
            }
        }
        return false;
    }

    bool EncontrarFone(vector<Fone> fones, string pattern) { //Procura por um numero
        for (int i = 0; i < (int)fones.size(); i++) {
            if (fones[i].getNumero().find(pattern) != string::npos) {
                return true;
            }
        }
        return false;
    }

public:
    Agenda(){} //Construtor para inicializar a agenda

    //Metodos 
    //Getters
    Contato getContato(string name) {
        return this->contatos[encontrarPos(name)];
    }

    void addFone(Contato contato){ //Adiciona um fone a um contato
        if (!existe(contato.getNome())) {
            this->contatos.push_back(contato);
            return;    
        }

        int posicao = encontrarPos(contato.getNome());
        vector<Fone> fones = contato.getFones();
        for (int i = 0; i < (int)fones.size(); i++) {
            this->contatos[posicao].addFone(fones[i]);
        }
    }

    void removerFone(string name, int indice) { //Remover um contato por nome e indice
        int posicao = encontrarPos(name);
        if(posicao != -1) {
            this->contatos[posicao].removerFone(indice);
            return;
        }
        cout << "Contato nao encontrado" << endl;
        return;
    }

    void removerContato(string name) { 
        int posicao = encontrarPos(name);
        if(posicao != -1) {
            this->contatos.erase(contatos.begin() + posicao);
            cout << "Contato selecionado removido" << endl;
            return;
        }
        cout << "Contato nao encontrado na agenda" << endl;
        return;
    }

    vector<Contato> search(string pattern) { //Procura contato
        vector<Contato> resultado; // Ao achar armazena no vetor resultado
        for (int i = 0; i < (int)contatos.size(); i++) { //Percorre todos os contatos procurando pelo nome
            if (contatos[i].getNome().find(pattern) != string::npos) {
                resultado.push_back(contatos[i]); //Adiciona contato
                cout << resultado[i] << endl; //Armazena no vetor
            }
        }
        for (int i = 0; i < (int)contatos.size(); i++) {
            if (EncontrarFone(contatos[i].getFones(), pattern) == true) {
                resultado.push_back(contatos[i]);
                cout << resultado[i] << endl;
            }
        }

        if ((int)resultado.size() == 0) {
            cout << "Nenhum contato encontrado" << endl;
        }
        return resultado;
    }

    //Friend (Operador de saída)
    friend ostream& operator<<(ostream& os, const Agenda& agenda) {
        if ((int)agenda.contatos.size() == 0) {
            os << "Agenda vazia" << endl;
        } else {
            for (int i = 0; i < (int)agenda.contatos.size(); i++) {
                auto contatos = agenda.contatos[i];
                os << i << ":";
                os << contatos;
            }
        }
        return os;
    }
}; 

int main() {
    Agenda agenda;

    cout << "Adicionar contatos" << endl;
    Contato Joao{"Joao"};
    Contato Fred{"Fred"};
    Contato Maria{"Maria"};

    Joao.addFone(Fone("tim", "9994"));
    Fred.addFone(Fone("tim", "9990"));
    Fred.addFone(Fone("vivo", "8999"));
    Maria.addFone(Fone("oi", "8785"));

    cout << "Lista" << endl;
    agenda.addFone(Joao);
    agenda.addFone(Fred);
    agenda.addFone(Maria);

    cout << agenda << endl;

    agenda.removerContato("Maria");
    agenda.removerContato("Fred, 1");

    cout << "Procurar contatos" << endl;
    agenda.search("Fred");
    cout << agenda << endl;
}