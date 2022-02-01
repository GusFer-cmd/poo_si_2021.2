#include <iostream>

using namespace std;


class veiculo {
    private:
        string nome;
        string marca;
    
    public:
        int velocidade;
        int roda;

    veiculo(string nome, string marca, int velocidade, int roda) :
        nome(nome), marca(marca), velocidade(velocidade), roda(roda) {
            cout << this->nome << " Veiculo criado e da marca " << this->marca << endl;
        }

    virtual ~veiculo() {
        cout << this->nome << " Veiculo destruido" << endl;
    }

    virtual void setNome(string nome) {
        this->nome = nome;
    }

    virtual string getNome() {
        return nome;
    }

    virtual void setMarca(string marca) {
        this->marca = marca;
    }

    virtual string getMarca() {
        return marca;
    }

    virtual void setVelocidade(int velocidade) {
        this->velocidade = velocidade;
    }

    virtual int getVelocidade() {
        return velocidade;
    }

    virtual void setRoda(int roda) {
        this->roda = roda;
    }

    virtual int getRoda() {
        return roda;
    }

    friend ostream& operator<<(ostream& os, veiculo& v) {
        os << v.getNome() << " : " << v.getMarca() << " : " << v.getVelocidade() << " : " << v.getRoda() << endl;
        return os;
    }
};

class carro : public veiculo{
    string plate;
    string brand;

public:
    bool numPortas{true};

    carro(string nome, string marca, int velocidade, int roda, string plate, string brand) :
        veiculo(nome, marca, velocidade, roda), plate(plate), brand(brand) {
        }

    virtual ~carro() {
        cout << this->plate << " destruido" << endl;
    }

    virtual bool getNumPortas() const{
        return numPortas;
    }

    virtual string getPlate() const{
        return plate;
    }

    virtual string getBrand() const{
        return brand;
    }

    friend ostream& operator<<(ostream& os, const carro& c) {
        os << c.getPlate() << " : "  << c.getBrand() << " : " << (c.numPortas ? "Duas portas" : "Quatro portas");
        return os;
    }
};

class moto : public veiculo{
    int plates;
    string brands;

public:
    moto(int plates, string brands, string nome, string marca, int velocidade, int roda) :
        veiculo(nome, marca, velocidade, roda), plates(plates), brands(brands) {
        }

    virtual ~moto() {
        cout << this->plates << " destruido" << endl;
    }

    virtual int getPlates() const{
        return plates;
    }

    virtual string getBrands() const{
        return brands;
    }

    friend ostream& operator<<(ostream& os, const moto& m) {
        os << m.getBrands() << " : " << m.getPlates() << endl;
        return os;
    }
};

int main() {

    carro carro("Carro", "Ford", 200, 4, "ABC-1234", "Ford");
    cout << carro << endl;

    moto moto( 2, "Yamaha", "Moto", "Yamaha", 100, 2);
    cout << moto << endl;
}
