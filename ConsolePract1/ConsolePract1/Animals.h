#include <iostream>
#include <vector>

using namespace std;

class Animal {
public:
    virtual void sound() const = 0;
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void sound() const override { cout << "Собака: гав" << endl; }
};

class Cat : public Animal {
public:
    void sound() const override { cout << "Кот: мяу" << endl; }
};

void animalDemo() {
    vector<Animal*> animals = {
        new Dog(),
        new Cat()
    };

    for (auto animal : animals) {
        animal->sound();
        delete animal;
    }
}