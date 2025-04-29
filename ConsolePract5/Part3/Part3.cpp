#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <map>

using namespace std;

class Product {
private:
    string id;
    string name;
    string description;
    double price;
    int stock;
public:
    Product(const string& i, const string& n, const string& d, double p, int s)
        : id(i), name(n), description(d), price(p), stock(s) {
    }

    void reduceStock(int quantity) { stock -= quantity; }

    string getId() const { return id; }
    string getName() const { return name; }
    string getDescription() const { return description; }
    double getPrice() const { return price; }
    int getStock() const { return stock; }
};

class Customer {
private:
    string id;
    string name;
    string email;
    string address;
public:
    Customer(const string& i, const string& n, const string& e, const string& a)
        : id(i), name(n), email(e), address(a) {
    }

    string getId() const { return id; }
    string getName() const { return name; }
    string getEmail() const { return email; }
    string getAddress() const { return address; }
};

class ShoppingCart {
private:
    Customer* customer;
    map<Product*, int> items;
public:
    ShoppingCart(Customer* c) : customer(c) {}

    void addItem(Product* product, int quantity) {
        if (product->getStock() >= quantity) {
            items[product] += quantity;
        }
    }

    void removeItem(Product* product) {
        items.erase(product);
    }

    const map<Product*, int>& getItems() const { return items; }
    Customer* getCustomer() const { return customer; }
};

class Payment {
public:
    enum PaymentMethod { CREDIT_CARD, PAYPAL, BANK_TRANSFER };

private:
    double amount;
    PaymentMethod method;
    string transactionId;
    bool completed;
public:
    Payment(double a, PaymentMethod m, const string& tid)
        : amount(a), method(m), transactionId(tid), completed(false) {
    }

    void completePayment() { completed = true; }

    double getAmount() const { return amount; }
    PaymentMethod getMethod() const { return method; }
    string getTransactionId() const { return transactionId; }
    bool isCompleted() const { return completed; }
};

class Shipping {
public:
    enum ShippingMethod { STANDARD, EXPRESS, NEXT_DAY };
    enum ShippingStatus { PROCESSING, SHIPPED, DELIVERED };

private:
    string trackingNumber;
    ShippingMethod method;
    ShippingStatus status;
    string address;
public:
    Shipping(const string& tn, ShippingMethod m, const string& addr)
        : trackingNumber(tn), method(m), status(PROCESSING), address(addr) {
    }

    void updateStatus(ShippingStatus newStatus) { status = newStatus; }

    string getTrackingNumber() const { return trackingNumber; }
    ShippingMethod getMethod() const { return method; }
    ShippingStatus getStatus() const { return status; }
    string getAddress() const { return address; }
};

class Order {
private:
    string id;
    Customer* customer;
    vector<Product*> products;
    vector<int> quantities;
    Payment* payment;
    Shipping* shipping;
    time_t orderDate;
    bool fulfilled;
public:
    Order(const string& i, Customer* c, const ShoppingCart* cart)
        : id(i), customer(c), orderDate(time(nullptr)), fulfilled(false) {
        for (const auto& (product) : cart->getItems()) {
        }
    }

    void setPayment(Payment* p) { payment = p; }
    void setShipping(Shipping* s) { shipping = s; }
    void fulfillOrder() { fulfilled = true; }

    string getId() const { return id; }
    Customer* getCustomer() const { return customer; }
    const vector<Product*>& getProducts() const { return products; }
    const vector<int>& getQuantities() const { return quantities; }
    Payment* getPayment() const { return payment; }
    Shipping* getShipping() const { return shipping; }
    time_t getOrderDate() const { return orderDate; }
    bool isFulfilled() const { return fulfilled; }
};

class OrderHistory {
private:
    Customer* customer;
    vector<Order*> orders;
public:
    OrderHistory(Customer* c) : customer(c) {}

    void addOrder(Order* order) {
        orders.push_back(order);
    }

    const vector<Order*>& getOrders() const { return orders; }
    Customer* getCustomer() const { return customer; }
};

int main() {
    // Создаем продукты
    Product* laptop = new Product("P001", "Laptop", "High-end gaming laptop", 1200.99, 10);
    Product* phone = new Product("P002", "Smartphone", "Latest model smartphone", 899.99, 15);

    // Создаем клиента
    Customer* customer = new Customer("C001", "John Doe", "john@example.com", "123 Main St");

    // Создаем корзину и добавляем товары
    ShoppingCart* cart = new ShoppingCart(customer);
    cart->addItem(laptop, 1);
    cart->addItem(phone, 2);

    // Создаем заказ
    Order* order = new Order("O001", customer, cart);

    // Создаем доставку
    Shipping* shipping = new Shipping("TN54321", Shipping::EXPRESS, customer->getAddress());
    order->setShipping(shipping);

    // Обновляем статус заказа
    order->fulfillOrder();
    shipping->updateStatus(Shipping::SHIPPED);

    // Добавляем заказ в историю
    OrderHistory history(customer);
    history.addOrder(order);

    // Выводим информацию о заказе
    cout << "Order ID: " << order->getId() << endl;
    cout << "Customer: " << customer->getName() << endl;
    cout << "Products:" << endl;
    for (size_t i = 0; i < order->getProducts().size(); ++i) {
        cout << "  " << order->getProducts()[i]->getName()
            << " x " << order->getQuantities()[i]
            << " @ $" << order->getProducts()[i]->getPrice() << endl;
    }
    cout << "Total: $" << order->getPayment()->getAmount() << endl;
    cout << "Status: " << (order->isFulfilled() ? "Fulfilled" : "Processing") << endl;

    // Очистка памяти
    delete laptop;
    delete phone;
    delete customer;
    delete cart;
    delete order;
    delete shipping;

    return 0;
}