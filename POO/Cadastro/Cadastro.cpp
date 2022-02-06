#include <iostream>
#include <map>
#include <vector>
#include <memory>

using namespace std;

class Conta {
protected:
    int id;
    float balance{0};
    string clientId;
    string type; //CC ou CP

public:
    Conta(int id, string clientId = "") :id(id), clientId(clientId) { //Construtor da Conta
    }

    virtual void monthupdate() = 0; //Mês update

    virtual void saque(float valor){ //Saque
        if(valor <= 0){ //Valor da conta for menor que 0
            cout << "Valor invalido" << endl; 
        }

        if(valor > this->balance){ 
            cout << "Saldo insuficiente" << endl;
        } else       

        cout << "Saque de R$ " << valor << " realizado com sucesso!" << endl;
        this->balance -= valor; //Decrementa o saldo da conta
     }

    virtual void deposito(float valor){ //Deposito
        if(valor <= 0){ //Valor do deposito for menor que 0
            cout << "Valor invalido" << endl;
        }
    
        cout << "Deposito de R$ " << valor << " realizado com sucesso!" << endl;
        this->balance += valor;//Incrementa o saldo da conta
     }

    virtual void transferir(shared_ptr<Conta> other ,float valor){ //Transferência
        this->saque(valor);
        other->deposito(valor);
    }

    //Metodos
    //Getters
    virtual int getId() {
        return this->id;
    }

    virtual float getBalance() {
        return this->balance;
    }

    virtual string getClientId() {
        return this->clientId;
    }

    virtual string getType() {
        return this->type;
    }

    //Friend (Operador de saída).
    friend ostream& operator<<(ostream& os, Conta& conta) {
        os << conta.getId() << ": " << conta.getClientId() << ": " << conta.getBalance() << ": " << conta.getType() << endl;
    }
};

//Herança
class ChecandoConta : public Conta {
public:
    ChecandoConta(int id, string clientId) : Conta(id, clientId) { //Construtor do Checando Conta
        this->type = "CC"; //Inicializa a conta com "CC" (Conta corrente).
    }
    
    virtual void monthupdate(){ //Update mensal
        this->balance -= 20;
    }
};

//Herança
class SalvandoConta : public Conta {
public:
    SalvandoConta(int id, string clientId) : Conta{id, clientId} { //Construtor do Salvando Conta
    }
    
    virtual void monthupdate(){ //Update mensal
        this->balance += this->balance * 0.1; //Rende 1% do saldo
    }
};

class Cliente {
private:
    string clientId;
    vector<shared_ptr<Conta>> contas; //Vetor de contas

public:
    Cliente(string clientId = "") : clientId{clientId} { //Construtor de Cliente
    }

    //Metodos
    //Getters e Setters    
    virtual void addConta(const shared_ptr<Conta> &conta){ //Adiciona conta
        this->contas.push_back(conta);//No final do vetor
    }

    virtual string getClientId() {
        return this->clientId;
    }

    virtual vector<shared_ptr<Conta>> getContas() {
        return this->contas;
    }

    virtual void setClientId(string newClientId) {
        this->clientId = newClientId;
    }

    virtual void setContas(vector<shared_ptr<Conta>> contas) {
        this->contas = contas;
    }

    //Friend (Operador de saída).
    friend ostream& operator<<(ostream& os, Cliente& cliente) {
        os << cliente.clientId << " [ " << endl;
        for (int i = 0; i < (int)cliente.contas.size(); i++){
            os << cliente.contas[i]->getClientId() << ((i+1 < (int)cliente.contas.size()) ? "," : "");
        }
        os << " ]" << endl;
        return os;
    }
};

class Agencia {
private:
    map<string, shared_ptr<Cliente>> clientes; //Map de clientes da agencia
    map<int, shared_ptr<Conta>> contas; //Map de contas da agencia
    int nexContaId{0};

    virtual shared_ptr<Conta> getConta(int id){ //Procura conta pelo Id
        auto it = this->contas.find(id);//Achou
        if(it == this->contas.end()){ //Não achou
            cout << "Conta nao registrada" << endl;
        }
        return it->second;
    }

    bool procurarCliente(string cliente) { //Procura cliente 
        auto it = clientes.find(cliente); //Cliente achado
        if(it == clientes.end()){ //Caso não achado
            cout << "Cliente nao registrado" << endl;
            return false;
        } else {
            return true;
        }
    }

public:
    Agencia(){};

    virtual void addConta(string clientId){ //Adiciona conta pelo ID do cliente
        auto it = this->clientes.find(clientId);//Procura conta do cliente
        if(it != this->clientes.end()){//Achado
            cout << "Cliente ja registrado" << endl;
        }
        
        Cliente c{clientId}; //Cria cliente

        SalvandoConta sa{this->nexContaId, clientId}; //Cria conta poupança
        c.addConta(make_shared<SalvandoConta>(sa)); //Adiciona conta como poupança
        this->contas[this->nexContaId] = make_shared<SalvandoConta>(sa);

        this->nexContaId++;

        ChecandoConta cc{this->nexContaId, clientId}; //Cria conta corrente
        c.addConta(make_shared<ChecandoConta>(cc)); //Adiciona conta como corrente
        this->contas[this->nexContaId] = make_shared<ChecandoConta>(cc);

        this->clientes[clientId] = make_shared<Cliente>(c);
        this->nexContaId++;
    }

    virtual void saque(int id, float valor){ //Realiza saque
        shared_ptr<Conta> conta{getConta(id)};
        conta->saque(valor);
    }

    virtual void deposito(int id, float valor){ //Realiza transferência
        shared_ptr<Conta> conta{getConta(id)};
        conta->deposito(valor);
    }

    virtual void transferir(int id, int id2, float valor){ //Realiza transferência
        shared_ptr<Conta> conta{getConta(id)};
        shared_ptr<Conta> conta2{getConta(id2)};
        conta->transferir(conta2, valor);
    }

    virtual void monthupdate(){ //Update mensal
        for(auto it = this->contas.begin(); it != this->contas.end(); it++){
            it->second->monthupdate();
        }
    }

    //Friend (Operador de saída).
    friend ostream &operator<<(ostream &os, Agencia &agencia) {
        os << "Clientes: " << endl;
        for(auto it = agencia.clientes.begin(); it != agencia.clientes.end(); it++){
            os << *it->second;
        }
            os << "Contas: " << endl;
            for(auto it = agencia.contas.begin(); it != agencia.contas.end(); it++){
                os << *it->second;
            }
            return os;
    }
};

int main() {

    Agencia banco;
    banco.addConta("Peter");
    banco.addConta("Gustavo");
    banco.addConta("Maria");
    cout << banco << endl;

    banco.deposito(0, 100);
    banco.deposito(1, 200);
    banco.deposito(2, 300);
    banco.saque(1, 50);
    cout << banco << endl;

    banco.transferir(0, 2, 50);
    cout << banco << endl;

    banco.monthupdate();

    cout << banco << endl;
}
