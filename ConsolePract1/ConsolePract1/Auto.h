#include <iostream>
#include <vector>

using namespace std;

class Vehicle {
public:
    virtual void move() const = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    void move() const override { cout << "������: ����" << endl; }
};

class Bike : public Vehicle {
public:
    void move() const override { cout << "���������: ����" << endl; }
};

void vehicleDemo() {
    vector<Vehicle*> vehicles = {
        new Car(),
        new Bike()
    };

    for (auto v : vehicles) {
        v->move();
        delete v;
    }
}