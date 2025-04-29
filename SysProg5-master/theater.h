#include <iostream>
using namespace std;

class theater {
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
        string inf(theater tea) {
            return "Название театра: " + tea.name + " Адрес театра: " + tea.address + " Количество спектаклей театра: " + tea.kolvo;
        }
};

