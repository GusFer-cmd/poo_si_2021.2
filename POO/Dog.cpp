#include <iostream>


class Animal {
    bool alive {true};
    std::string type;
public:
    Animal(std::string type = "bacteria"): type(type) {
        std::cout << this->type << " created" << std::endl;
    }
    ~Animal() {
        std::cout << this->type << " destroyed" << std::endl;
    }
    bool isAlive() {
        return alive;
    }
    void die() {
        alive = false;
    }
    std::string getType() {
        return type;
    }
    friend std::ostream& operator<<(std::ostream& os, const Animal& animal) {
        os << animal.type << ":" << (animal.alive ? "alive" : "dead");
        return os;
    }
};

class Pet : public Animal {
    std::string name;
public:
    Pet(std::string name, std::string type): Animal(type), name(name) {
        std::cout << this->name << " created" << std::endl;
    }
    ~Pet() {
        std::cout << this->name << " destroyed" << std::endl;
    }
    std::string getName() {
        return name;
    }
};

int main() {
    Animal dog("dog");
    std::cout << dog << std::endl;
    dog.die();
    std::cout << dog << std::endl;
}