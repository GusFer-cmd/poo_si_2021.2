#include <iostream>
using namespace std;

struct Gato {
    string nome {""};
    int vidas {0};


    Gato& operator=(const Gato& gato) { //Atribuição por cópia.
        cout << "copiando de " << gato.nome << endl;
        this->nome = gato.nome + " copiado";
        this->vidas = gato.vidas;
        return *this;
    }

    Gato(const Gato& other): //Construtor Copy
        nome(other.nome + " copiado"), vidas(other.vidas) {
            cout << "Copia de " << other.nome << " nascendo" << endl;
        }

    Gato(string nome = "Gato", int vidas = 7) : //Lista de inicialização(:)
        nome{nome}, vidas{vidas} {
        cout << this->nome << " nascendo\n";
    }

    ~Gato() { //Destrutor, momento que a variável é destruida. (~)
        cout << this->nome << " morrendo\n"; 
    }
};
    void mostrar(Gato& gato) { //Referência para o gato original. (&)
        cout << gato.nome << " tem " << gato.vidas << " vidas\n";
    }



int main() {                              
        
    { //Escopo determina o tempo de vida.
    Gato fushi ("Fushi", 5); 
    mostrar(fushi);
    Gato yokai ("Yokai", 3);
    mostrar(yokai);
    Gato Lili ("Lili", 7);
    mostrar(Lili);    
    } //Escopo determina o tempo de vida.
    
    cout << "\n";

    {
    Gato naruto {"Naruto", 1};
    mostrar(naruto);
    Gato narutin {naruto}; //Copy constructor
    Gato clone = narutin;
    }

    cout << "\n";

    {
    Gato abacaxi {"Abacaxi", 7};
    Gato gaiato;
    gaiato = abacaxi; //Retorna atribuição pro cópia.
    }

    cout << "\n";

    {
    Gato siriguela {"Siriguela", 3};
    Gato& apelido {siriguela}; //apelido aponta para siriguela
    siriguela.vidas--;
    apelido.vidas--;
    {
        Gato& apelido2 {siriguela};
        auto& nome = apelido2.nome;
        nome = "Siri";
        Gato abacaxi {"Abacaxi", 7};
    }
    mostrar(siriguela);
    }
    
    cout << "\n";

    
}