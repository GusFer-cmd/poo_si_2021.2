#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <set>
#include <sstream>
#include "auxiliar.hpp"

using namespace std;

template <typename T>
using ptr = shared_ptr<T>;

class Message{
    int id;
    string username;
    string msg;
    set<string> likes;

public:
    Message(int id, string username, string msg) :
        id(id), username(username), msg(msg) {    
    } 
    
    int getId() { return id; }

    void like(string username) { 
        likes.insert(username); 
    }

    friend ostream& operator<<(ostream& os, Message& message){
        os << message.getId() << ":" << message.username + " ("
            << message.msg << ")";
        if(message.likes.size() > 0)
            os << ", " << aux::format(message.likes);
        return os;    
    }
};

class Inbox{
    map<int, Message*> unread;
    map<int, Message*> allMsgs;
public:
    Inbox() {}
    vector<Message*> getUnread() {
        auto result = aux::get_values(unread);
        unread.clear();
        return result;
    }
    vector<Message*> getAll() const {
        return aux::get_values(allMsgs);
    }

    Message* getTweet(int id) {
        if(allMsgs.find(id) == allMsgs.end())
            throw runtime_error("Fail: Tweet nao existe");
        return allMsgs[id]; 
    }

    friend ostream& operator<<(ostream& os, Inbox& inbox){
        os << aux::join_ptr(inbox.getAll(), "\n");
        return os;
    }

    void storeUnread(Message* tweet) {
        unread[tweet->getId()] = tweet;
        allMsgs[tweet->getId()] = tweet;
    }

    void storeReaded(Message* tweet) {
        allMsgs[tweet->getId()] = tweet;
    }
};

class User {
    Inbox inbox;
    string username;
    map<string, User*> followers;
    map<string, User*> following;
public:
    void mandarTweet(Message * msg) {
        inbox.storeReaded(msg);
        for (auto& follower : followers) {
            follower.second->inbox.storeUnread(msg);
        }
    }

    User(string& username) : username(username) {}

    void follow(User * other) {
        if(other == this)
            throw runtime_error("Fail: nao pode seguir a si mesmo");
        if(following.find(other->username) != following.end())
            throw runtime_error("Fail: Voce ja segue esse usuario");
        following[other->username] = other;
        other->followers[username] = this;
    }
    void unfollow(string username) {
        if(following.find(username) == following.end())
            throw runtime_error("Fail: Voce nao segue esse usuario");
        auto other = following[username];
        following.erase(username);
        other->followers.erase(username);
    }

    void like(int twitterId) {
        inbox.getTweet(twitterId)->like(username);
    }

    Inbox& getInbox() {
        return inbox;
    }

    friend ostream& operator<<(ostream& os, User& user){
        os << user.username << "\n"
            << " Seguidos" << aux::format(aux::get_keys(user.following)) << "\n"
            << " Seguidores " << aux::format(aux::get_keys(user.followers));
        return os;
    }   
};

class Controller {
    map<string, ptr<User>> users;
    map<int, ptr<Message>> tweets;
    int nextTweetId {0};

    Message* createMsg(string username, string msg){
        auto twObj = make_shared<Message>(nextTweetId++, username, msg);
        tweets[twObj->getId()] = twObj;
        return twObj.get();
    }

public:
    Controller() {}

    void addUser(string username) {
        if(users.find(username) != users.end())
            throw runtime_error("Fail: Usuario ja existe");
        users[username] = make_shared<User>(username);
    }
    User* getUser(string username){
        if(users.find(username) == users.end())
            throw runtime_error("Fail: Usuario nao encontrado");
        return users[username].get();
    }
    void sendTweet(string username, string msg) {
        auto sender = getUser(username);
        auto tw = createMsg(username, msg);
        sender->mandarTweet(tw);
    }

    friend ostream& operator<<(ostream& os, Controller& controller);
};

ostream& operator<<(ostream& os, Controller& controller){
        return os << aux::join(controller.users, "\n", aux::fn_map_values_ptr);
}

vector<string>getcmd() {
    string line;
    getline(cin, line);
    cout << "$" << line << '\n';
    return aux::split(line, ' ');
}

int main() {
    Controller sistema;

    while(true) {
        auto param = getcmd();
        auto cmd = param[0];
            if (cmd == "end") {
                break;
            } else if (cmd == "add") {
                sistema.addUser(param[1]);
            } else if (cmd == "show") {
                cout << sistema << '\n';
            } else if (cmd == "follow") {
                sistema.getUser(param[1])->follow(sistema.getUser(param[2]));
            } else if (cmd == "unfollow") {
                sistema.getUser(param[1])->unfollow(param[2]);
            } else if (cmd == "twittar") {
                auto msg = aux::slice(param, 2);
                sistema.sendTweet(param[1], aux::join(msg, " "));
            } else if (cmd == "like") {
                sistema.getUser(param[1])->like(std::stoi(param[2]));
            } else if (cmd == "unread") {
                auto msgs = sistema.getUser(param[1])->getInbox().getUnread();
                    cout << aux::join_ptr(msgs, "\n") << '\n';
            } else if (cmd == "timeline") {
                auto msgs = sistema.getUser(param[1])->getInbox().getAll();
                    cout << aux::join_ptr(msgs, "\n") << '\n';
            } else {
                cout << "fail: comando invalido" << '\n';
            } 
    }
    return 0;
}