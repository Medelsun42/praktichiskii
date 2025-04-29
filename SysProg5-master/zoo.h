#include <iostream>
using namespace std;

class zoo {
    string name, address, kolvo;

public:
    void set_inf(string na, string pr, string nu) {
        name = na;
        address = pr;
        kolvo = nu;
    }
    void new_kolnom(string new_p) {
        kolvo = new_p;
    }
    string inf(zoo zoooop) {
        return "Название зоопарка: " + zoooop.name + " Адрес зоопарка: " + zoooop.address + " Количество животных зоопарка: " + zoooop.kolvo;
    }
};

