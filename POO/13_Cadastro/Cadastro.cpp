#include <iostream>
#include <vector>
#include <map>
#include <memory>

using namespace std;

class Conta{
protected:
    string clienteId;
    string type; //CC ou CP
    float saldo{0};
    int id;

public:
    Conta(string clienteId = "", int id = -1 ) : 
        clienteId(clienteId), id(id) {
    }

    //Metodos
    //Getters
    int getId(){
        return this->id;
    }

    float getSaldo(){
        return this->saldo;
    }

    string getClienteId(){
        return this->clienteId;
    }

    string getType(){
        return this->type;
    }

    virtual void monthupdate () = 0;

    virtual void saque(float valor){ //Saque
        if(valor <= 0){ //Valor da conta for menor que 0
            cout << "Valor invalido" << endl; 
        }

        if(valor > this->saldo){ 
            cout << "Saldo insuficiente" << endl;
        } else       

        cout << "Saque de R$ " << valor << " realizado com sucesso!" << endl;
        this->saldo -= valor; //Decrementa o saldo da conta
     }

    virtual void deposito(float valor){ //Deposito
        if(valor <= 0){ //Valor do deposito for menor que 0
            cout << "Valor invalido" << endl;
        }
    
        cout << "Deposito de R$ " << valor << " realizado com sucesso!" << endl;
        this->saldo += valor;//Incrementa o saldo da conta
     }

    virtual void transferir(shared_ptr<Conta> outraConta ,float valor){ //Transferência
        if (valor <= 0 || valor > this->saldo){ //Valor da transferência for menor ou maior que o limite
            cout << "Valor invalido" << endl;
        }

        if (outraConta == nullptr){ //Se a conta for nula
            cout << "Destinatario nao encontrado" << endl;
        } else {
            this->saldo -= valor; //Decrementa o saldo da conta origem
            outraConta->saldo += valor; //Incrementa o saldo da conta destinatária
            cout << "Transferencia de R$ " << valor << " realizada com sucesso!" << endl;
        }
    }     

    //Friend (Operador de saída)
    friend ostream& operator<<(ostream& os, const Conta& conta){
        os << conta.id << " : " << conta.clienteId << " : " << "R$" << conta.saldo << " : " << conta.type << endl;
        return os;
    }
};

//Herança
class ContaCorrente : public Conta{
public:
    ContaCorrente(string clienteId, int id) : Conta(clienteId, id) { //Construtor da Conta Corrente
        this->type = "CC"; //Tipo da conta
    };

    virtual void monthupdate(){
        this->saldo -= 20; //Desconta 20 reais de taxa mensal
    }
};

//Herança
class ContaPoupanca : public Conta{
public:
    ContaPoupanca(string clienteId, int id) : Conta(clienteId, id) { //Construtor da Conta Poupança
        this->type = "CP"; //Tipo da conta
    }

    virtual void monthupdate(){
        this->saldo += 0.01 * this->saldo; //Incrementa 1% do saldo
    }
};

class Cliente {
private:
    string clienteId;
    vector<shared_ptr<Conta>> contas;
public:
    Cliente(string clienteId = " ") : clienteId(clienteId) { //Construtor de Cliente
    }

    //Metodos
    void addConta(shared_ptr<Conta> conta){
        this->contas.push_back(conta); //Adiciona a conta ao vetor de contas
    }

    //Getters e Setters
    string getClienteId(){
        return clienteId;
    }

    vector<shared_ptr<Conta>> getContas(){
        return contas;
    }

    void setClientId(string clienteId){
        this->clienteId = clienteId;
    }

    //Friend (Operador de saída).
    friend ostream& operator<<(ostream& os, const Cliente& cliente){
        os << cliente.clienteId << endl;
        for(auto conta : cliente.contas){ //Percorre o vetor de contas
            os << *conta; //Imprime as contas
        }
        return os;
    }
};

class Agencia{
private:
    map<string, shared_ptr<Cliente>> clientes;
    map<int, shared_ptr<Conta>> contas;
    int nextAccountId{0};

    //Metodos
    shared_ptr<Conta> getConta(int id){
        auto it = this->contas.find(id); //Busca a conta pelo id
        if(it == this->contas.end()){ //Se não encontrar a conta
            cout << "Conta nao registrada no banco" << endl;
        }
        return it->second; //Retorna a conta
    }

    bool validarCliente(string nome){  //Valida o cliente pelo nome
        auto it = this->clientes.find(nome); //Busca o cliente pelo nome
        if(it == this->clientes.end()){ //Se não encontrar o cliente
            cout << "Cliente nao registrado no banco" << endl;
            return false;
        }
        return true; //Retorna true se o cliente existir
    }

    bool validarConta(int id){ //Valida a conta pelo id
        auto it = this->contas.find(id); //Busca a conta pelo id
        if(it == this->contas.end()){ //Se não encontrar a conta
            cout << "Conta nao registrada no banco" << endl;
            return false;
        }
        return true; //Retorna true se a conta existir
    }

public:
    Agencia() {} //Construtor de inicialização da Agencia

    void addCliente(string nome){
        if(validarCliente(nome)){ //Se o cliente já existir
            cout << "Cliente ja existe" << endl;
        } else {
            Cliente cliente(nome); //Cria um cliente
            ContaCorrente contaCorrente(nome, nextAccountId); //Cria uma conta corrente
            ContaPoupanca contaPoupanca(nome, nextAccountId); //Cria uma conta poupança

            cliente.addConta(make_shared<ContaCorrente>(contaCorrente)); //Adiciona a conta corrente ao vetor de contas do cliente
            cliente.addConta(make_shared<ContaPoupanca>(contaPoupanca)); //Adiciona a conta poupança ao vetor de contas do cliente
        
            this->clientes[nome] = make_shared<Cliente>(cliente); //Adiciona o cliente ao map de clientes
            this->contas[nextAccountId] = make_shared<ContaCorrente>(contaCorrente); //Adiciona a conta corrente ao map de contas
            this->contas[nextAccountId + 1] = make_shared<ContaPoupanca>(contaPoupanca); //Adiciona a conta poupança ao map de contas
            nextAccountId ++; //Incrementa o id da conta
        }
    }

    void saque(int id, float valor){
        if(validarConta(id) && valor > 0){
            this->getConta(id)->saque(valor); //Chama o metodo saque da conta
        } else {
            cout << "Saque nao realizado" << endl;
        }
    }

    void deposito(int id, float valor){
        if(validarConta(id)){
            this->getConta(id)->deposito(valor); //Chama o metodo deposito da conta
        } else {
            cout << "Deposito nao realizado" << endl;
        }
    }

    void transferencia(int idConta, int idOutraConta, float valor){
        if(validarConta(idConta) && validarConta(idOutraConta) && valor > 0){
            this->getConta(idConta)->transferir(this->getConta(idOutraConta), valor); //Chama o metodo transferencia da conta
        } else {
            cout << "Transferencia nao realizada" << endl;
        }
    }

    void monthupdate(){
        for(auto conta : this->contas){ //Percorre o map de contas
            conta.second->monthupdate(); //Chama o metodo monthupdate da conta
        }
    }

    //Friend (Operador de saída).
    friend ostream& operator<<(ostream& os, Agencia& agencia){
    os << "Contas: \n";
        for(auto conta : agencia.contas){ //Percorre o map de contas
            os << *conta.second; //Imprime as contas
            cout << "-----" << endl;
        }
    return os;
    }
};

int main() {

    Agencia agencia;

    agencia.addCliente("Gustavo");
    agencia.addCliente("Lucas");
    agencia.addCliente("Guilerme");


    agencia.deposito(0, 100);
    agencia.deposito(1, 150);
    agencia.deposito(2, 200);

    cout << agencia << endl;
    
    agencia.saque(0, 50);
    agencia.saque(1, 15);
    agencia.saque(2, 100);

    cout << agencia;

    agencia.transferencia(0, 1, 100);
    agencia.transferencia(1, 2, 50);
    agencia.transferencia(2, 0, 100);

    cout << agencia;

    return 0;











}