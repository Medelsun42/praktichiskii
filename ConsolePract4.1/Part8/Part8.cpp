#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <regex>

using namespace std;

// 1. Класс Shape с функцией getDescription()
class Shape {
public:
    virtual string getDescription() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {
        if (r <= 0) throw invalid_argument("Radius must be positive");
    }
    string getDescription() const override {
        return "Circle with radius " + to_string(radius);
    }
};

class Square : public Shape {
    double side;
public:
    Square(double s) : side(s) {
        if (s <= 0) throw invalid_argument("Side must be positive");
    }
    string getDescription() const override {
        return "Square with side " + to_string(side);
    }
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
    string getDescription() const override {
        return "Triangle with sides " + to_string(a) + ", " + to_string(b) + ", " + to_string(c);
    }
};

// 2. Класс EmailService с функцией sendEmail()
class EmailService {
public:
    virtual void sendEmail(const string& to, const string& subject, const string& body) = 0;
    virtual ~EmailService() = default;
};

class SMTPService : public EmailService {
public:
    void sendEmail(const string& to, const string& subject, const string& body) override {
        if (to.empty() || to.find('@') == string::npos)
            throw invalid_argument("Invalid recipient email");
        if (subject.empty())
            throw invalid_argument("Email subject cannot be empty");

        bool smtpAvailable = false; // имитация
        if (!smtpAvailable)
            throw runtime_error("SMTP server unavailable");

        cout << "Email sent via SMTP to: " << to << endl;
    }
};

class APIService : public EmailService {
public:
    void sendEmail(const string& to, const string& subject, const string& body) override {
        if (body.empty())
            throw invalid_argument("Email body cannot be empty");

        bool apiAvailable = false; // имитация
        if (!apiAvailable)
            throw runtime_error("Email API unavailable");

        cout << "Email sent via API to: " << to << endl;
    }
};

class MockEmailService : public EmailService {
public:
    void sendEmail(const string& to, const string& subject, const string& body) override {
        if (to == "test@example.com")
            throw runtime_error("Test email blocked");

        cout << "[MOCK] Email would be sent to: " << to << endl;
    }
};

// 3. Класс DataValidator с функцией validate()
class DataValidator {
public:
    virtual void validate(const string& data) = 0;
    virtual ~DataValidator() = default;
};

class EmailValidator : public DataValidator {
public:
    void validate(const string& email) override {
        regex pattern(R"(\w+@\w+\.\w+)");
        if (!regex_match(email, pattern))
            throw invalid_argument("Invalid email format");
    }
};

class PhoneValidator : public DataValidator {
public:
    void validate(const string& phone) override {
        regex pattern(R"(\+\d{11})");
        if (!regex_match(phone, pattern))
            throw invalid_argument("Phone must be in format +XXXXXXXXXXX");
    }
};

class AgeValidator : public DataValidator {
public:
    void validate(const string& ageStr) override {
        try {
            int age = stoi(ageStr);
            if (age < 0 || age > 120)
                throw out_of_range("Age must be between 0 and 120");
        }
        catch (const invalid_argument&) {
            throw invalid_argument("Age must be a number");
        }
    }
};

// 4. Класс Shape с функцией getDimensions()
class DimensionalShape {
public:
    virtual vector<double> getDimensions() const = 0;
    virtual ~DimensionalShape() = default;
};

class DimensionalCircle : public DimensionalShape {
    double radius;
public:
    DimensionalCircle(double r) : radius(r) {
        if (r <= 0) throw invalid_argument("Radius must be positive");
    }
    vector<double> getDimensions() const override {
        return { radius };
    }
};

class Rectangle : public DimensionalShape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {
        if (w <= 0 || h <= 0) throw invalid_argument("Sides must be positive");
    }
    vector<double> getDimensions() const override {
        return { width, height };
    }
};

class DimensionalTriangle : public DimensionalShape {
    double a, b, c;
public:
    DimensionalTriangle(double a, double b, double c) : a(a), b(b), c(c) {
        if (a <= 0 || b <= 0 || c <= 0)
            throw invalid_argument("Sides must be positive");
        if (a + b <= c || a + c <= b || b + c <= a)
            throw invalid_argument("Invalid triangle sides");
    }
    vector<double> getDimensions() const override {
        return { a, b, c };
    }
};

// 5. Класс Transaction с функцией execute()
class Transaction {
protected:
    double amount;
public:
    Transaction(double amt) : amount(amt) {
        if (amt <= 0) throw invalid_argument("Amount must be positive");
    }
    virtual void execute() = 0;
    virtual ~Transaction() = default;
};

class DepositTransaction : public Transaction {
public:
    DepositTransaction(double amt) : Transaction(amt) {}
    void execute() override {
        bool success = false; // имитация
        if (!success)
            throw runtime_error("Deposit failed");
        cout << "Deposited: " << amount << endl;
    }
};

class WithdrawalTransaction : public Transaction {
    double balance;
public:
    WithdrawalTransaction(double amt, double bal) : Transaction(amt), balance(bal) {}
    void execute() override {
        if (amount > balance)
            throw runtime_error("Insufficient funds");
        bool success = false; // имитация
        if (!success)
            throw runtime_error("Withdrawal failed");
        cout << "Withdrawn: " << amount << endl;
    }
};

// 6. Класс Shape с функцией getIntersection()
class IntersectableShape {
public:
    virtual bool getIntersection(const IntersectableShape& other) const = 0;
    virtual ~IntersectableShape() = default;
};

class IntersectableCircle : public IntersectableShape {
    double x, y, radius;
public:
    IntersectableCircle(double x, double y, double r) : x(x), y(y), radius(r) {
        if (r <= 0) throw invalid_argument("Radius must be positive");
    }
    bool getIntersection(const IntersectableShape& other) const override {
        throw runtime_error("Intersection not implemented for this shape combination");
    }
};

class IntersectableRectangle : public IntersectableShape {
    double x1, y1, x2, y2;
public:
    IntersectableRectangle(double x1, double y1, double x2, double y2)
        : x1(x1), y1(y1), x2(x2), y2(y2) {
        if (x1 >= x2 || y1 >= y2)
            throw invalid_argument("Invalid rectangle coordinates");
    }
    bool getIntersection(const IntersectableShape& other) const override {
        throw runtime_error("Intersection not implemented for this shape combination");
    }
};

class Polygon : public IntersectableShape {
    vector<pair<double, double>> points;
public:
    Polygon(const vector<pair<double, double>>& pts) : points(pts) {
        if (pts.size() < 3) throw invalid_argument("Polygon needs at least 3 points");
    }
    bool getIntersection(const IntersectableShape& other) const override {
        throw runtime_error("Intersection not implemented for this shape combination");
    }
};

// 7. Класс User с функцией authenticate()
class AuthenticableUser {
protected:
    string username;
public:
    AuthenticableUser(const string& name) : username(name) {
        if (name.empty()) throw invalid_argument("Username cannot be empty");
    }
    virtual void authenticate(const string& credentials) = 0;
    virtual ~AuthenticableUser() = default;
};

class AdminUser : public AuthenticableUser {
public:
    AdminUser(const string& name) : AuthenticableUser(name) {}
    void authenticate(const string& credentials) override {
        if (credentials != "AdminSecure123")
            throw invalid_argument("Invalid admin credentials");
        cout << "Admin authenticated: " << username << endl;
    }
};

class RegularUser : public AuthenticableUser {
public:
    RegularUser(const string& name) : AuthenticableUser(name) {}
    void authenticate(const string& credentials) override {
        if (credentials.length() < 8)
            throw invalid_argument("Password must be at least 8 characters");
        cout << "User authenticated: " << username << endl;
    }
};

// 8. Класс DataProcessor с функцией processData()
class DataFormatProcessor {
public:
    virtual void processData(const string& data) = 0;
    virtual ~DataFormatProcessor() = default;
};

class CSVDataProcessor : public DataFormatProcessor {
public:
    void processData(const string& data) override {
        if (data.empty())
            throw invalid_argument("CSV data cannot be empty");
        if (data.find(',') == string::npos)
            throw runtime_error("Invalid CSV format - no commas found");
        cout << "Processing CSV data" << endl;
    }
};

class XMLDataProcessor : public DataFormatProcessor {
public:
    void processData(const string& data) override {
        if (data.empty())
            throw invalid_argument("XML data cannot be empty");
        if (data.find("<root>") == string::npos)
            throw runtime_error("Invalid XML format - missing root element");
        cout << "Processing XML data" << endl;
    }
};

class JSONDataProcessor : public DataFormatProcessor {
public:
    void processData(const string& data) override {
        if (data.empty())
            throw invalid_argument("JSON data cannot be empty");
        if (data.front() != '{' || data.back() != '}')
            throw runtime_error("Invalid JSON format - missing braces");
        cout << "Processing JSON data" << endl;
    }
};

// 9. Класс Shape с функцией getArea()
class AreaCalculatingShape {
public:
    virtual double getArea() const = 0;
    virtual ~AreaCalculatingShape() = default;
};

class AreaCircle : public AreaCalculatingShape {
    double radius;
public:
    AreaCircle(double r) : radius(r) {
        if (r <= 0) throw invalid_argument("Radius must be positive");
    }
    double getArea() const override { return 3.14159 * radius * radius; }
};

class AreaRectangle : public AreaCalculatingShape {
    double width, height;
public:
    AreaRectangle(double w, double h) : width(w), height(h) {
        if (w <= 0 || h <= 0) throw invalid_argument("Sides must be positive");
    }
    double getArea() const override { return width * height; }
};

class AreaCalculatingTriangle : public AreaCalculatingShape {
    double a, b, c;
public:
    AreaCalculatingTriangle(double a, double b, double c) : a(a), b(b), c(c) {
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

// 10. Класс NotificationService с функцией sendNotification()
class NotificationService {
public:
    virtual void sendNotification(const string& recipient, const string& message) = 0;
    virtual ~NotificationService() = default;
};

class EmailNotificationService : public NotificationService {
public:
    void sendNotification(const string& recipient, const string& message) override {
        if (recipient.empty() || recipient.find('@') == string::npos)
            throw invalid_argument("Invalid recipient email");
        if (message.empty())
            throw invalid_argument("Message cannot be empty");

        bool emailServiceAvailable = false; // имитация
        if (!emailServiceAvailable)
            throw runtime_error("Email service unavailable");

        cout << "Email notification sent to: " << recipient << endl;
    }
};

class SMSNotificationService : public NotificationService {
public:
    void sendNotification(const string& recipient, const string& message) override {
        if (recipient.length() != 11)
            throw invalid_argument("Invalid phone number");
        if (message.length() > 160)
            throw invalid_argument("SMS message too long");

        bool smsServiceAvailable = false; // имитация
        if (!smsServiceAvailable)
            throw runtime_error("SMS service unavailable");

        cout << "SMS notification sent to: " << recipient << endl;
    }
};

class PushNotificationService : public NotificationService {
public:
    void sendNotification(const string& recipient, const string& message) override {
        if (recipient.empty())
            throw invalid_argument("Device ID cannot be empty");
        if (message.empty())
            throw invalid_argument("Push message cannot be empty");

        bool pushServiceAvailable = false; // имитация
        if (!pushServiceAvailable)
            throw runtime_error("Push service unavailable");

        cout << "Push notification sent to device: " << recipient << endl;
    }
};

int main() {
    try {
        // Тестирование классов
        Circle circle(5.0);
        cout << circle.getDescription() << endl;

        SMTPService smtp;
        smtp.sendEmail("user@example.com", "Test", "Hello");

        EmailValidator emailValidator;
        emailValidator.validate("test@example.com");

        DimensionalCircle dimCircle(3.0);
        auto dims = dimCircle.getDimensions();

        DepositTransaction deposit(100);
        deposit.execute();

        AdminUser admin("admin1");
        admin.authenticate("AdminSecure123");

        CSVDataProcessor csvProcessor;
        csvProcessor.processData("name,age\nJohn,30");

        AreaRectangle areaRect(4, 5);
        cout << "Rectangle area: " << areaRect.getArea() << endl;

        EmailNotificationService emailNotif;
        emailNotif.sendNotification("user@example.com", "New notification");

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}