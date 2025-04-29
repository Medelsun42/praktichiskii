#include <iostream>
#include <vector>

using namespace std;

class Employee {
public:
    virtual double calculateSalary() const = 0;
    virtual ~Employee() {}
};

class FullTimeEmployee : public Employee {
    double monthlySalary;
public:
    FullTimeEmployee(double salary) : monthlySalary(salary) {}
    double calculateSalary() const override { return monthlySalary; }
};

class PartTimeEmployee : public Employee {
    double hourlyRate;
    int hours;
public:
    PartTimeEmployee(double rate, int h) : hourlyRate(rate), hours(h) {}
    double calculateSalary() const override { return hourlyRate * hours; }
};

void employeeDemo() {
    int salary, hours, sarhour;

    cout << "Введите зарплату: " << endl;
    cin >> salary;
    cout << "Введите количество часов и почасовую оплату: " << endl;
    cin >> hours;
    cin >> sarhour;

    vector<Employee*> employees = {
        new FullTimeEmployee(salary),
        new PartTimeEmployee(hours, sarhour)
    };

    for (auto emp : employees) {
        cout << "Зарплата: " << emp->calculateSalary() << endl;
        delete emp;
    }
}