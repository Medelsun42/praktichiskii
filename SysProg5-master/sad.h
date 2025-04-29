#include <iostream>
using namespace std;

class sad {
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
    string inf(sad sa) {
        return "Название сада: " + sa.name + " Адрес сада: " + sa.address + " Количество цветов сада: " + sa.kolvo;
    }
};

