#include <iostream>
using namespace std;

class bus {
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
    string inf(bus bu) {
        return "Название автобусной станции: " + bu.name + " Адрес автобусной станции: " + bu.address + " Количество автобусов автобусной станции: " + bu.kolvo;
    }
};

