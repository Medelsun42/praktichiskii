#include <iostream>
using namespace std;

class cafe {
    string name, address, kolvo;

    public:
        void set_inf(string na, string pr, string nu) {
            name = na;
            address = pr;
            kolvo = nu;
        }
        void new_kolnap(string new_p) {
            kolvo = new_p;
        }
        string inf(cafe caf) {
            return "Название кафе: " + caf.name + " Адрес кафе: " + caf.address + " Количество напитков кафе: " + caf.kolvo;
        }
};

