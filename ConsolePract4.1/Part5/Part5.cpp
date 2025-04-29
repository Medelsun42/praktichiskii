#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>
#include <memory>

using namespace std;

// 1. Абстрактный класс Shape с функцией area()
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

class Triangle : public Shape {
    double a, b, c;
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {
        if (a <= 0 || b <= 0 || c <= 0)
            throw invalid_argument("Sides must be positive");
        if (a + b <= c || a + c <= b || b + c <= a)
            throw invalid_argument("Invalid triangle sides");
    }
    double area() const override {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

// 2. Класс Employee с функцией calculateSalary()
class Employee {
protected:
    string name;
    double hours;
public:
    Employee(const string& n, double h) : name(n), hours(h) {
        if (h < 0) throw invalid_argument("Hours cannot be negative");
    }
    virtual double calculateSalary() const = 0;
    virtual ~Employee() = default;
};

class FullTimeEmployee : public Employee {
    double hourlyRate;
public:
    FullTimeEmployee(const string& n, double h, double rate)
        : Employee(n, h), hourlyRate(rate) {
        if (rate <= 0) throw invalid_argument("Rate must be positive");
    }
    double calculateSalary() const override {
        return hours * hourlyRate * 1.2; // 20% бонус
    }
};

class PartTimeEmployee : public Employee {
    double hourlyRate;
public:
    PartTimeEmployee(const string& n, double h, double rate)
        : Employee(n, h), hourlyRate(rate) {
        if (rate <= 0) throw invalid_argument("Rate must be positive");
    }
    double calculateSalary() const override {
        return hours * hourlyRate;
    }
};

// 3. Класс DataReader с функцией readData()
class DataReader {
public:
    virtual vector<string> readData(const string& filename) = 0;
    virtual ~DataReader() = default;
};

class CSVReader : public DataReader {
public:
    vector<string> readData(const string& filename) override {
        ifstream file(filename);
        if (!file.is_open())
            throw runtime_error("CSV file not found: " + filename);

        vector<string> lines;
        string line;
        while (getline(file, line)) {
            if (line.find(',') == string::npos)
                throw runtime_error("Invalid CSV format in file: " + filename);
            lines.push_back(line);
        }
        return lines;
    }
};

class XMLReader : public DataReader {
public:
    vector<string> readData(const string& filename) override {
        ifstream file(filename);
        if (!file.is_open())
            throw runtime_error("XML file not found: " + filename);

        vector<string> lines;
        string line;
        bool hasRoot = false;
        while (getline(file, line)) {
            if (line.find("<?xml") != string::npos) continue;
            if (line.find("<root>") != string::npos) hasRoot = true;
            lines.push_back(line);
        }

        if (!hasRoot)
            throw runtime_error("Invalid XML format - missing root element");
        return lines;
    }
};

// 4. Класс Shape с функцией scale()
class ScalableShape {
public:
    virtual void scale(double factor) = 0;
    virtual ~ScalableShape() = default;
};

class ScalableCircle : public ScalableShape {
    double radius;
public:
    ScalableCircle(double r) : radius(r) {
        if (r <= 0) throw invalid_argument("Radius must be positive");
    }
    void scale(double factor) override {
        if (factor <= 0) throw invalid_argument("Scale factor must be positive");
        radius *= factor;
    }
};

class Square : public ScalableShape {
    double side;
public:
    Square(double s) : side(s) {
        if (s <= 0) throw invalid_argument("Side must be positive");
    }
    void scale(double factor) override {
        if (factor <= 0) throw invalid_argument("Scale factor must be positive");
        side *= factor;
    }
};

class Polygon : public ScalableShape {
    vector<pair<double, double>> points;
public:
    Polygon(const vector<pair<double, double>>& pts) : points(pts) {
        if (pts.size() < 3) throw invalid_argument("Polygon needs at least 3 points");
    }
    void scale(double factor) override {
        if (factor <= 0) throw invalid_argument("Scale factor must be positive");
        for (auto& p : points) {
            p.first *= factor;
            p.second *= factor;
        }
    }
};

// 5. Класс BankAccount с функцией transfer()
class BankAccount {
public:
    double balance;
    BankAccount(double b) : balance(b) {
        if (b < 0) throw invalid_argument("Balance cannot be negative");
    }
    virtual void transfer(double amount, BankAccount& to) = 0;
    virtual ~BankAccount() = default;
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(double b) : BankAccount(b) {}
    void transfer(double amount, BankAccount& to) override {
        if (amount <= 0) throw invalid_argument("Amount must be positive");
        if (amount > balance * 0.9) // Не более 90% баланса
            throw runtime_error("Cannot transfer more than 90% of savings");
        balance -= amount;
        to.balance += amount;
    }
};

class CheckingAccount : public BankAccount {
public:
    CheckingAccount(double b) : BankAccount(b) {}
    void transfer(double amount, BankAccount& to) override {
        if (amount <= 0) throw invalid_argument("Amount must be positive");
        if (amount > balance)
            throw runtime_error("Insufficient funds");
        balance -= amount;
        to.balance += amount;
    }
};

// 6. Класс NetworkRequest с функцией send()
class NetworkRequest {
public:
    virtual void send(const string& data) = 0;
    virtual ~NetworkRequest() = default;
};

class HttpRequest : public NetworkRequest {
public:
    void send(const string& data) override {
        if (data.empty()) throw invalid_argument("Data cannot be empty");
        bool httpAvailable = false; // имитация
        if (!httpAvailable)
            throw runtime_error("HTTP connection failed");
        cout << "HTTP request sent: " << data.substr(0, 20) << "..." << endl;
    }
};

class FtpRequest : public NetworkRequest {
public:
    void send(const string& data) override {
        if (data.size() > 1024)
            throw invalid_argument("FTP data too large (max 1KB)");
        bool ftpAvailable = false; // имитация
        if (!ftpAvailable)
            throw runtime_error("FTP connection failed");
        cout << "FTP request sent: " << data.substr(0, 20) << "..." << endl;
    }
};

// 7. Класс Shape с функцией getBoundingBox()
class BoundedShape {
public:
    virtual void getBoundingBox(double& x1, double& y1, double& x2, double& y2) const = 0;
    virtual ~BoundedShape() = default;
};

class BoundedCircle : public BoundedShape {
    double x, y, radius;
public:
    BoundedCircle(double x, double y, double r) : x(x), y(y), radius(r) {
        if (r <= 0) throw invalid_argument("Radius must be positive");
    }
    void getBoundingBox(double& x1, double& y1, double& x2, double& y2) const override {
        x1 = x - radius;
        y1 = y - radius;
        x2 = x + radius;
        y2 = y + radius;
    }
};

class BoundedRectangle : public BoundedShape {
    double x1, y1, x2, y2;
public:
    BoundedRectangle(double x1, double y1, double x2, double y2)
        : x1(x1), y1(y1), x2(x2), y2(y2) {
        if (x1 >= x2 || y1 >= y2)
            throw invalid_argument("Invalid rectangle coordinates");
    }
    void getBoundingBox(double& x1, double& y1, double& x2, double& y2) const override {
        x1 = this->x1;
        y1 = this->y1;
        x2 = this->x2;
        y2 = this->y2;
    }
};

class BoundedPolygon : public BoundedShape {
    vector<pair<double, double>> points;
public:
    BoundedPolygon(const vector<pair<double, double>>& pts) : points(pts) {
        if (pts.size() < 3) throw invalid_argument("Polygon needs at least 3 points");
    }
    void getBoundingBox(double& x1, double& y1, double& x2, double& y2) const override {
        if (points.empty()) throw logic_error("No points in polygon");
        x1 = x2 = points[0].first;
        y1 = y2 = points[0].second;
        for (const auto& p : points) {
            x1 = min(x1, p.first);
            y1 = min(y1, p.second);
            x2 = max(x2, p.first);
            y2 = max(y2, p.second);
        }
    }
};

// 8. Базовый класс Exception и производные
class MyException : public exception {
protected:
    string message;
public:
    MyException(const string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class FileNotFoundException : public MyException {
public:
    FileNotFoundException(const string& filename)
        : MyException("File not found: " + filename) {
    }
};

class InvalidInputException : public MyException {
public:
    InvalidInputException(const string& details)
        : MyException("Invalid input: " + details) {
    }
};

class NetworkException : public MyException {
public:
    NetworkException(const string& details)
        : MyException("Network error: " + details) {
    }
};

// 9. Класс Task с функцией execute()
class Task {
public:
    virtual void execute() = 0;
    virtual ~Task() = default;
};

class PrintTask : public Task {
    string message;
public:
    PrintTask(const string& msg) : message(msg) {
        if (msg.empty()) throw invalid_argument("Print message cannot be empty");
    }
    void execute() override {
        cout << "Printing: " << message << endl;
    }
};

class EmailTask : public Task {
    string recipient, subject;
public:
    EmailTask(const string& rec, const string& subj)
        : recipient(rec), subject(subj) {
        if (rec.empty() || subj.empty())
            throw invalid_argument("Recipient and subject cannot be empty");
        if (rec.find('@') == string::npos)
            throw invalid_argument("Invalid email address");
    }
    void execute() override {
        cout << "Sending email to: " << recipient << endl;
    }
};

class DatabaseTask : public Task {
    string query;
public:
    DatabaseTask(const string& q) : query(q) {
        if (q.empty()) throw invalid_argument("Query cannot be empty");
        if (q.find("SELECT") == string::npos && q.find("INSERT") == string::npos)
            throw invalid_argument("Invalid SQL query");
    }
    void execute() override {
        cout << "Executing database query: " << query.substr(0, 20) << "..." << endl;
    }
};

// 10. Класс Shape с функцией rotate()
class RotatableShape {
public:
    virtual void rotate(double angle) = 0;
    virtual ~RotatableShape() = default;
};

class RotatableCircle : public RotatableShape {
public:
    void rotate(double angle) override {
        if (isnan(angle)) throw invalid_argument("Angle cannot be NaN");
        // Вращение круга не изменяет его
    }
};

class RotatableSquare : public RotatableShape {
public:
    void rotate(double angle) override {
        if (fmod(angle, 90) != 0)
            throw invalid_argument("Square can only be rotated by 90 degree increments");
    }
};

class RotatableTriangle : public RotatableShape {
public:
    void rotate(double angle) override {
        if (angle < 0 || angle > 360)
            throw invalid_argument("Angle must be between 0 and 360 degrees");
    }
};

int main() {
    try {
        // Тестирование классов
        Circle circle(5.0);
        cout << "Circle area: " << circle.area() << endl;

        FullTimeEmployee emp("John", 160, 25.0);
        cout << "Salary: " << emp.calculateSalary() << endl;

        CSVReader csvReader;
        auto data = csvReader.readData("data.csv");

        Square square(4.0);
        square.scale(1.5);

        SavingsAccount sa(1000);
        CheckingAccount ca(500);
        sa.transfer(100, ca);

        HttpRequest httpReq;
        httpReq.send("GET /index.html HTTP/1.1");

        BoundedCircle bc(0, 0, 5);
        double x1, y1, x2, y2;
        bc.getBoundingBox(x1, y1, x2, y2);

        PrintTask printTask("Hello World");
        printTask.execute();

        RotatableSquare rotSquare;
        rotSquare.rotate(90);

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}