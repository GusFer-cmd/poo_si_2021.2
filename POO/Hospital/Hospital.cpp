#include <iostream>
#include <string>
#include <map>
#include <locale>
#include <iomanip>

using namespace std;


class Doutor; //Forward declaration

class Paciente{ //Paciente
public:
    virtual void addDoutor(Doutor * doutor) = 0;
    virtual void rmDoutor(Doutor * doutor) = 0;
    virtual string getNome() const = 0; 
    virtual string getDiagnos() const = 0;
    virtual map<string, Doutor*> &getDoutores() = 0;
};

class Doutor{ //Doutor
public:
    virtual void addPaciente(Paciente * paciente) = 0;
    virtual void rmPaciente(Paciente * paciente) = 0;
    virtual string getNome() const = 0;
    virtual string getEspecialidade() const = 0;
    virtual map<string, Paciente*> &getPacientes() = 0;
}; 

class Doc : public Doutor{ //
private:
    string name;
    string especialidade;
    map<string, Paciente*> pacientes;

public:
    Doc(string name, string especialidade) : name{name}, especialidade{especialidade} {} //Construtor de doutor

    //Metodos
    //Getters

    void addPaciente(Paciente * paciente) override{ //Adiciona paciente ao doutor
        this->pacientes[paciente->getNome()] = paciente;
    }

    void rmPaciente(Paciente * paciente) override{ //Remove paciente do doutor
        this->pacientes.erase(paciente->getNome());
    }

    string getNome() const override{ //Retorna nome 
        return this->name;
    }

    string getEspecialidade() const override{ //Retorna especialidade
        return this->especialidade;
    }

    map<string, Paciente *> &getPacientes() override{ //Retorna pacientes
        return this->pacientes;
    }

    //Friend (Operador de saída)
    friend ostream &operator<<(ostream &os, Doutor *doutor){
        string beginning = "Doc: " + doutor->getNome() + " - " + doutor->getEspecialidade() + " - ";
        os << beginning;

        os << setw(40 - beginning.length()) << "Pacientes: ";
        for (auto pacientes : doutor->getPacientes()){
            os << pacientes.second->getNome() << " ";
        }
    
        os << " ]";
        return os;
    }
};

//Herança paciente
class Ipaciente : public Paciente{
private:
    string nome;
    string diagnosticos;
    map<string, Doutor*> doutores;

public:
    Ipaciente(string nome, string diagnosticos) : nome{nome}, diagnosticos{diagnosticos} {} //Construtor de paciente

    //Metodos
    virtual void addDoutor(Doutor * doutor) override{ //Adiciona doutor ao paciente
        this->doutores[doutor->getNome()] = doutor;
    }

    virtual void rmDoutor(Doutor * doutor) override{ //Remove doutor do paciente
        this->doutores.erase(doutor->getNome());
    }

    //Getters
    string getNome() const override{ //Retorna nome
        return this->nome;
    }

    string getDiagnos() const override{ //Retorna diagnostico
        return this->diagnosticos;
    }

    map<string, Doutor*> &getDoutores() override{ 
        return this->doutores;
    }

    //Friend (Operador de saída)
    friend ostream &operator<<(ostream &os, Paciente *paciente){
        string beginning = "Paciente: " + paciente->getNome() + " - " + paciente->getDiagnos() + " - ";
        os << beginning;

        os << setw(40 - beginning.length()) << "Doutores: ";
        for (auto doutores : paciente->getDoutores()){
            os << static_cast<Doutor *>(doutores.second)->getNome() << " ";
        }
    
        os << " ]";
        return os;
    }
};

class Hospital {
private:
    map<string, Doutor *> doutores;
    map<string, Paciente *> pacientes;

public:

    Hospital(){} //Construtor de inicialização de Hospital

    //Metodos
    void addDoutor(string nome, string especialidade){ //Adiciona doutor ao hospital
        auto it = this->doutores.find(nome); //Procura o doutor
        if (it == this->doutores.end()){ //Se não existir
            Doutor *doutor = new Doc(nome, especialidade);
            this->doutores[nome] = doutor; //Ele cria
            cout << "Doutor " << nome << " adicionado com sucesso!" << endl;
            return;
        } else {
            cout << "Doutor " << nome << " já existe!" << endl; //Se já existir
            return;
        }
    }

    void addPaciente(string nome, string diagnosticos){//Adiciona paciente ao hospital
        auto it = this->pacientes.find(nome); //Procura o paciente
        if (it == this->pacientes.end()){ //Se não existir
            Paciente *paciente = new Ipaciente(nome, diagnosticos);
            this->pacientes[nome] = paciente; //Ele cria
            cout << "Paciente " << nome << " adicionado com sucesso!" << endl;
            return;
        } else {
            cout << "Paciente " << nome << " já existe!" << endl; //Se já existir
            return;
        }
    }

    void link(string nomeDoc, string nomePac){
        auto itDoc = this->doutores.find(nomeDoc); //Procura o doutor
        auto itPac = this->pacientes.find(nomePac); //Procura o paciente

        if (itDoc == this->doutores.end()){ //Se não existir doutor
            cout << "Doutor " << nomeDoc << " não existe!" << endl;
            return;
        }
        
        if (itPac == this->pacientes.end()){ //Se não existir paciente
            cout << "Paciente " << nomePac << " não existe!" << endl;
            return;
        }

        auto listDoutores = itPac->second->getDoutores(); //Lista de doutores do paciente
        for (auto doutor : listDoutores) {
            if (doutor.second->getEspecialidade() == itDoc->second->getEspecialidade()){ //Se o doutor tem a mesma especialidade
                cout << "Outros medicos irao atender o paciente" << endl;
                return;
            }
        }

        itPac->second->addDoutor(itDoc->second); //Adiciona doutor ao paciente
        itDoc->second->addPaciente(itPac->second); //Adiciona paciente ao doutor
        cout << "Paciente " << nomePac << " agora atendido por " << nomeDoc << endl;
    }

    void rmDoutor(string nome) {
        auto it = this->doutores.find(nome); //Procura o doutor
        if (it == this->doutores.end()){ //Se não existir
            cout << "Doutor " << nome << " não existe!" << endl;
            return;
        }

        for (auto paciente : it->second->getPacientes()){ //Percorre os pacientes do doutor
            paciente.second->rmDoutor(it->second); //Remove o doutor do paciente
        }

        this->doutores.erase(it); //Remove o doutor
        cout << "Doutor " << nome << " removido com sucesso!" << endl;
    }

    void rmPaciente(string nome) {
        auto it = this->pacientes.find(nome); //Procura o paciente
        if (it == this->pacientes.end()){ //Se não existir
            cout << "Paciente " << nome << " nao existe!" << endl;
            return;
        }

        for (auto doutor : it->second->getDoutores()){ //Percorre os doutores do paciente
            doutor.second->rmPaciente(it->second); //Remove o paciente do doutor
        }
    }


    //Friend (Operador de saída)
    friend ostream &operator<<(ostream &os, Hospital &hospital){
        os << "Hospital: " << endl;
        for (auto paciente : hospital.pacientes){
            os << static_cast<Paciente *>(paciente.second) << endl;
        }
    
        for (auto doutor : hospital.doutores){
            os << static_cast<Doutor *>(doutor.second) << endl;
        }
    
        return os;
    }
};

int main(){
    Hospital hosp;

    while (true){
        cout << endl;
        string cmd{""};
        cin >> cmd;

        try{
            if (cmd == "addDoutor"){
                string nome, especialidade;
                cin >> nome >> especialidade;
                hosp.addDoutor(nome, especialidade);
                continue;
            }

            if (cmd == "addPaciente"){
                string nome, diagnosticos;
                hosp.addPaciente(nome, diagnosticos);
                continue;
            }

            if (cmd == "link"){
                string nomeDoc, nomePac;
                cin >> nomeDoc >> nomePac;
                hosp.link(nomeDoc, nomePac);
                continue;
            }

            if (cmd == "rmMed") {
                string nome;
                cin >> nome;
                hosp.rmDoutor(nome);
                continue;
            }

            if (cmd == "rmPac"){
                string nome;
                cin >> nome;
                hosp.rmPaciente(nome);
                continue;
            }

            if (cmd == "show"){
                cout << hosp << endl;
                continue;
            }

            if (cmd == "clear"){
                continue;
            }

            if (cmd == "end"){
                exit(1);
            } else  {
                cout << "fali: unknown command" << endl;
            }
        } catch (runtime_error &e){
            cout << e.what() << endl;
        }
        
    } 
}