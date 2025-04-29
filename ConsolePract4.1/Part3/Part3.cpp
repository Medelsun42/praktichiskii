#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cmath>

using namespace std;

// 1. Класс Shape с функцией translate()
class Shape {
public:
    virtual void translate(double dx, double dy) = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double x, y, radius;
public:
    Circle(double x, double y, double r) : x(x), y(y), radius(r) {
        if (r <= 0) throw invalid_argument("Radius must be positive");
    }
    void translate(double dx, double dy) override {
        if (isinf(dx) || isinf(dy) || isnan(dx) || isnan(dy))
            throw invalid_argument("Invalid translation values");
        x += dx;
        y += dy;
    }
};

class Rectangle : public Shape {
    double x, y, width, height;
public:
    Rectangle(double x, double y, double w, double h)
        : x(x), y(y), width(w), height(h) {
        if (w <= 0 || h <= 0) throw invalid_argument("Dimensions must be positive");
    }
    void translate(double dx, double dy) override {
        if (abs(dx) > 1000 || abs(dy) > 1000)
            throw invalid_argument("Translation values too large");
        x += dx;
        y += dy;
    }
};

// 2. Класс Database и производные
class Database {
public:
    virtual void connect(const string& connectionString) = 0;
    virtual ~Database() = default;
};

class MySQLDatabase : public Database {
public:
    void connect(const string& connectionString) override {
        if (connectionString.empty())
            throw runtime_error("MySQL connection string is empty");
        if (connectionString.find("mysql://") == string::npos)
            throw runtime_error("Invalid MySQL connection string format");
        cout << "Connected to MySQL database" << endl;
    }
};

class SQLiteDatabase : public Database {
public:
    void connect(const string& connectionString) override {
        if (connectionString.empty())
            throw runtime_error("SQLite connection string is empty");
        cout << "Connected to SQLite database" << endl;
    }
};

// 3. Класс Task и производные
class Task {
public:
    virtual void execute() = 0;
    virtual ~Task() = default;
};

class PrintTask : public Task {
    string message;
public:
    PrintTask(const string& msg) : message(msg) {
        if (msg.empty()) throw runtime_error("Print message cannot be empty");
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
            throw runtime_error("Recipient and subject cannot be empty");
        if (rec.find('@') == string::npos)
            throw runtime_error("Invalid email address");
    }
    void execute() override {
        cout << "Sending email to: " << recipient << " with subject: " << subject << endl;
    }
};

// 4. Класс Shape с getPerimeter()
class PerimeterShape {
public:
    virtual double getPerimeter() const = 0;
    virtual ~PerimeterShape() = default;
};

class Triangle : public PerimeterShape {
    double a, b, c;
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {
        if (a <= 0 || b <= 0 || c <= 0)
            throw invalid_argument("Sides must be positive");
        if (a + b <= c || a + c <= b || b + c <= a)
            throw invalid_argument("Invalid triangle sides");
    }
    double getPerimeter() const override { return a + b + c; }
};

class Square : public PerimeterShape {
    double side;
public:
    Square(double s) : side(s) {
        if (s <= 0) throw invalid_argument("Side must be positive");
    }
    double getPerimeter() const override { return 4 * side; }
};

// 5. Класс WeatherService и производные
class WeatherService {
public:
    virtual string getForecast() const = 0;
    virtual ~WeatherService() = default;
};

class LocalWeatherService : public WeatherService {
public:
    string getForecast() const override {
        throw runtime_error("Local weather data not available");
    }
};

class RemoteWeatherService : public WeatherService {
public:
    string getForecast() const override {
        bool networkAvailable = false; // имитация
        if (!networkAvailable)
            throw runtime_error("Failed to connect to weather service");
        return "Sunny, 25°C";
    }
};

// 6. Класс Transaction и производные
class Transaction {
protected:
    double amount;
public:
    Transaction(double amt) : amount(amt) {
        if (amt <= 0) throw invalid_argument("Amount must be positive");
    }
    virtual void commit() = 0;
    virtual ~Transaction() = default;
};

class BankTransaction : public Transaction {
public:
    BankTransaction(double amt) : Transaction(amt) {}
    void commit() override {
        bool success = false; // имитация
        if (!success) throw runtime_error("Bank transaction failed");
        cout << "Bank transaction of $" << amount << " completed" << endl;
    }
};

class CryptoTransaction : public Transaction {
public:
    CryptoTransaction(double amt) : Transaction(amt) {}
    void commit() override {
        bool blockchainAvailable = false; // имитация
        if (!blockchainAvailable)
            throw runtime_error("Blockchain network error");
        cout << "Crypto transaction of " << amount << " BTC completed" << endl;
    }
};

// 7. Класс Notification и производные
class Notification {
public:
    virtual void send(const string& message) = 0;
    virtual ~Notification() = default;
};

class EmailNotification : public Notification {
public:
    void send(const string& message) override {
        if (message.empty()) throw invalid_argument("Message cannot be empty");
        bool emailServerAvailable = false; // имитация
        if (!emailServerAvailable)
            throw runtime_error("Email server unavailable");
        cout << "Email sent: " << message << endl;
    }
};

class SMSNotification : public Notification {
public:
    void send(const string& message) override {
        if (message.length() > 160)
            throw invalid_argument("SMS message too long");
        bool smsGatewayAvailable = false; // имитация
        if (!smsGatewayAvailable)
            throw runtime_error("SMS gateway unavailable");
        cout << "SMS sent: " << message << endl;
    }
};

// 8. Класс Shape с getBoundingBox()
class BoundingBoxShape {
public:
    virtual void getBoundingBox(double& x1, double& y1, double& x2, double& y2) const = 0;
    virtual ~BoundingBoxShape() = default;
};

class CircleBB : public BoundingBoxShape {
    double x, y, radius;
public:
    CircleBB(double x, double y, double r) : x(x), y(y), radius(r) {
        if (r <= 0) throw invalid_argument("Radius must be positive");
    }
    void getBoundingBox(double& x1, double& y1, double& x2, double& y2) const override {
        x1 = x - radius;
        y1 = y - radius;
        x2 = x + radius;
        y2 = y + radius;
    }
};

class Polygon : public BoundingBoxShape {
    vector<pair<double, double>> points;
public:
    Polygon(const vector<pair<double, double>>& pts) : points(pts) {
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

// 9. Класс UserProfile и производные
class UserProfile {
protected:
    string username;
public:
    UserProfile(const string& uname) : username(uname) {
        if (uname.empty()) throw invalid_argument("Username cannot be empty");
    }
    virtual void updateProfile(const string& newData) = 0;
    virtual ~UserProfile() = default;
};

class AdminProfile : public UserProfile {
public:
    AdminProfile(const string& uname) : UserProfile(uname) {}
    void updateProfile(const string& newData) override {
        if (newData.length() > 1000)
            throw invalid_argument("Admin profile data too large");
        cout << "Admin profile updated" << endl;
    }
};

class GuestProfile : public UserProfile {
public:
    GuestProfile(const string& uname) : UserProfile(uname) {}
    void updateProfile(const string& newData) override {
        if (newData.find("admin") != string::npos)
            throw invalid_argument("Guest cannot use admin keywords");
        cout << "Guest profile updated" << endl;
    }
};

// 10. Класс PaymentProcessor и производные
class PaymentProcessor {
protected:
    double balance;
public:
    PaymentProcessor(double bal) : balance(bal) {
        if (bal < 0) throw invalid_argument("Balance cannot be negative");
    }
    virtual void processPayment(double amount) = 0;
    virtual ~PaymentProcessor() = default;
};

class CreditCardProcessor : public PaymentProcessor {
public:
    CreditCardProcessor(double bal) : PaymentProcessor(bal) {}
    void processPayment(double amount) override {
        if (amount > balance * 1.5)
            throw runtime_error("Credit limit exceeded");
        balance -= amount;
        cout << "Credit card payment processed. Remaining balance: $" << balance << endl;
    }
};

class DebitCardProcessor : public PaymentProcessor {
public:
    DebitCardProcessor(double bal) : PaymentProcessor(bal) {}
    void processPayment(double amount) override {
        if (amount > balance)
            throw runtime_error("Insufficient funds");
        balance -= amount;
        cout << "Debit card payment processed. Remaining balance: $" << balance << endl;
    }
};

int main() {
    try {
        // Тестирование классов
        Circle circle(0, 0, 5);
        circle.translate(10, 10);

        MySQLDatabase mysql;
        mysql.connect("mysql://user:pass@localhost");

        PrintTask printTask("Hello World");
        printTask.execute();

        Triangle triangle(3, 4, 5);
        cout << "Triangle perimeter: " << triangle.getPerimeter() << endl;

        BankTransaction bankTx(100);
        bankTx.commit();

        EmailNotification email;
        email.send("Important message");

        CircleBB circleBB(0, 0, 5);
        double x1, y1, x2, y2;
        circleBB.getBoundingBox(x1, y1, x2, y2);

        AdminProfile admin("admin1");
        admin.updateProfile("New admin data");

        CreditCardProcessor ccProcessor(1000);
        ccProcessor.processPayment(500);

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}