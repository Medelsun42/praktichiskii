#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>
#include <memory>

using namespace std;

// 1. Класс User с функцией login()
class User {
protected:
    string username;
    bool isLoggedIn;
public:
    User(const string& name) : username(name), isLoggedIn(false) {}
    virtual void login(const string& password) = 0;
    virtual ~User() = default;
};

class AdminUser : public User {
public:
    AdminUser(const string& name) : User(name) {}
    void login(const string& password) override {
        if (isLoggedIn) {
            throw runtime_error("Admin user already logged in");
        }
        if (password != "AdminSecure123") {
            throw invalid_argument("Invalid admin password");
        }
        isLoggedIn = true;
        cout << "Admin " << username << " logged in successfully" << endl;
    }
};

class RegularUser : public User {
public:
    RegularUser(const string& name) : User(name) {}
    void login(const string& password) override {
        if (isLoggedIn) {
            throw runtime_error("User already logged in");
        }
        if (password.length() < 8) {
            throw invalid_argument("Password must be at least 8 characters");
        }
        isLoggedIn = true;
        cout << "User " << username << " logged in successfully" << endl;
    }
};

// 2. Класс Payment с функцией process()
class Payment {
protected:
    double amount;
public:
    Payment(double amt) : amount(amt) {
        if (amt <= 0) throw invalid_argument("Amount must be positive");
    }
    virtual void process() = 0;
    virtual ~Payment() = default;
};

class CreditCardPayment : public Payment {
    string cardNumber;
    string expiryDate;
public:
    CreditCardPayment(double amt, const string& num, const string& exp)
        : Payment(amt), cardNumber(num), expiryDate(exp) {
        if (num.length() != 16) throw invalid_argument("Invalid card number");
        if (exp.length() != 5 || exp[2] != '/')
            throw invalid_argument("Invalid expiry date format (MM/YY)");
    }
    void process() override {
        bool paymentSuccess = false; // имитация
        if (!paymentSuccess) {
            throw runtime_error("Credit card payment failed");
        }
        cout << "Processed credit card payment of $" << amount << endl;
    }
};

class PayPalPayment : public Payment {
    string email;
public:
    PayPalPayment(double amt, const string& eml)
        : Payment(amt), email(eml) {
        if (eml.find('@') == string::npos)
            throw invalid_argument("Invalid PayPal email");
    }
    void process() override {
        bool paymentSuccess = false; // имитация
        if (!paymentSuccess) {
            throw runtime_error("PayPal payment failed");
        }
        cout << "Processed PayPal payment of $" << amount << endl;
    }
};

class BankTransfer : public Payment {
    string accountNumber;
    string routingNumber;
public:
    BankTransfer(double amt, const string& acc, const string& rout)
        : Payment(amt), accountNumber(acc), routingNumber(rout) {
        if (acc.length() != 12) throw invalid_argument("Invalid account number");
        if (rout.length() != 9) throw invalid_argument("Invalid routing number");
    }
    void process() override {
        bool paymentSuccess = false; // имитация
        if (!paymentSuccess) {
            throw runtime_error("Bank transfer failed");
        }
        cout << "Processed bank transfer of $" << amount << endl;
    }
};

// 3. Класс Shape с функцией getArea()
class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {
        if (r <= 0) throw invalid_argument("Radius must be positive");
    }
    double getArea() const override { return 3.14159 * radius * radius; }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {
        if (w <= 0 || h <= 0) throw invalid_argument("Sides must be positive");
    }
    double getArea() const override { return width * height; }
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
    double getArea() const override {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

// 4. Класс FileHandler с функцией open()
class FileHandler {
public:
    virtual void open(const string& filename) = 0;
    virtual ~FileHandler() = default;
};

class TextFileHandler : public FileHandler {
public:
    void open(const string& filename) override {
        ifstream file(filename);
        if (!file.is_open()) {
            throw runtime_error("Failed to open text file: " + filename);
        }
        cout << "Text file opened successfully: " << filename << endl;
    }
};

class BinaryFileHandler : public FileHandler {
public:
    void open(const string& filename) override {
        ifstream file(filename, ios::binary);
        if (!file.is_open()) {
            throw runtime_error("Failed to open binary file: " + filename);
        }
        cout << "Binary file opened successfully: " << filename << endl;
    }
};

// 5. Класс Database с функцией query()
class Database {
public:
    virtual void query(const string& sql) = 0;
    virtual ~Database() = default;
};

class MySQLDatabase : public Database {
public:
    void query(const string& sql) override {
        if (sql.empty()) {
            throw invalid_argument("SQL query cannot be empty");
        }
        bool connected = false; // имитация
        if (!connected) {
            throw runtime_error("MySQL connection failed");
        }
        cout << "Executed MySQL query: " << sql.substr(0, 20) << "..." << endl;
    }
};

class SQLiteDatabase : public Database {
public:
    void query(const string& sql) override {
        if (sql.find(";") == string::npos) {
            throw invalid_argument("SQL query must end with semicolon");
        }
        bool connected = false; // имитация
        if (!connected) {
            throw runtime_error("SQLite connection failed");
        }
        cout << "Executed SQLite query: " << sql.substr(0, 20) << "..." << endl;
    }
};

// 6. Класс Shape с функцией getVertices()
class VertexShape {
public:
    virtual vector<pair<double, double>> getVertices() const = 0;
    virtual ~VertexShape() = default;
};

class TriangleShape : public VertexShape {
    double x1, y1, x2, y2, x3, y3;
public:
    TriangleShape(double x1, double y1, double x2, double y2, double x3, double y3)
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {
        double area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2;
        if (area == 0) throw invalid_argument("Invalid triangle vertices");
    }
    vector<pair<double, double>> getVertices() const override {
        return { {x1, y1}, {x2, y2}, {x3, y3} };
    }
};

class SquareShape : public VertexShape {
    double x, y, side;
public:
    SquareShape(double x, double y, double s) : x(x), y(y), side(s) {
        if (s <= 0) throw invalid_argument("Side must be positive");
    }
    vector<pair<double, double>> getVertices() const override {
        return { {x, y}, {x + side, y}, {x + side, y + side}, {x, y + side} };
    }
};

class Pentagon : public VertexShape {
    vector<pair<double, double>> vertices;
public:
    Pentagon(const vector<pair<double, double>>& verts) : vertices(verts) {
        if (verts.size() != 5)
            throw invalid_argument("Pentagon must have 5 vertices");
    }
    vector<pair<double, double>> getVertices() const override {
        return vertices;
    }
};

// 7. Класс Logger с функцией log()
class Logger {
public:
    virtual void log(const string& message) = 0;
    virtual ~Logger() = default;
};

class FileLogger : public Logger {
    string filename;
public:
    FileLogger(const string& fn) : filename(fn) {
        if (fn.empty()) throw invalid_argument("Filename cannot be empty");
    }
    void log(const string& message) override {
        ofstream file(filename, ios::app);
        if (!file.is_open()) {
            throw runtime_error("Failed to open log file: " + filename);
        }
        file << message << endl;
        if (file.fail()) {
            throw runtime_error("Failed to write to log file");
        }
    }
};

class ConsoleLogger : public Logger {
public:
    void log(const string& message) override {
        if (message.empty()) {
            throw invalid_argument("Log message cannot be empty");
        }
        cout << "LOG: " << message << endl;
    }
};

// 8. Класс Notification с функцией send()
class Notification {
public:
    virtual void send(const string& message) = 0;
    virtual ~Notification() = default;
};

class EmailNotification : public Notification {
public:
    void send(const string& message) override {
        if (message.empty()) {
            throw invalid_argument("Email message cannot be empty");
        }
        bool emailServerAvailable = false; // имитация
        if (!emailServerAvailable) {
            throw runtime_error("Email server unavailable");
        }
        cout << "Email notification sent: " << message.substr(0, 20) << "..." << endl;
    }
};

class SMSNotification : public Notification {
public:
    void send(const string& message) override {
        if (message.length() > 160) {
            throw invalid_argument("SMS message too long (max 160 chars)");
        }
        bool smsGatewayAvailable = false; // имитация
        if (!smsGatewayAvailable) {
            throw runtime_error("SMS gateway unavailable");
        }
        cout << "SMS notification sent: " << message << endl;
    }
};

class PushNotification : public Notification {
public:
    void send(const string& message) override {
        if (message.find("urgent") != string::npos && message.length() > 100) {
            throw invalid_argument("Urgent push notification too long");
        }
        bool pushServiceAvailable = false; // имитация
        if (!pushServiceAvailable) {
            throw runtime_error("Push service unavailable");
        }
        cout << "Push notification sent: " << message.substr(0, 20) << "..." << endl;
    }
};

// 9. Класс Shape с функцией getPerimeter()
class PerimeterShape {
public:
    virtual double getPerimeter() const = 0;
    virtual ~PerimeterShape() = default;
};

class PerimeterCircle : public PerimeterShape {
    double radius;
public:
    PerimeterCircle(double r) : radius(r) {
        if (r <= 0) throw invalid_argument("Radius must be positive");
    }
    double getPerimeter() const override { return 2 * 3.14159 * radius; }
};

class PerimeterRectangle : public PerimeterShape {
    double width, height;
public:
    PerimeterRectangle(double w, double h) : width(w), height(h) {
        if (w <= 0 || h <= 0) throw invalid_argument("Sides must be positive");
    }
    double getPerimeter() const override { return 2 * (width + height); }
};

class PerimeterTriangle : public PerimeterShape {
    double a, b, c;
public:
    PerimeterTriangle(double a, double b, double c) : a(a), b(b), c(c) {
        if (a <= 0 || b <= 0 || c <= 0)
            throw invalid_argument("Sides must be positive");
        if (a + b <= c || a + c <= b || b + c <= a)
            throw invalid_argument("Invalid triangle sides");
    }
    double getPerimeter() const override { return a + b + c; }
};

// 10. Класс Session с функцией start()
class Session {
protected:
    bool isActive;
public:
    Session() : isActive(false) {}
    virtual void start() = 0;
    virtual ~Session() = default;
};

class UserSession : public Session {
public:
    void start() override {
        if (isActive) {
            throw runtime_error("User session already active");
        }
        isActive = true;
        cout << "User session started" << endl;
    }
};

class AdminSession : public Session {
public:
    void start() override {
        if (isActive) {
            throw runtime_error("Admin session already active");
        }
        isActive = true;
        cout << "Admin session started" << endl;
    }
};

int main() {
    try {
        // Тестирование классов
        AdminUser admin("admin1");
        admin.login("AdminSecure123");

        CreditCardPayment payment(100.0, "1234567812345678", "12/25");
        payment.process();

        Circle circle(5.0);
        cout << "Circle area: " << circle.getArea() << endl;

        TextFileHandler textHandler;
        textHandler.open("example.txt");

        MySQLDatabase mysql;
        mysql.query("SELECT * FROM users;");

        SquareShape square(0, 0, 10);
        auto vertices = square.getVertices();

        FileLogger fileLogger("app.log");
        fileLogger.log("Application started");

        EmailNotification email;
        email.send("Important system update");

        PerimeterTriangle triangle(3, 4, 5);
        cout << "Triangle perimeter: " << triangle.getPerimeter() << endl;

        AdminSession adminSession;
        adminSession.start();

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}