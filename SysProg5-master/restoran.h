#include <iostream>
using namespace std;

class restoran {
    string name, address, kolvo;

    public:
        void set_inf(string na, string pr, string nu) {
            name = na;
            address = pr;
            kolvo = nu;
        }
        void new_kold(string new_p) {
            kolvo = new_p;
        }
        string inf(restoran res) {
            return "Название ресторана: " + res.name + " Адрес ресторана: " + res.address + " Количество блюд ресторана: " + res.kolvo;
        }
};

