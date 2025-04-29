#include <iostream>
using namespace std;

class tovar {
    string name, price, number;

    public:
        void set_inf(string na, string pr, string nu) {
            name = na;
            price = pr;
            number = nu;
        }
        void new_price(string new_p) {
            price = new_p;
        }
        string inf(tovar tof) {
            return "Имя товара: " + tof.name + " Стоимость товара: " + tof.price + " Количество товара: " + tof.number;
        }
};

