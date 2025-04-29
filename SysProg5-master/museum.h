#include <iostream>
using namespace std;

class museum {
    string name, address, kolvo;

    public:
        void set_inf(string na, string pr, string nu) {
            name = na;
            address = pr;
            kolvo = nu;
        }
        void new_kole(string new_p) {
            kolvo = new_p;
        }
        string inf(museum xum) {
            return "Название музея: " + xum.name + " Адрес музея: " + xum.address + " Количество экспонатов музея: " + xum.kolvo;
        }
};

