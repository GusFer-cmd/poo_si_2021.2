#include <iostream>
#include <vector>
#include <list>
#include <memory>

using namespace std;

class Grafite {
    public:
    float calibre;
    int tamanho;
    string dureza;

    Grafite(float calibre, int tamanho, string dureza) : 
        calibre{calibre}, tamanho{tamanho}, dureza{dureza} {
    }
       
    friend ostream& operator<<(ostream& os, const Grafite& grafite) {
        os << "Calibre: " << grafite.calibre << "mm, ";
        os << "Tamanho: " << grafite.tamanho << "mm, ";
        os << "Dureza: " << grafite.dureza << ".";
        return os;
    }
};

class Lapiseira {
    vector<shared_ptr<Grafite>> bico;
    list<shared_ptr<Grafite>> tambor; 

public:
    Lapiseira( int qtdGrafites) : bico(qtdGrafites, nullptr){
    }

    void adicionaGrafite(shared_ptr<Grafite>& grafite) {
        this->tambor.push_back(grafite);
    }

    bool colocarGrafite(int indice) {
        if (indice < 0 || indice >= this->bico.size()) {
            cout << "Grafite inexistente\n";
            return false;
        }
        if (this->bico[indice] != nullptr) {
            cout << "Grafite ja esta sendo usado\n";
            return false;
        }
        if (this->tambor.empty()) {
            cout << "Nao ha grafites no tambor\n";
            return false;
        }
        this->bico[indice] = this->tambor.front();
        this->tambor.pop_front();
        return true;
    }    

    bool removerGrafite(int indice) {
        if (indice < 0 || indice >= this->bico.size()) {
            cout << "Grafite inexistente\n";
            return false;
        }
        if (this->bico[indice] == nullptr) {
            cout << "Bico sem grafite\n";
            return false;
        }
        this->bico[indice] = nullptr; // remove grafite do bico e ele é descartado
        return true;
    }

    friend ostream& operator<<(ostream& os, const Lapiseira& lapiseira) {
        os << "Grafite no bico: | ";
        for (int i = 0; i < (int) lapiseira.bico.size(); i++) {
            auto& bico = lapiseira.bico[i];
            os << i << ":";
            if (bico != nullptr) {
                os << *bico;
            } else {
                os << "-----";
            os << " | ";
            }
        }
        os << "\nGrafite no tambor: | ";
        for (auto tambor : lapiseira.tambor) {
            os << *tambor << " ";
        }
        return os;
    }

};

int main () {

    Lapiseira lapiseira(3);
    auto grafite1 = make_shared<Grafite>(1.5, 10, "Duro");
    auto grafite2 = make_shared<Grafite>(2.0, 5, "Duro");
    auto grafite3 = make_shared<Grafite>(1.5, 10, "Duro");

    lapiseira.adicionaGrafite(grafite1);
    lapiseira.adicionaGrafite(grafite2);
    lapiseira.adicionaGrafite(grafite3);

    cout << lapiseira << endl;

    return 0;
}