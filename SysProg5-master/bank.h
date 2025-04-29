#include <iostream>
using namespace std;

class bank {
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
        string inf(bank bamko) {
            return "Название банка: " + bamko.name + " Адрес банка: " + bamko.address + " Количество клиентов банка: " + bamko.kolvo;
        }
};