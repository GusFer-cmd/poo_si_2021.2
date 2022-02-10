#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <set>

using namespace std;

class TweetException : public std::exception { //exception permite reagir a circustancias como (runtime_error)
private:
    string message;
public:
    TweetException(const string& message) : message(message) {} 

    const char* what() const throw() {
        return message.c_str();
    }
};

class Tweet{
private:
    int id;
    set<string> likes; //Remove duplicatas
    Tweet* retweet = nullptr;
    string text;
    string sender;
    bool deleted = false;

public:
    Tweet(int id, string text, string sender) : //Construtor de Tweet
        id(id), text(text), sender(sender) {}


    //Metodos
    //Getters
    int getId() const {
        return this->id;
    }

    string getText() const {
        return this->text;
    }

    string getSender() const {
        return this->sender;
    }

    void likes(string user) {
        likes.insert(user);
    }

    set<string> getLikes() const {
        return this->likes;
    }

    void retweet(Tweet* tweet) {
        this->retweet = tweet;
    }

    bool apagar() const {
        return this->deleted;
    }

    void set_apagar(){
        this->deleted = true;
        this->likes.clear();
        this->text = "Deletado";
    }

    void like(string username) {
        likes.insert(username);
    }

    //Friend (Operador de saída).
    friend ostream& operator<<(ostream& os, const Tweet& tweet){
        os << "Tweet: " << tweet.getId() << " - " << tweet.getText() << " - " << tweet.getSender() << endl;
        os << "Likes: ";
        for(auto& user : tweet.getLikes()){
            os << user << " ";
        }
        os << endl;
        return os;
    }

};

class Inbox {
private:
    string username;
    map<int, Tweet*> timeLine;
    map<int, Tweet*> myTweets;

public:
    Inbox() {} //Construtor de inicialização do Inbox

    void time_line(Tweet* tweet){ //Guarda o tweet na timeline
        this->timeLine[tweet->getId()] = tweet;
    }

    void my_tweets(Tweet* tweet){ //Guarda os meus tweets
        this->myTweets[tweet->getId()] = tweet;
    }

    Tweet* getTweet(int id){ //Retorna o tweet
        auto it = timeLine.find(id); //Procura o tweet na timeline
        if(it == timeLine.end()){ //Se não encontrar
            throw TweetException("Tweet nao encontrado");
        return it->second;
        }
    }

    void rmTweet(const string& username){ //Remove o tweet
        vector<Tweet*> rm_tweets; //Vetor de tweets a serem removidos
        for (auto& tweet : timeLine){ //Percorre a timeline
            if(tweet.second->getSender() == username){ //Se o tweet for do usuário
                rm_tweets.push_back(tweet.second); //Adiciona o tweet ao vetor
            } 
        }

        for (auto& tweet : rm_tweets){
            timeLine.erase(tweet->getId());
        }
    }

    vector<Tweet*> get_timeLine() const { //Retorna a timeline
        vector<Tweet*> tweets; //Vetor de tweets
        for (auto& tweet : timeLine){ //Percorre a timeline
            tweets.push_back(tweet.second); //Adiciona o tweet ao vetor
        }
        return tweets;
    }

    vector<Tweet*> get_myTweets() const { //Retorna os meus tweets
        vector<Tweet*> tweets; //Vetor de tweets
        for (auto& tweet : myTweets){ //Percorre a timeline
            tweets.push_back(tweet.second); //Adiciona o tweet ao vetor
        }
        return tweets;
    }

    friend ostream& operator<<(ostream& os, Inbox& inbox){
        os << "Timeline: " << endl;
        for (auto& tweet : inbox.get_timeLine()){
            os << *tweet << endl;
        }
        os << "Meus Tweets: " << endl;
        for (auto& tweet : inbox.get_myTweets()){
            os << *tweet << endl;
        }
        return os;
    }
};

class Usuario{
private:
    string username;
    Inbox inbox;
    map<string, Usuario*> followers;
    map<string, Usuario*> following;


bool follow(string username){
    auto it = following.find(username); //Procura o usuário
    if(it == following.end()){ //Se não encontrar
        throw TweetException("Voce nao segue esse usuario");
    return false;
    } else {
        throw TweetException("Voce ja segue esse usuario");
    }
    return true;
}

public:
    Usuario(string username) : username(username) {} //Construtor de Usuário

    void followUp(Usuario* users){ //Seguir um usuário
        auto it = users->username; 
        if (follow(it)){ //Se o usuário não estiver seguindo
            users->followers[this->username] = this; //Adiciona o usuário aos seguidores
            this->following[it] = users; //Adiciona o usuário aos seguidores
        }
        cout << "Voce segue " << it << endl; 
    }

    Inbox& getInbox(){ //Retorna a Inbox
        return this->inbox;
    }

    void sendTweet(Tweet* tweet){
        this->inbox.time_line(tweet); //Adiciona o tweet na timeline
        this->inbox.my_tweets(tweet); //Adiciona o tweet aos meus tweets
    
        for (auto user : followers) {
            user.second->getInbox().time_line(tweet); //Adiciona o tweet aos seguidores
        }
    }

    void unFollow(Usuario* users){
        auto it = users->username; //Procura o usuário
        if(follow(it)){
            this->inbox.rmTweet(it); //Remove o tweet da timeline
            this->following.erase(it); //Remove o usuário dos seguidores
            users->following.erase(this->username); //Remove o usuário dos seguidores
        }   
    }

    void rmFollowers() {
        vector<Usuario*> rm_followers; //Vetor de usuários a serem removidos
        for (auto& user : followers){ //Percorre os seguidores
            rm_followers.push_back(user.second); //Adiciona o usuário ao vetor
        }
    }

    void rmFollowing(){
        vector<Usuario*> rm_following; //Vetor de usuários a serem removidos
        for (auto& user : following){ //Percorre os seguidores
            rm_following.push_back(user.second); //Adiciona o usuário ao vetor
        }
    }

    void atualizar(){
        auto timeline = this->inbox.get_timeLine(); //Pega a timeline
        for (auto& tweet : timeline){ //Percorre a timeline
            if (tweet->getSender() == this->username){
                tweet->set_apagar(); //Deleta o tweet
            }
        }
    }

    void like(int id){
        auto tweet = this->inbox.getTweet(id); //Pega o tweet
        tweet->like(this->username); //Adiciona o like
    }

    //Friend (Operador de saída)
    friend ostream& operator<<(ostream& os, const Usuario& user){
        
    }
};

template <typename T>
using ptr = shared_ptr<T>;

class Controller{
private:
    map<string, ptr<Usuario>> user;
    map<int, ptr<Tweet>> tweets;
    int nextId{0};

    Tweet* newTweet(string nome, string text){ //Cria um novo tweet
        auto tweet = make_shared<Tweet>(this->nextId, nome, text); //Cria um novo tweet
        tweets[this->nextId] = tweet; //Adiciona o tweet ao map de tweets
        this->nextId++; //Incrementa o id
        return tweet.get(); //Retorna o tweet
    }

public:
    Controller() : nextId(0) {} //Construtor de Controler 

    void addUser(string username){
    auto it = user.find(username); //Procura o usuário
        if(it == user.end()){ //Se não encontrar
            user[username] = make_shared<Usuario>(username); //Cria um novo usuário
        } else {
            throw TweetException("Usuario ja existe");
        }
    }

    Usuario* getUser(string username){
        auto it = user.find(username); //Procura o usuário
        if(it == user.end()){ //Se não encontrar
            throw TweetException("Usuario nao encontrado");
        } else {
        return it->second.get(); //Retorna o usuário
        }
    }

    void sendRtw(int id, string username){
        auto user = getUser(username); //Pega o usuário
        auto tweetRtw = user->getInbox().getTweet(id); //Pega o tweet
        auto Newtweet = newTweet(tweetRtw->getSender(), tweetRtw->getText()); //Cria um novo tweet
        user->sendTweet(Newtweet); //Envia o tweet
    }

    void sendTweet(string username, string text){
        auto user = getUser(username); //Pega o usuário
        auto tweet = newTweet(username, text); //Cria um novo tweet
        user->sendTweet(tweet); //Envia o tweet
    }

    void rmUsername(string username){
        auto it = user.find(username); //Procura o usuário
        if(it == user.end()){ //Se não encontrar
            throw TweetException("Usuario nao encontrado");
        } else {
            user.erase(it); //Remove o usuário
        }
    }

    friend ostream& operator<<(ostream& os, const Controller& controller){
        for (auto& user : controller.user){
            os << *user.second << endl;
        }
        return os;
    }
};

int main(){

    Controller twitter;

    while(true){
        try {
            string cmd{};
            cin >> cmd;
        
            if (cmd == "logout"){
                break;
            }

            else if (cmd == "addUser"){
                string username{};
                cin >> username;
                twitter.addUser(username);
            }

            else if (cmd == "rmUsername"){
                string username{};
                cin >> username;
                twitter.rmUsername(username);
            }
        
            else if (cmd == "show"){
                cout << twitter << endl;
            }
        
            else if (cmd == "like"){
                string username{};
                int id{};
                cin >> username >> id;
                twitter.getUser(username)->like(id);
            }

            else if (cmd == "follow"){
                string sender{}, receiver{};
                cin >> sender >> receiver;
                twitter.getUser(sender)->followUp(twitter.getUser(receiver));
            }

            else if (cmd == "unfollow"){
                string sender{}, receiver{};
                cin >> sender >> receiver;
                twitter.getUser(sender)->unFollow(twitter.getUser(receiver));
            }

            else if (cmd == "Text"){
                string username{}, text{};
                cin >> username;
                getline(cin, text);
                twitter.sendTweet(username, text);
            }
            
            else if (cmd == "timeline"){
                string username{};
                cin >> username;
                cout << twitter.getUser(username)->getInbox() << endl;
            }

            else if (cmd == "rtw"){
                string username{}, text{};
                int id{};
                cin >> username >> id;
                getline(cin, text);
                twitter.sendRtw(id, username);
            }

            else {
                cout << "Comando invalido" << endl;
            }

        } catch (TweetException& e){
            cout << e.what() << endl;
        }
        cout << endl;
    }
    return 0;
}