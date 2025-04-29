#include <iostream>
using namespace std;

class university {
    string name, address, kolvo;

    public:
        void set_inf(string na, string pr, string nu) {
            name = na;
            address = pr;
            kolvo = nu;
        }
        void new_kols(string new_p) {
            kolvo = new_p;
        }
        string inf(university univer) {
            return "Название университета: " + univer.name + " Адрес университета: " + univer.address + " Количество студентов университета: " + univer.kolvo;
        }
};

