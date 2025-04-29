#include <iostream>
using namespace std;

class apuarium {
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
    string inf(apuarium aq) {
        return "Название аквариума: " + aq.name + " Адрес аквариума: " + aq.address + " Количество рыб аквариума: " + aq.kolvo;
    }
};

