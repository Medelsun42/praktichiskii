#include <iostream>
#include <vector>
using namespace std;

class Appliance {
public:
    virtual void turnOn() const = 0;
    virtual ~Appliance() {}
};

class WashingMachine : public Appliance {
public:
    void turnOn() const override { cout << "���������� ������ ��������" << endl; }
};

class Refrigerator : public Appliance {
public:
    void turnOn() const override { cout << "����������� ��������" << endl; }
};

void applianceDemo() {
    vector<Appliance*> appliances = {
        new WashingMachine(),
        new Refrigerator()
    };

    for (auto a : appliances) {
        a->turnOn();
        delete a;
    }
}