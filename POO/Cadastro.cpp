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
        Conta(int id, string clientId = "") :id(id), clientId(clientId) {
        }

        virtual void monthupdate() = 0;

        virtual void saque(float valor){
            if(valor <= 0){
                cout << "Valor invalido" << endl;
            }

            if(valor > this->balance){
                cout << "Saldo insuficiente" << endl;
            }            

            cout << "Saque de R$ " << valor << " realizado com sucesso!" << endl;
            this->balance -= valor;
        }

        virtual void deposito(float valor){
            if(valor <= 0){
                cout << "Valor invalido" << endl;
            }
    
            cout << "Deposito de R$ " << valor << " realizado com sucesso!" << endl;
            this->balance += valor;
        }

        virtual void transferir(shared_ptr<Conta> other ,float valor){
            this->saque(valor);
            other->deposito(valor);
        }

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

        friend ostream& operator<<(ostream& os, Conta& conta) {
            os << conta.getId() << ": " << conta.getClientId() << ": " << conta.getBalance() << ": " << conta.getType() << endl;
        }
};

class ChecandoConta : public Conta {
    public:
    ChecandoConta(int id, string clientId) : Conta(id, clientId) {
        this->type = "CC";
    }
    
    virtual void monthupdate(){
        this->balance -= 20;
    }
};

class SalvandoConta : public Conta {
    public:
    SalvandoConta(int id, string clientId) : Conta{id, clientId} {
    }
    
    virtual void monthupdate(){
        this->balance += this->balance * 0.1;
    }
};

class Cliente {
    private:
        string clientId;
        vector<shared_ptr<Conta>> contas;

    public:
        Cliente(string clientId = "") : clientId{clientId} {
        }
        
        virtual void addConta(const shared_ptr<Conta> &conta){
            this->contas.push_back(conta);
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
        map<string, shared_ptr<Cliente>> clientes;
        map<int, shared_ptr<Conta>> contas;
        int nexContaId{0};

        virtual shared_ptr<Conta> getConta(int id){
            auto it = this->contas.find(id);
            if(it == this->contas.end()){
                cout << "Conta nao registrada" << endl;
            }
            return it->second;
        }

    public:
        Agencia(){};

        virtual void addConta(string clientId){
            auto it = this->clientes.find(clientId);
            if(it != this->clientes.end()){
                cout << "Cliente registrado" << endl;
            }
        
            Cliente c{clientId};

            SalvandoConta sa{this->nexContaId, clientId};
            c.addConta(make_shared<SalvandoConta>(sa));
            this->contas[this->nexContaId] = make_shared<SalvandoConta>(sa);

            this->nexContaId++;

            ChecandoConta cc{this->nexContaId, clientId};
            c.addConta(make_shared<ChecandoConta>(cc));
            this->contas[this->nexContaId] = make_shared<ChecandoConta>(cc);

            this->clientes[clientId] = make_shared<Cliente>(c);
            this->nexContaId++;
        }

        virtual void saque(int id, float valor){
            shared_ptr<Conta> conta{getConta(id)};
            conta->saque(valor);
        }

        virtual void deposito(int id, float valor){
            shared_ptr<Conta> conta{getConta(id)};
            conta->deposito(valor);
        }

        virtual void transferir(int id, int id2, float valor){
            shared_ptr<Conta> conta{getConta(id)};
            shared_ptr<Conta> conta2{getConta(id2)};
            conta->transferir(conta2, valor);
        }

        virtual void monthupdate(){
            for(auto it = this->contas.begin(); it != this->contas.end(); it++){
                it->second->monthupdate();
            }
        }

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
