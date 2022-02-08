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
    Contato(string name = "") : //Construtor de Contato
        name{name} {
    }

    void addFone(Fone fone) { //Adicionar numero
        if (fone.validar != nullptr) { //Se o numero valido for diferente de nullptr
            if (numeroRepetido(fone) == 1){ //Se o numero já existir
                cout << "Numero repetido" << endl;
                return;
            }
            this->fones.push_back(fone); //Adicionar numero
                cout << "Numero adicionado\n";
        } else {
            cout << "Numero invalido" << endl;
        }
    }

    void removerFone(int indice){ //Remover um numero
        if (indice < 0 || indice >= (int)this->fones.size()) { //Verifica se está no limite
            return;
        }
        this->fones.erase(this->fones.begin() + indice); //Apaga o numero
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
    vector<Contato> contatos;

    int encontrarPos(string name) { //Retorna posição do contato e retorna -1
        for (int i = 0; i < (int)this->contatos.size(); i++) { //Laço
            if (this->contatos[i].getNome() == name) { //Verifica se o nome é igual
                return i;
            }
        }
        return -1;
    }

    bool existe(string name) { //Verifica se existe pelo nome
        for (int i = 0; i < (int)this->contatos.size(); i++) { //Laço
            if (this->contatos[i].getNome() == name) { //Verifica se o nome é igual
                return true;
            }
        }
        return false;
    }

    bool EncontrarFone(vector<Fone> fones, string pattern) { //Procura por um numero
        for (int i = 0; i < (int)fones.size(); i++) { //Laço
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
    Contato getContato(string name) { //Retorna um contato
        return this->contatos[encontrarPos(name)];
    }

    void addFone(Contato contato){ //Adiciona um fone a um contato
        if (!existe(contato.getNome())) { //Verifica se o contato existe
            this->contatos.push_back(contato); //Puxa o contato no final da lista
            return;    
        }

        int posicao = encontrarPos(contato.getNome()); //Pega a posição do contato
        vector<Fone> fones = contato.getFones(); //Pega os fones do contato
        for (int i = 0; i < (int)fones.size(); i++) { //Laço
            this->contatos[posicao].addFone(fones[i]); //Adiciona o fone
        }
    }

    void removerFone(string name, int indice) { //Remover um contato por nome e indice
        int posicao = encontrarPos(name); //Pega a posição do contato
        if(posicao != -1) { //Verifica se existe
            this->contatos[posicao].removerFone(indice); //Remove o fone
            return;
        } else {
        cout << "Contato nao encontrado" << endl;
        return;
        }
    }

    void removerContato(string name) { 
        int posicao = encontrarPos(name); //Pega a posição do contato
        if(posicao != -1) { //Verifica se existe
            this->contatos.erase(contatos.begin() + posicao); //Remove o contato
            cout << "Contato selecionado removido" << endl;
            return;
        } else {
        cout << "Contato nao encontrado na agenda" << endl;
        return;
        }
    }

    vector<Contato> search(string contato) { //Procura contato
        vector<Contato> resultado; // Ao achar armazena no vetor resultado
        for (int i = 0; i < (int)contatos.size(); i++) { //Percorre todos os contatos procurando pelo nome
            if (contatos[i].getNome().find(contato) != string::npos) {
                resultado.push_back(contatos[i]); //Adiciona contato
                cout << resultado[i] << endl;
            }
        }
        for (int i = 0; i < (int)contatos.size(); i++) { //Percorre todos os contatos procurando pelo numero
            if (EncontrarFone(contatos[i].getFones(), contato) == true) { //Verifica se o numero existe
                resultado.push_back(contatos[i]); //Impressão do contato
                cout << resultado[i] << endl;
            }
        }

        if ((int)resultado.size() == 0) {
            cout << "Nenhum contato encontrado" << endl;
        }
        return resultado;
    }

    void Contatoslist(){
        for (auto contato : this->contatos) {
            cout << contato << endl;
        }
    }

    //Friend (Operador de saída)
    friend ostream& operator<<(ostream& os, const Agenda& agenda) {
        if ((int)agenda.contatos.size() == 0) {
            os << "Agenda vazia" << endl;
        } else {
            for (int i = 0; i < (int)agenda.contatos.size(); i++) {
                auto contatos = agenda.contatos[i];
                os << i << ":";
                os << contatos << endl;
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

    cout << "Lista" << " ";
    agenda.addFone(Joao);
    agenda.addFone(Fred);
    agenda.addFone(Maria);

    cout << agenda << endl;

    agenda.removerContato("Maria");
    agenda.removerContato("Fred, 0");

    cout << "Procurar contatos" << " ";
    
    agenda.search("9994");

    cout << agenda << endl;
}