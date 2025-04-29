#include <iostream>
using namespace std;

class client {
    string name, lastname, address;

    public:
        void set_inf(string na, string ls, string lo) {
            name = na;
            lastname = ls;
            address = lo;
        }
        void new_addrs(string new_a) {
            address = new_a;
        }
        string inf(client clea) {
            return "Имя клиента : " + clea.name + " Фамилия клиента: " + clea.lastname + " Адрес клиента: " + clea.address;
        }
};

