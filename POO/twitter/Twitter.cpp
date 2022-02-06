#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <utility>

using namespace std;

class Message{
private:
    int id;
    string username;
    string msg;
    set<string> likes; //Usa set pra eleminar repetidos
    int getId();

public:
    Message(int id = 0, string username = " ", string msg = " "): //Construtor de Message
        id(id), username(username), msg(msg){}

    //Metodos
    virtual void like(string username){
        if(likes.find(username) != likes.end()){
            likes.insert(username);
            return;
        }
        throw runtime_error("fail: User " + username + " curtiu");
    }

    int getId() { return id; }

    //Friend (Operador de saída)
    friend iostream &operator<<(iostream &os, Message &msg){
    os << msg.id << ": " << msg.username << "( " << msg.msg << " )";
    int msgs = msg.likes.size();
    if(msgs > 0){
        int cout = 1;
        os << "[ ";
        for(auto user : msg.likes){
            if(cout >= msgs){
                os << user;
                break;
            }
            os << user << ", ";
            cout++;
        }
        os << " ]";
    }
    return os;
    }
};