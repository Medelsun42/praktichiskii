#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>
#include <memory>

using namespace std;

// 1. Базовый класс DataProcessor
class DataProcessor {
public:
    virtual void process(const string& data) = 0;
    virtual ~DataProcessor() = default;
};

class CSVProcessor : public DataProcessor {
public:
    void process(const string& data) override {
        if (data.empty()) {
            throw invalid_argument("CSV data cannot be empty");
        }
        if (data.find(',') == string::npos) {
            throw runtime_error("Invalid CSV format - no commas found");
        }
        cout << "Processing CSV data: " << data.substr(0, 20) << "..." << endl;
    }
};

class JSONProcessor : public DataProcessor {
public:
    void process(const string& data) override {
        if (data.empty()) {
            throw invalid_argument("JSON data cannot be empty");
        }
        if (data.front() != '{' || data.back() != '}') {
            throw runtime_error("Invalid JSON format - missing braces");
        }
        cout << "Processing JSON data: " << data.substr(0, 20) << "..." << endl;
    }
};

class XMLProcessor : public DataProcessor {
public:
    void process(const string& data) override {
        if (data.empty()) {
            throw invalid_argument("XML data cannot be empty");
        }
        if (data.find("<root>") == string::npos || data.find("</root>") == string::npos) {
            throw runtime_error("Invalid XML format - missing root element");
        }
        cout << "Processing XML data: " << data.substr(0, 20) << "..." << endl;
    }
};

// 2. Класс Shape с функцией transform()
class Shape {
public:
    virtual void transform(double x, double y, double scale) = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double centerX, centerY, radius;
public:
    Circle(double x, double y, double r) : centerX(x), centerY(y), radius(r) {
        if (r <= 0) throw invalid_argument("Radius must be positive");
    }
    void transform(double x, double y, double scale) override {
        if (scale <= 0) throw invalid_argument("Scale must be positive");
        if (isnan(x) || isnan(y)) throw invalid_argument("Invalid coordinates");
        centerX += x;
        centerY += y;
        radius *= scale;
    }
};

class Square : public Shape {
    double x, y, side;
public:
    Square(double x, double y, double s) : x(x), y(y), side(s) {
        if (s <= 0) throw invalid_argument("Side must be positive");
    }
    void transform(double x, double y, double scale) override {
        if (scale <= 0) throw invalid_argument("Scale must be positive");
        if (isinf(x) || isinf(y)) throw invalid_argument("Invalid coordinates");
        this->x += x;
        this->y += y;
        side *= scale;
    }
};

class Polygon : public Shape {
    vector<pair<double, double>> points;
public:
    Polygon(const vector<pair<double, double>>& pts) : points(pts) {
        if (pts.size() < 3) throw invalid_argument("Polygon needs at least 3 points");
    }
    void transform(double x, double y, double scale) override {
        if (scale <= 0) throw invalid_argument("Scale must be positive");
        for (auto& p : points) {
            p.first = (p.first + x) * scale;
            p.second = (p.second + y) * scale;
        }
    }
};

// 3. Класс User с функцией updateProfile()
class User {
protected:
    string username;
public:
    User(const string& name) : username(name) {
        if (name.empty()) throw invalid_argument("Username cannot be empty");
    }
    virtual void updateProfile(const string& field, const string& value) = 0;
    virtual ~User() = default;
};

class AdminUser : public User {
public:
    AdminUser(const string& name) : User(name) {}
    void updateProfile(const string& field, const string& value) override {
        if (field == "permissions" && value.empty()) {
            throw invalid_argument("Admin permissions cannot be empty");
        }
        cout << "Admin profile updated: " << field << " = " << value << endl;
    }
};

class RegularUser : public User {
public:
    RegularUser(const string& name) : User(name) {}
    void updateProfile(const string& field, const string& value) override {
        if (field == "email" && value.find('@') == string::npos) {
            throw invalid_argument("Invalid email format");
        }
        cout << "User profile updated: " << field << " = " << value << endl;
    }
};

// 4. Класс TaskManager с функцией runTask()
class TaskManager {
public:
    virtual void runTask() = 0;
    virtual ~TaskManager() = default;
};

class ScheduledTask : public TaskManager {
    string taskName;
    time_t scheduleTime;
public:
    ScheduledTask(const string& name, time_t time) : taskName(name), scheduleTime(time) {
        if (name.empty()) throw invalid_argument("Task name cannot be empty");
        if (time < time) throw invalid_argument("Schedule time cannot be in the past");
    }
    void runTask() override {
        cout << "Running scheduled task: " << taskName << endl;
    }
};

class ImmediateTask : public TaskManager {
    string taskName;
public:
    ImmediateTask(const string& name) : taskName(name) {
        if (name.empty()) throw invalid_argument("Task name cannot be empty");
    }
    void runTask() override {
        cout << "Running immediate task: " << taskName << endl;
    }
};

// 5. Класс Shape с функцией getColor()
class ColoredShape {
protected:
    string color;
public:
    ColoredShape(const string& col) : color(col) {
        if (col.empty()) throw invalid_argument("Color cannot be empty");
    }
    virtual string getColor() const = 0;
    virtual ~ColoredShape() = default;
};

class ColoredCircle : public ColoredShape {
    double radius;
public:
    ColoredCircle(const string& col, double r) : ColoredShape(col), radius(r) {
        if (r <= 0) throw invalid_argument("Radius must be positive");
    }
    string getColor() const override {
        if (color == "transparent")
            throw runtime_error("Cannot get color of transparent circle");
        return color;
    }
};

class ColoredSquare : public ColoredShape {
    double side;
public:
    ColoredSquare(const string& col, double s) : ColoredShape(col), side(s) {
        if (s <= 0) throw invalid_argument("Side must be positive");
    }
    string getColor() const override {
        return color;
    }
};

class ColoredTriangle : public ColoredShape {
    double a, b, c;
public:
    ColoredTriangle(const string& col, double a, double b, double c)
        : ColoredShape(col), a(a), b(b), c(c) {
        if (a <= 0 || b <= 0 || c <= 0)
            throw invalid_argument("Sides must be positive");
        if (a + b <= c || a + c <= b || b + c <= a)
            throw invalid_argument("Invalid triangle sides");
    }
    string getColor() const override {
        if (color == "invisible")
            throw runtime_error("Cannot get color of invisible triangle");
        return color;
    }
};

// 6. Класс PaymentGateway с функцией processPayment()
class PaymentGateway {
public:
    virtual void processPayment(double amount, const string& currency) = 0;
    virtual ~PaymentGateway() = default;
};

class StripeGateway : public PaymentGateway {
public:
    void processPayment(double amount, const string& currency) override {
        if (amount <= 0) throw invalid_argument("Amount must be positive");
        if (currency != "USD" && currency != "EUR")
            throw invalid_argument("Unsupported currency");
        bool success = false; // имитация
        if (!success) throw runtime_error("Stripe payment failed");
        cout << "Processed Stripe payment: " << amount << " " << currency << endl;
    }
};

class PayPalGateway : public PaymentGateway {
public:
    void processPayment(double amount, const string& currency) override {
        if (amount < 1.0) throw invalid_argument("Minimum amount is 1.0");
        if (currency.length() != 3)
            throw invalid_argument("Currency code must be 3 characters");
        bool success = false; // имитация
        if (!success) throw runtime_error("PayPal payment failed");
        cout << "Processed PayPal payment: " << amount << " " << currency << endl;
    }
};

class SquareGateway : public PaymentGateway {
public:
    void processPayment(double amount, const string& currency) override {
        if (amount > 10000) throw invalid_argument("Amount exceeds limit");
        if (currency.empty()) throw invalid_argument("Currency cannot be empty");
        bool success = false; // имитация
        if (!success) throw runtime_error("Square payment failed");
        cout << "Processed Square payment: " << amount << " " << currency << endl;
    }
};

// 7. Класс FileReader с функцией read()
class FileReader {
public:
    virtual string read(const string& filename) = 0;
    virtual ~FileReader() = default;
};

class TextFileReader : public FileReader {
public:
    string read(const string& filename) override {
        ifstream file(filename);
        if (!file.is_open())
            throw runtime_error("Failed to open text file: " + filename);
        string content((istreambuf_iterator<char>(file)),
            istreambuf_iterator<char>());
        if (content.empty())
            throw runtime_error("Text file is empty: " + filename);
        return content;
    }
};

class BinaryFileReader : public FileReader {
public:
    string read(const string& filename) override {
        ifstream file(filename, ios::binary);
        if (!file.is_open())
            throw runtime_error("Failed to open binary file: " + filename);
        file.seekg(0, ios::end);
        size_t size = file.tellg();
        if (size == 0)
            throw runtime_error("Binary file is empty: " + filename);
        string content(size, '\0');
        file.seekg(0);
        file.read(&content[0], size);
        return content;
    }
};

class JsonFileReader : public FileReader {
public:
    string read(const string& filename) override {
        ifstream file(filename);
        if (!file.is_open())
            throw runtime_error("Failed to open JSON file: " + filename);
        string content((istreambuf_iterator<char>(file)),
            istreambuf_iterator<char>());
        if (content.empty())
            throw runtime_error("JSON file is empty: " + filename);
        if (content.front() != '{' || content.back() != '}')
            throw runtime_error("Invalid JSON format in file: " + filename);
        return content;
    }
};

// 8. Класс Shape с функцией getArea()
class AreaShape {
public:
    virtual double getArea() const = 0;
    virtual ~AreaShape() = default;
};

class AreaCircle : public AreaShape {
    double radius;
public:
    AreaCircle(double r) : radius(r) {
        if (r <= 0) throw invalid_argument("Radius must be positive");
    }
    double getArea() const override { return 3.14159 * radius * radius; }
};

class AreaRectangle : public AreaShape {
    double width, height;
public:
    AreaRectangle(double w, double h) : width(w), height(h) {
        if (w <= 0 || h <= 0) throw invalid_argument("Sides must be positive");
    }
    double getArea() const override { return width * height; }
};

class AreaTriangle : public AreaShape {
    double a, b, c;
public:
    AreaTriangle(double a, double b, double c) : a(a), b(b), c(c) {
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

// 9. Класс ExceptionHandler с функцией handle()
class ExceptionHandler {
public:
    virtual void handle(const exception& e) = 0;
    virtual ~ExceptionHandler() = default;
};

class FileExceptionHandler : public ExceptionHandler {
public:
    void handle(const exception& e) override {
        cerr << "File Error: " << e.what() << endl;
    }
};

class NetworkExceptionHandler : public ExceptionHandler {
public:
    void handle(const exception& e) override {
        cerr << "Network Error: " << e.what() << endl;
    }
};

class InputExceptionHandler : public ExceptionHandler {
public:
    void handle(const exception& e) override {
        cerr << "Input Error: " << e.what() << endl;
    }
};

// 10. Класс UserProfile с функцией save()
class UserProfile {
protected:
    string username;
public:
    UserProfile(const string& name) : username(name) {
        if (name.empty()) throw invalid_argument("Username cannot be empty");
    }
    virtual void save() = 0;
    virtual ~UserProfile() = default;
};

class AdminProfile : public UserProfile {
    vector<string> permissions;
public:
    AdminProfile(const string& name) : UserProfile(name) {}
    void save() override {
        if (permissions.empty())
            throw runtime_error("Admin must have at least one permission");
        cout << "Admin profile saved: " << username << endl;
    }
    void addPermission(const string& perm) {
        if (perm.empty()) throw invalid_argument("Permission cannot be empty");
        permissions.push_back(perm);
    }
};

class RegularProfile : public UserProfile {
    string email;
public:
    RegularProfile(const string& name) : UserProfile(name) {}
    void save() override {
        if (email.empty())
            throw runtime_error("Regular user must have an email");
        cout << "Regular profile saved: " << username << endl;
    }
    void setEmail(const string& eml) {
        if (eml.find('@') == string::npos)
            throw invalid_argument("Invalid email format");
        email = eml;
    }
};

int main() {
    try {
        // Тестирование классов
        JSONProcessor jsonProc;
        jsonProc.process("{\"key\":\"value\"}");

        Circle circle(0, 0, 5);
        circle.transform(10, 10, 2);

        AdminUser admin("admin1");
        admin.updateProfile("permissions", "all");

        ImmediateTask task("Backup");
        task.runTask();

        ColoredSquare square("blue", 4);
        cout << "Square color: " << square.getColor() << endl;

        StripeGateway stripe;
        stripe.processPayment(100, "USD");

        TextFileReader textReader;
        string content = textReader.read("example.txt");

        AreaTriangle triangle(3, 4, 5);
        cout << "Triangle area: " << triangle.getArea() << endl;

        FileExceptionHandler fileHandler;
        try {
            throw runtime_error("File not found");
        }
        catch (const exception& e) {
            fileHandler.handle(e);
        }

        AdminProfile adminProfile("admin");
        adminProfile.addPermission("write");
        adminProfile.save();

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}