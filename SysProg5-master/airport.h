#include <iostream>
using namespace std;

class airport {
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
        string inf(airport ait) {
            return "Название аэропорта: " + ait.name + " Адрес аэропорта: " + ait.address + " Количество рейсов аэропорта: " + ait.kolvo;
        }
};

