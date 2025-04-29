#include <iostream>
using namespace std;

class kniga {
    string name, author, year;

    public:
        void set_inf(string na, string au, string yr) {
            name = na;
            author = au;
            year = yr;
        }
        void new_aut(string new_a) {
            author = new_a;
        }
        string inf(kniga book) {
            return "Название книги : " + book.name + " Автор книги: " + book.author + " Год выпуска книги: " + book.year;
        }
};

