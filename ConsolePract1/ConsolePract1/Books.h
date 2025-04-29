#include <iostream>
#include <vector>
using namespace std;

class Book {
public:
    virtual void getInfo() const = 0;
    virtual ~Book() {}
};

class EBook : public Book {
public:
    void getInfo() const override { cout << "����������� �����" << endl; }
};

class PrintedBook : public Book {
public:
    void getInfo() const override { cout << "�������� �����" << endl; }
};

void bookDemo() {
    vector<Book*> books = {
        new EBook(),
        new PrintedBook()
    };

    for (auto b : books) {
        b->getInfo();
        delete b;
    }
}