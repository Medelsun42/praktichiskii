#include <iostream>
#include <vector>
using namespace std;

class Person {
public:
    virtual void introduce() const = 0;
    virtual ~Person() {}
};

class Student : public Person {
public:
    void introduce() const override { cout << "� �������" << endl; }
};

class Teacher : public Person {
public:
    void introduce() const override { cout << "� �������������" << endl; }
};

void personDemo() {
    vector<Person*> people = {
        new Student(),
        new Teacher()
    };

    for (auto p : people) {
        p->introduce();
        delete p;
    }
}