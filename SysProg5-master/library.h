#include <iostream>
using namespace std;

class library {
    string name, address, kolvo;

    public:
        void set_inf(string na, string pr, string nu) {
            name = na;
            address = pr;
            kolvo = nu;
        }
        void new_kolb(string new_p) {
            kolvo = new_p;
        }
        string inf(library svh) {
            return "Название библиотеки: " + svh.name + " Адрес библиотеки: " + svh.address + " Количество книг библиотеки: " + svh.kolvo;
        }
};

