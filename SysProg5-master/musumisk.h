#include <iostream>
using namespace std;

class musumisk {
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
    string inf(musumisk mus) {
        return "Название музея: " + mus.name + " Адрес музея: " + mus.address + " Количество экспонатов музея: " + mus.kolvo;
    }
};

