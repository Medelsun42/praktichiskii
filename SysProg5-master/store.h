#include <iostream>
using namespace std;

class store {
    string name, address, kolvo;

    public:
        void set_inf(string na, string pr, string nu) {
            name = na;
            address = pr;
            kolvo = nu;
        }
        void new_kola(string new_p) {
            kolvo = new_p;
        }
        string inf(store magaz) {
            return "Название магазина: " + magaz.name + " Адрес магазина: " + magaz.address + " Количество товаров магазина: " + magaz.kolvo;
        }
};

