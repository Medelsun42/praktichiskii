#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>
#include <memory>

using namespace std;

// 1. Базовый класс Shape с area()
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {
        if (r <= 0) throw invalid_argument("Radius must be positive");
    }
    double area() const override { return 3.14159 * radius * radius; }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {
        if (w <= 0 || h <= 0) throw invalid_argument("Sides must be positive");
    }
    double area() const override { return width * height; }
};

// 2. Класс Animal с speak()
class Animal {
public:
    virtual void speak() const = 0;
    virtual ~Animal() = default;
};

class Dog : public Animal {
    string name;
public:
    Dog(const string& n) : name(n) {
        if (n.empty()) throw invalid_argument("Dog name cannot be empty");
    }
    void speak() const override { cout << name << " says Woof!" << endl; }
};

class Cat : public Animal {
    string name;
public:
    Cat(const string& n) : name(n) {
        if (n.empty()) throw invalid_argument("Cat name cannot be empty");
    }
    void speak() const override { cout << name << " says Meow!" << endl; }
};

// 3. Класс BankAccount с withdraw()
class BankAccount {
protected:
    double balance;
public:
    BankAccount(double b) : balance(b) {}
    virtual void withdraw(double amount) = 0;
    virtual ~BankAccount() = default;
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(double b) : BankAccount(b) {}
    void withdraw(double amount) override {
        if (amount > balance) throw runtime_error("Insufficient funds in savings account");
        balance -= amount;
    }
};

class CheckingAccount : public BankAccount {
public:
    CheckingAccount(double b) : BankAccount(b) {}
    void withdraw(double amount) override {
        if (amount > balance) throw runtime_error("Insufficient funds in checking account");
        balance -= amount;
    }
};

// 4. Класс FileHandler с open()
class FileHandler {
public:
    virtual void open(const string& filename) = 0;
    virtual ~FileHandler() = default;
};

class TextFileHandler : public FileHandler {
public:
    void open(const string& filename) override {
        ifstream file(filename);
        if (!file) throw runtime_error("Text file not found: " + filename);
        cout << "Text file opened successfully" << endl;
    }
};

class BinaryFileHandler : public FileHandler {
public:
    void open(const string& filename) override {
        ifstream file(filename, ios::binary);
        if (!file) throw runtime_error("Binary file not found: " + filename);
        cout << "Binary file opened successfully" << endl;
    }
};

// 5. Класс Shape с draw()
class DrawableShape {
public:
    virtual void draw() const = 0;
    virtual ~DrawableShape() = default;
};

class Triangle : public DrawableShape {
    double a, b, c;
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {
        if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a)
            throw invalid_argument("Invalid triangle sides");
    }
    void draw() const override { cout << "Drawing triangle" << endl; }
};

class Square : public DrawableShape {
    double side;
public:
    Square(double s) : side(s) {
        if (s <= 0) throw invalid_argument("Side must be positive");
    }
    void draw() const override { cout << "Drawing square" << endl; }
};

// 6. Класс Person с display()
class Person {
protected:
    string name;
    int age;
public:
    Person(const string& n, int a) : name(n), age(a) {
        if (n.empty()) throw invalid_argument("Name cannot be empty");
        if (a < 0 || a > 120) throw invalid_argument("Invalid age");
    }
    virtual void display() const = 0;
    virtual ~Person() = default;
};

class Student : public Person {
    string studentId;
public:
    Student(const string& n, int a, const string& id) : Person(n, a), studentId(id) {
        if (id.empty()) throw invalid_argument("Student ID cannot be empty");
    }
    void display() const override {
        cout << "Student: " << name << ", Age: " << age << ", ID: " << studentId << endl;
    }
};

class Teacher : public Person {
    string subject;
public:
    Teacher(const string& n, int a, const string& subj) : Person(n, a), subject(subj) {
        if (subj.empty()) throw invalid_argument("Subject cannot be empty");
    }
    void display() const override {
        cout << "Teacher: " << name << ", Age: " << age << ", Subject: " << subject << endl;
    }
};

// 7. Класс Calculator с calculate()
class Calculator {
public:
    virtual double calculate(double a, double b) const = 0;
    virtual ~Calculator() = default;
};

class Addition : public Calculator {
public:
    double calculate(double a, double b) const override { return a + b; }
};

class Division : public Calculator {
public:
    double calculate(double a, double b) const override {
        if (b == 0) throw runtime_error("Division by zero");
        return a / b;
    }
};

// 8. Класс Game с start()
class Game {
public:
    virtual void start() = 0;
    virtual ~Game() = default;
};

class Chess : public Game {
public:
    void start() override {
        cout << "Chess game started" << endl;
    }
};

class Tennis : public Game {
    int players;
public:
    Tennis(int p) : players(p) {
        if (p != 2 && p != 4) throw invalid_argument("Tennis requires 2 or 4 players");
    }
    void start() override {
        cout << "Tennis game started with " << players << " players" << endl;
    }
};

// 9. Класс Document с save()
class Document {
public:
    virtual void save(const string& filename) = 0;
    virtual ~Document() = default;
};

class PDFDocument : public Document {
public:
    void save(const string& filename) override {
        if (filename.empty()) throw invalid_argument("Filename cannot be empty");
        cout << "PDF document saved as " << filename << endl;
    }
};

class WordDocument : public Document {
public:
    void save(const string& filename) override {
        if (filename.empty()) throw invalid_argument("Filename cannot be empty");
        if (filename.find(".docx") == string::npos)
            throw invalid_argument("Word document must have .docx extension");
        cout << "Word document saved as " << filename << endl;
    }
};

// 10. Класс Matrix с getElement()
class Matrix {
protected:
    int rows, cols;
public:
    Matrix(int r, int c) : rows(r), cols(c) {
        if (r <= 0 || c <= 0) throw invalid_argument("Matrix dimensions must be positive");
    }
    virtual double getElement(int r, int c) const = 0;
    virtual ~Matrix() = default;
};

class IntMatrix : public Matrix {
    vector<vector<int>> data;
public:
    IntMatrix(int r, int c) : Matrix(r, c), data(r, vector<int>(c)) {}
    double getElement(int r, int c) const override {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            throw out_of_range("Matrix index out of range");
        return data[r][c];
    }
};

class FloatMatrix : public Matrix {
    vector<vector<float>> data;
public:
    FloatMatrix(int r, int c) : Matrix(r, c), data(r, vector<float>(c)) {}
    double getElement(int r, int c) const override {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            throw out_of_range("Matrix index out of range");
        return data[r][c];
    }
};

// Главная функция для тестирования
int main() {
    try {
        // Тестирование различных классов
        Circle circle(5);
        cout << "Circle area: " << circle.area() << endl;

        Dog dog("Rex");
        dog.speak();

        SavingsAccount sa(1000);
        sa.withdraw(500);

        TextFileHandler tfh;
        tfh.open("example.txt");

        Triangle triangle(3, 4, 5);
        triangle.draw();

        Student student("Alice", 20, "S12345");
        student.display();

        Division div;
        cout << "10 / 2 = " << div.calculate(10, 2) << endl;

        Tennis tennis(2);
        tennis.start();

        WordDocument wordDoc;
        wordDoc.save("document.docx");

        IntMatrix im(3, 3);
        cout << "Matrix element: " << im.getElement(1, 1) << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}