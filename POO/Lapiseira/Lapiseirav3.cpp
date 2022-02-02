#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <sstream>
#include <algorithm>

using namespace std;

class Grafite {
private:
    float calibre;
    int tamanho;
    string dureza;

public:
    Grafite(float calibre = 0, int tamanho = 0, string dureza = "") : //Construtor
        calibre{calibre}, tamanho{tamanho}, dureza{dureza} {
    }

    //Destrutor
    ~Grafite() {
    }

    //Métodos

    //Possíveis casos de dureza no uso do grafite por folha
    int Folha(){ 
        if (this->dureza == "HB"){
            return 1;
        } else if (this->dureza == "2B"){
            return 2;
        } else if (this->dureza == "4B"){
            return 3;
        } else if (this->dureza == "6B"){
            return 4;
        } else {
            cout << "Dureza inválida" << endl;
            return 0;
        }
    }

    //Getters
    float getCalibre() {
        return this->calibre;
    }

    int getTamanho() {
        return this->tamanho;
    }

    string getDureza() {
        return this->dureza;
    }

    //Setters
    bool setTamanho(int tamanho) {
        if (tamanho >= 10) {
            this->tamanho = tamanho;
            return true;
        } else {
            this->tamanho = 10;
            return false;
        }
    }

    //Friend (Operador de saída).
    friend ostream& operator<<(ostream& os, Grafite& grafite) { //Constante posso usar "&"
        os << "Calibre: " << grafite.calibre << endl;
        os << "Tamanho: " << grafite.tamanho << endl;
        os << "Dureza: " << grafite.dureza << endl;
        return os;
    }
};

class Lapiseira {
private:
    list<shared_ptr<Grafite>> tambor; //Elemento independente. Todos os grafitos que estão no tambor.
    vector<shared_ptr<Grafite>> bico {nullptr}; //O grafite que está no bico.
    float dureza {0}; //Inicializando a dureza como 0.

public:
    
    Lapiseira(float dureza = 0.0) : //Construtor de dureza
        dureza{dureza} {
    }

    //Metodos
    void inserirGrafite(const shared_ptr<Grafite>& grafite){
        tambor.push_back(grafite);
    } 

    bool colocarGrafite(int indice) { //Tambor não existe
        if (indice < 0 || indice >= this->bico.size()) { 
            cout << "Grafite inexistente\n";
            return false;
        }
        if (this->bico[indice] != nullptr) { //Tambor já tem grafite
            cout << "Grafite ja esta sendo usado\n";
            return false;
        }
        if (this->tambor.empty()) { //Não tem grafite.
            cout << "Nao ha grafites no tambor\n";
            return false;
        }
        this->bico[indice] = this->tambor.front(); //Ponta do tambor para o bico. Lista não usa índice
        this->tambor.pop_front(); //Tira o primeiro
        return true;
    }    

    bool removerGrafite(int indice) {
        if (indice < 0 || indice >= this->bico.size()) { //Existe ou não
            cout << "Grafite inexistente\n";
            return false;
        }
        if (this->bico[indice] == nullptr) { //Sem grafite
            cout << "Bico sem grafite\n";
            return false;
        }
        this->bico[indice] = nullptr; //Remove grafite do bico e ele é descartado
        return true;
    }

    void escrever(int indice) {
        if (this->bico[indice] == nullptr) {
            cout << "Bico sem grafite\n";
        }
        if (indice >= this->bico.size() <= 10) {
            cout << "Grafite muito curto\n";
        }
    }

    friend ostream& operator<<(ostream& os, const Lapiseira& lapiseira) { //Friend
        os << "Grafite no bico: | "; //Mostrar grafite
        for (int i = 0; i < (int) lapiseira.bico.size(); i++) {
            auto& bico = lapiseira.bico[i];
            os << i << ":";
            if (bico != nullptr) { //Se existir mostra o grafite
                os << *bico;
            } else {
                os << "-----"; //Caso não existir
            os << " | ";
            }
        }
        os << "\nGrafite no tambor: | "; //Grafites
        for (auto tambor : lapiseira.tambor) {
            os << *tambor << " ";
        }
        return os;
    }
};

int main () {

    Lapiseira lapiseira(0.5);

    lapiseira.inserirGrafite(make_shared<Grafite>(0.5, 5, "2B"));
    lapiseira.inserirGrafite(make_shared<Grafite>(0.5, 13, "6B"));
    lapiseira.inserirGrafite(make_shared<Grafite>(0.5, 17, "HB"));

    lapiseira.colocarGrafite(0);
    lapiseira.colocarGrafite(1);
    lapiseira.colocarGrafite(2);

    lapiseira.escrever(0);
    lapiseira.escrever(1);

    lapiseira.removerGrafite(0);

    cout << lapiseira << endl;

}