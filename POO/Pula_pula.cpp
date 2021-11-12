#include <iostream>
#include <vector>
#include <list>
#include <memory>

using namespace std;

class Kid {
    public:
    int idade;
    string nome;
    
    Kid(string nome = "", int idade = 0) :
        nome{nome}, idade{idade} {    
    }

    friend ostream& operator<<(ostream& os, const Kid& kid) {
        os << "Nome: " << kid.nome << ", "; 
        os << "Idade: " << kid.idade << " anos\n";
        return os;
    }  
}; 

class Pula_Pula {
    vector<shared_ptr<Kid>> brincando;
    list<shared_ptr<Kid>> esperando; 
    
public:
    Pula_Pula( int qtdBrinquedos) : brincando(qtdBrinquedos, nullptr){
    }

    void entrar(const shared_ptr<Kid>& k) {
        this->esperando.push_back(k);
    }

    bool chamarBrinquedo(int indice) {
        if (indice < 0 || indice >= this->brincando.size()) {
            cout << "Brinquedo fechado\n";
            return false;
        }
        if (this->brincando[indice] != nullptr) {
            cout << "Brinquedo ocupado\n";
                return false;
        }
        if (this->esperando.empty()) {
            cout << "Sem criancas\n";
            return false;
        }
        this->brincando[indice] = this->esperando.front();
        this->esperando.pop_front();
        return true;
    }

    bool finalizarRodada(int indice) {
        if (indice < 0 || indice >= this->brincando.size()) {
            cout << "Brinquedo fechado\n";
            return false;
        }
        if (this->brincando[indice] == nullptr) {
            cout << "Brinquedo vazio\n";
            return false;
        }
        this->esperando.push_back(this->brincando[indice]); //Quando acabar a rodada, a criança volta para a fila de espera.
        this->brincando[indice] = nullptr;
        return true;
    }

    friend ostream& operator<<(ostream& os, const Pula_Pula& p) {
        os << "Brincando: | ";
        for (int i = 0; i < (int) p.brincando.size(); i++) {
            auto& brincando = p.brincando[i];
            os << i << ":" ;
            if (brincando != nullptr) {
                os << *brincando;
            } else {
                os << "-----";
            os << " | ";
            }
        }
        os << "\nEsperando: | ";
        for (auto esperando : p.esperando) {
            os << *esperando << " ";
        }
        return os;
    }

};

int main() {
    Pula_Pula pula_pula(3);
    pula_pula.entrar(make_shared<Kid>("Joao", 10));
    pula_pula.entrar(make_shared<Kid>("Maria", 5));
    pula_pula.entrar(make_shared<Kid>("Pedro", 7));
    pula_pula.entrar(make_shared<Kid>("Jose", 8));
    pula_pula.entrar(make_shared<Kid>("Paulo", 9));

    pula_pula.chamarBrinquedo(0);
    pula_pula.chamarBrinquedo(1);
    pula_pula.chamarBrinquedo(2);
    pula_pula.chamarBrinquedo(0); // Brinquedo ocupado

    pula_pula.finalizarRodada(0);
    pula_pula.finalizarRodada(1);

    cout << pula_pula << endl;

    return 0;
}