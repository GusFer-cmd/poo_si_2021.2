#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <sstream>

using namespace std;

template <typename T>
using ptr = shared_ptr<T>;

//guardar o texto e o usuario
//Interface (I)
class IMsg{
public:
    virtual string getSender() = 0;
    virtual string getText() = 0;
    virtual ~IMsg() {}
    friend ostream& operator<<(ostream& os, IMsg& msg);
};       
ostream& operator<<(ostream& os, IMsg& msg) {
    os << msg.getSender() << ":" << msg.getText();
    return os;
}

class Msg : public IMsg {
    string sender;
    string text;
public:
    Msg(string sender, string text) {
        this->sender = sender;
        this->text = text;
    }
    virtual string getSender() override {
        return sender;
    }
    virtual string getText() override {
        return text;
    }
};

//Aplicando conceito de herança
class MsgPremium : public Msg {
    bool read{false};
public:
    MsgPremium(string sender, string text) : Msg(sender, text) {}
    
    virtual string getText() override {
        read = true;
        return Msg::getText();
    }
    
    virtual string inspect() {
        return Msg::getText();
    }
    
    virtual bool getRead() {
        return read;
    }
};

//guardar, recuperar e enviar as mensagens
class User{
    string username;
protected:
    vector<ptr<IMsg>> inbox;
    vector<ptr<IMsg>> sent;
public:
    User(string username) : username(username){}

    virtual void sendMsg(User* receiver, string text) {
        auto msg = make_shared<Msg>(this->username, text);
        receiver->inboxStore(msg);
        this->sent.push_back(msg);
    }

    virtual void inboxStore(ptr<IMsg> msg) {
        inbox.push_back(msg);
    }

    virtual string getInbox() {
        stringstream ss;
        for (auto msg : this->inbox)
            ss << *msg << endl;
        this->inbox.clear();
        return ss.str();
    }

    virtual string getSent() {
        stringstream ss;
        for (auto msg : this->sent)
            ss << *msg << endl;
        return ss.str();
    }
    
    virtual string getUsername() {
        return username;
    }
    virtual ~User() {}	
}; 

//Aplicando os conceitos de herança
class UserPremium : public User {
public:    
    UserPremium(string username) : User(username) {}
    virtual void sendMsg(User* receiver, string text) {
        auto msg = make_shared<MsgPremium>(this->getUsername(), text);
        receiver->inboxStore(msg);
        this->sent.push_back(msg);
    }

    virtual string getSent() {
        stringstream ss;
        for (auto msg : this->sent) {
            auto premium = dynamic_cast<MsgPremium*>(msg.get());
            if (premium){
                ss << premium->getSender() << ":" << premium->inspect() << ":" << (premium->getRead() ? "Lido" : "unread") << endl;
            } else {
                ss << *msg << endl;
            }
        }
        return ss.str();
    }
};

//encontrar e gerenciar os usuarios
class UserManager {
    map<string, ptr<User>> users;

public:
    UserManager() {}

    void addUser(string username) {
        if (users.find(username) == users.end()) {
            users[username] = make_shared<User>(username);
        } else {
            throw runtime_error("User" + username + "already exists");
        }
    }
    
     void addPremium(string username) {
        if (users.find(username) == users.end()) {
            users[username] = make_shared<UserPremium>(username);
        } else {
            throw runtime_error("User" + username + "already exists");
        }
    }

    string getUsername(){ //Pegar os usuários registrados
        string result;
        for (auto& user : users) {
            result += user.first + " ";
        }
        return result;
    }

    User* findUser(string username) { //obter usuários
        auto it = users.find(username);
        if (it == users.end())
            throw runtime_error("User" + username + "not found");
        return it->second.get();
    }

    void sendMsg(string sender, string receiver, string text) {
        auto senderUser = findUser(sender); //procura o objeto.        
        auto receiverUser = findUser(receiver); //emissário
        senderUser->sendMsg(receiverUser, text);
    }
};

    template <typename T>
    T read(stringstream& ss) {
        T t;
        ss >> t;
        return t;
    }
    
    template <typename... Args>
    auto parse(istream& is) {
        tuple<Args...> t;
        apply([&is](auto&&... args) {((is >> args), ...);}, t);
        return t;   
    }    

int main() {
    UserManager um;

    while(true) {
        string line{}, cmd{};
        getline(cin, line);
        stringstream ss(line);
        ss >> cmd;
        cout << "$" << line << '\n';
        if (cmd == "end") {
            break;
        } else if (cmd == "show") {
            cout << um.getUsername() << endl;
        } else if (cmd == "add") {
            um.addUser(read<string>(ss));
        } else if (cmd == "premium") {
            um.addPremium(read<string>(ss));
        } else if (cmd == "send") {
            string sender = read<string>(ss);
            string receiver = read<string>(ss);
            string text{};
            getline(ss, text);
            um.sendMsg(sender, receiver, text.substr(1));
        } else if (cmd == "sent") {
            cout << um.findUser(read<string>(ss))->getSent() << endl;    
        } else if (cmd == "inbox") {    
            cout << um.findUser(read<string>(ss))->getInbox() << endl;
        } else {
            cout << "fail: Unknown command " << '\n';
        }
    }
    return 0;
}
