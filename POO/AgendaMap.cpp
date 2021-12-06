#include <iostream>
#include <memory>
#include <vector>
#include <map>

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

class Agenda{
    private:
    map<string, Contato> contatos;

    public:
    Agenda() {};    
       
    Contato getContato(string nome) {
        return this->contatos[nome];
    }
    
    void addContato(Contato contato) {
        auto it = contatos.find(contato.getNome());
        if ( it == contatos.end()) {
            contatos[contato.getNome()] = contato;
        } else{
        it -> second.addFone(contato.getFones()[0]);
        }
    } 

    void removerFone(string nome){
        auto it = contatos.find(nome);
        if (it != contatos.end()) {
            contatos.erase(it);
        }else {
             cout << "Contato " << nome << " nao encontrado" << endl;
        }
    }

    void removerFone(string nome, int index) {
        auto it = contatos.find(nome);

        if (it != contatos.end()) 
        {
            it->second.removerFone(index);
        } else { 
            cout << "Contato selecionado nao encontrado" << endl;
        }
    }

    void search(string n){
        for (auto cont : contatos){
            size_t found = cont.second.getNome().find(n);
            if (found != string::npos) {
                cout << cont.second << endl;
            }
        }
        cout << "\n";
    }

    friend ostream& operator<<(ostream& os, Agenda& agenda){
        os << "\n";
        for (auto cont : agenda.contatos){
            os << cont.second << endl;
        }
        return os;
    }
}; 

int main() {  

cout << "AGENDA" << endl;
    Agenda agenda;

    cout << "Adicionar contatos" << endl;
    Contato Joao{"Joao"};
    Contato Fred{"Fred"};
    Contato Maria{"Maria"};

    Joao.addFone(Fone{"tim", "1640"});
    Fred.addFone(Fone{"tim", "788"});
    Fred.addFone(Fone{"vivo", "335"});
    Maria.addFone(Fone{"tim", "1765"});

    cout << "Lista" << endl;
    agenda.addContato(Joao);
    agenda.addContato(Fred);
    agenda.addContato(Maria);

    cout << agenda << endl;

    cout << "Remover contato" << endl;
    agenda.removerFone("Maria");
    agenda.removerFone("Fred", 1);

    cout << "Procurar contatos" << endl;
    agenda.search("335");
    cout << agenda << endl;

}