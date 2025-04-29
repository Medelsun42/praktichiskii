#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <memory>

using namespace std;

// 1. Класс Vehicle и производные
class Vehicle {
public:
    virtual double fuelEfficiency() const = 0;
    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
    double mpg;
public:
    Car(double efficiency) : mpg(efficiency) {
        if (efficiency <= 0)
            throw invalid_argument("Fuel efficiency must be positive");
    }
    double fuelEfficiency() const override { return mpg; }
};

class Truck : public Vehicle {
    double mpg;
    double loadCapacity;
public:
    Truck(double efficiency, double capacity) : mpg(efficiency), loadCapacity(capacity) {
        if (efficiency <= 0)
            throw invalid_argument("Fuel efficiency must be positive");
        if (capacity <= 0)
            throw invalid_argument("Load capacity must be positive");
    }
    double fuelEfficiency() const override { return mpg / (1 + loadCapacity / 1000); }
};

// 2. Класс User и производные
class User {
protected:
    string username;
public:
    User(const string& name) : username(name) {}
    virtual void login(const string& password) = 0;
    virtual ~User() = default;
};

class AdminUser : public User {
public:
    AdminUser(const string& name) : User(name) {}
    void login(const string& password) override {
        if (password != "admin123")
            throw runtime_error("Invalid admin password");
        cout << "Admin " << username << " logged in" << endl;
    }
};

class RegularUser : public User {
public:
    RegularUser(const string& name) : User(name) {}
    void login(const string& password) override {
        if (password.empty())
            throw runtime_error("Password cannot be empty");
        if (password.length() < 6)
            throw runtime_error("Password too short");
        cout << "User " << username << " logged in" << endl;
    }
};

// 3. Класс Shape с функцией scale()
class ScalableShape {
public:
    virtual void scale(double factor) = 0;
    virtual ~ScalableShape() = default;
};

class Circle : public ScalableShape {
    double radius;
public:
    Circle(double r) : radius(r) {
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

// 4. Класс Library и производные
class Library {
public:
    virtual void borrowBook(const string& title) = 0;
    virtual ~Library() = default;
};

class FictionLibrary : public Library {
    vector<string> availableBooks = { "Novel", "Short Story" };
public:
    void borrowBook(const string& title) override {
        bool found = false;
        for (const auto& book : availableBooks) {
            if (book == title) {
                found = true;
                break;
            }
        }
        if (!found) throw runtime_error("Fiction book not available: " + title);
        cout << "Borrowed fiction book: " << title << endl;
    }
};

class NonFictionLibrary : public Library {
    vector<string> availableBooks = { "Biography", "History" };
public:
    void borrowBook(const string& title) override {
        bool found = false;
        for (const auto& book : availableBooks) {
            if (book == title) {
                found = true;
                break;
            }
        }
        if (!found) throw runtime_error("Non-fiction book not available: " + title);
        cout << "Borrowed non-fiction book: " << title << endl;
    }
};

// 5. Класс Order и производные
class Order {
public:
    virtual void process() = 0;
    virtual ~Order() = default;
};

class OnlineOrder : public Order {
    string address;
public:
    OnlineOrder(const string& addr) : address(addr) {
        if (addr.empty()) throw invalid_argument("Address cannot be empty");
    }
    void process() override {
        cout << "Processing online order to " << address << endl;
    }
};

class InStoreOrder : public Order {
    int storeId;
public:
    InStoreOrder(int id) : storeId(id) {
        if (id <= 0) throw invalid_argument("Invalid store ID");
    }
    void process() override {
        cout << "Processing in-store order at store #" << storeId << endl;
    }
};

// 6. Класс Shape с функцией rotate()
class RotatableShape {
public:
    virtual void rotate(double angle) = 0;
    virtual ~RotatableShape() = default;
};

class Triangle : public RotatableShape {
public:
    void rotate(double angle) override {
        if (angle < 0 || angle > 360)
            throw invalid_argument("Angle must be between 0 and 360 degrees");
        cout << "Rotating triangle by " << angle << " degrees" << endl;
    }
};

class Rectangle : public RotatableShape {
public:
    void rotate(double angle) override {
        if (fmod(angle, 90) != 0)
            throw invalid_argument("Rectangle can only be rotated by multiples of 90 degrees");
        cout << "Rotating rectangle by " << angle << " degrees" << endl;
    }
};

// 7. Класс Payment и производные
class Payment {
protected:
    double amount;
public:
    Payment(double amt) : amount(amt) {
        if (amt <= 0) throw invalid_argument("Amount must be positive");
    }
    virtual void processPayment() = 0;
    virtual ~Payment() = default;
};

class CreditCardPayment : public Payment {
    string cardNumber;
public:
    CreditCardPayment(double amt, const string& num) : Payment(amt), cardNumber(num) {
        if (num.length() != 16) throw invalid_argument("Invalid credit card number");
    }
    void processPayment() override {
        cout << "Processing credit card payment of $" << amount << endl;
    }
};

class PayPalPayment : public Payment {
    string email;
public:
    PayPalPayment(double amt, const string& eml) : Payment(amt), email(eml) {
        if (eml.find('@') == string::npos)
            throw invalid_argument("Invalid PayPal email");
    }
    void processPayment() override {
        cout << "Processing PayPal payment of $" << amount << " to " << email << endl;
    }
};

// 8. Класс ExceptionHandler и производные
class ExceptionHandler {
public:
    virtual void handle(const exception& e) = 0;
    virtual ~ExceptionHandler() = default;
};

class FileExceptionHandler : public ExceptionHandler {
public:
    void handle(const exception& e) override {
        cerr << "File error: " << e.what() << endl;
    }
};

class NetworkExceptionHandler : public ExceptionHandler {
public:
    void handle(const exception& e) override {
        cerr << "Network error: " << e.what() << endl;
    }
};

// 9. Класс Course и производные
class Course {
protected:
    int currentEnrollment;
    int maxCapacity;
public:
    Course(int capacity) : maxCapacity(capacity), currentEnrollment(0) {
        if (capacity <= 0) throw invalid_argument("Capacity must be positive");
    }
    virtual void enroll() = 0;
    virtual ~Course() = default;
};

class OnlineCourse : public Course {
public:
    OnlineCourse(int capacity) : Course(capacity) {}
    void enroll() override {
        if (currentEnrollment >= maxCapacity)
            throw runtime_error("Online course is full");
        currentEnrollment++;
        cout << "Enrolled in online course (" << currentEnrollment << "/" << maxCapacity << ")" << endl;
    }
};

class OfflineCourse : public Course {
    string location;
public:
    OfflineCourse(int capacity, const string& loc) : Course(capacity), location(loc) {
        if (loc.empty()) throw invalid_argument("Location cannot be empty");
    }
    void enroll() override {
        if (currentEnrollment >= maxCapacity)
            throw runtime_error("Offline course is full");
        currentEnrollment++;
        cout << "Enrolled in offline course at " << location << " (" << currentEnrollment << "/" << maxCapacity << ")" << endl;
    }
};

// 10. Класс ShoppingCart и производные
class ShoppingCart {
protected:
    vector<string> items;
public:
    virtual void checkout() = 0;
    void addItem(const string& item) {
        items.push_back(item);
    }
    virtual ~ShoppingCart() = default;
};

class RegularCart : public ShoppingCart {
public:
    void checkout() override {
        if (items.empty()) throw runtime_error("Cannot checkout empty cart");
        cout << "Checking out regular cart with " << items.size() << " items" << endl;
    }
};

class DiscountedCart : public ShoppingCart {
    double discount;
public:
    DiscountedCart(double disc) : discount(disc) {
        if (disc < 0 || disc > 1) throw invalid_argument("Discount must be between 0 and 1");
    }
    void checkout() override {
        if (items.empty()) throw runtime_error("Cannot checkout empty cart");
        cout << "Checking out discounted cart with " << items.size()
            << " items (" << (discount * 100) << "% discount)" << endl;
    }
};

int main() {
    try {
        // Тестирование различных классов
        Car car(30.5);
        cout << "Car efficiency: " << car.fuelEfficiency() << " mpg" << endl;

        AdminUser admin("admin1");
        admin.login("admin123");

        Circle circle(5.0);
        circle.scale(2.0);

        FictionLibrary fictionLib;
        fictionLib.borrowBook("Novel");

        OnlineOrder onlineOrder("123 Main St");
        onlineOrder.process();

        Triangle triangle;
        triangle.rotate(45);

        CreditCardPayment ccPayment(100.0, "1234567812345678");
        ccPayment.processPayment();

        FileExceptionHandler fileHandler;
        try {
            throw runtime_error("File not found");
        }
        catch (const exception& e) {
            fileHandler.handle(e);
        }

        OnlineCourse onlineCourse(50);
        onlineCourse.enroll();

        RegularCart cart;
        cart.addItem("Book");
        cart.addItem("Laptop");
        cart.checkout();

    }
    catch (const exception& e) {
        cerr << "Error in main: " << e.what() << endl;
    }

    return 0;
}