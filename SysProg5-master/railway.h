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
            return "Ќазвание железнодорожной станции: " + ral.name + " јдрес железнодорожной станции: " + ral.address + "  оличество поездов железнодорожной станции: " + ral.kolvo;
        }
};

