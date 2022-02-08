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

    bool numeroRepetido(Fone fone) { //Verifica se o numero já existe
        for (int i = 0; i < (int)this->fones.size(); i++) {
            if ((this->fones[i].getId() == fone.getId()) && (this->fones[i].getNumero() == fone.getNumero())) {
                return true;
            }
        }
        return false;
    }    

public:
    Contato(string name = "") : //Construtor de Contato
        name{name} {
    }

    void addFone(Fone fone) { //Adicionar numero
        if (fone.validar != nullptr) { //Verifica se o numero valido é diferente de null
            if (numeroRepetido(fone) == 1){ //Se o numero já existe == 1
                cout << "Numero repetido" << endl;
                return;
            }
            this->fones.push_back(fone); //Depois da verificação adiciona o numero
                cout << "Numero adicionado\n";
        } else {
            cout << "Numero invalido" << endl;
        }
    }

    void removerFone(int indice){ //Remover o fone
        if (indice < 0 || indice >= (int)this->fones.size()) { //Verifica se está no limite do vector de fone
            return;
        }
        this->fones.erase(this->fones.begin() + indice); //Remove o fone
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
    friend ostream& operator<<(ostream& os, const Contato& contato) {
        os << contato.name << " ";
        for (int i = 0; i < (int)contato.fones.size(); i++) {
            auto fone = contato.fones[i];
            os << "[" << i << ":" << fone;
        }
        return os;
    }
};

class Agenda{
private:
    map<string, Contato> contatos;

public:
    Agenda() {}; //Construtor de inicialização da agenda

     //Getters  
    Contato getContato(string nome) { //Retorna o contato
        return this->contatos[nome];
    }
    
    void addContato(Contato contato) { //Adicionar contato
        auto it = contatos.find(contato.getNome()); //Verifica se o contato já existe
        if ( it == contatos.end()) { //Se não existir
            contatos[contato.getNome()] = contato; //Adiciona o contato
        } else{
        it -> second.addFone(contato.getFones()[0]); 
        }
    } 

    void removerFone(string nome) {
        auto it = contatos.find(nome); //Verifica se o contato existe pelo nome
        if (it != contatos.end()) {
            contatos.erase(it); //Remove o contato
        }else {
             cout << "Contato " << nome << " nao encontrado" << endl;
        }
    }


    void removerFone(string nome, int indice){
        auto it = contatos.find(nome); //Verifica se o contato existe pelo nome
        if (it != contatos.end()) {
            it -> second.removerFone(indice); //Remove o fone pelo indice
        }else {
             cout << "Contato nao encontrado" << endl;
        }
    }

    void search(string num){
        for (auto contato : contatos){
            size_t found = contato.second.getNome().find(num); //Percorre a agenda procurando o contato
            if (found != string::npos) {  //Se encontrar o contato
                cout << contato.second << endl; //Imprime o contato
            } else {
                cout << "Contato nao encontrado" << endl;
            }
        }
        cout << "\n";
    }

    friend ostream& operator<<(ostream& os, Agenda& agenda){
        os << "\n";
        for (auto cont : agenda.contatos){
            os << cont.second << "\n";
        }
        return os;
    }
}; 

int main() {  

    
    Agenda agenda;

    Contato Joao{"Joao"};
    Contato Fred{"Fred"};
    Contato Maria{"Maria"};

    cout << "Adicionar contatos" << endl;
    Joao.addFone(Fone{"tim", "1640"});
    Fred.addFone(Fone{"tim", "788"});
    Fred.addFone(Fone{"vivo", "335"});
    Maria.addFone(Fone{"tim", "1765"});

    cout << "Lista" << " ";
    agenda.addContato(Joao);
    agenda.addContato(Fred);
    agenda.addContato(Maria);

    cout << agenda << endl;

    agenda.removerFone("Maria");

    cout << "Procurar contatos" << " ";
    
    agenda.search("335");
    
    cout << agenda << endl;

}