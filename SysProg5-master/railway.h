#include <iostream>
using namespace std;

class railway {
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
        string inf(railway ral) {
            return "Название железнодорожной станции: " + ral.name + " Адрес железнодорожной станции: " + ral.address + " Количество поездов железнодорожной станции: " + ral.kolvo;
        }
};

