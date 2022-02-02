#include <iostream>
#include <vector>
#include <list>
#include <memory>

using namespace std;

class Grafite {
    
    //Declarando variáveis
    public:
    float calibre;
    int tamanho;
    string dureza;

    //Construtor
    Grafite(float calibre, int tamanho, string dureza) : 
        calibre{calibre}, tamanho{tamanho}, dureza{dureza} {
    }

    //Friend (Operador de saída).
    friend ostream& operator<<(ostream& os, const Grafite& grafite) { //Constante posso usar "&"
        os << "Calibre: " << grafite.calibre << "mm, ";
        os << "Tamanho: " << grafite.tamanho << "mm, ";
        os << "Dureza: " << grafite.dureza << ".";
        return os;
    }
};

//Nova classe
class Lapiseira {
    //shared ptr 
    vector<shared_ptr<Grafite>> bico;
    list<shared_ptr<Grafite>> tambor; //Elemento independente

public:
    Lapiseira( int qtdGrafites) : bico(qtdGrafites, nullptr){ //Construtor da lapiseira
    }

    void adicionaGrafite(const shared_ptr<Grafite>& grafite) {
        this->tambor.push_back(grafite); //Colocar grafite no final do tambor.
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

    Lapiseira lapiseira(3);
    
    lapiseira.adicionaGrafite(make_shared<Grafite>(2.0, 5, "Dura"));
    lapiseira.adicionaGrafite(make_shared<Grafite>(1.5, 10, "Dura"));
    lapiseira.adicionaGrafite(make_shared<Grafite>(3.0, 7, "Dura"));

    lapiseira.colocarGrafite(0);
    lapiseira.colocarGrafite(1);
    lapiseira.colocarGrafite(2);
    lapiseira.colocarGrafite(0);

    lapiseira.removerGrafite(0);

    cout << lapiseira << endl;


    return 0;
}