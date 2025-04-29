#include <iostream>
#include "automobile.h"
#include "student.h"
#include "product.h"
#include "sotrudniki.h"
#include "kniga.h"
#include "machine.h"
#include "polzovatel.h"
#include "tovar.h"
#include "teacher.h"
#include "client.h"
#include "store.h"
#include "bank.h"
#include "university.h"
#include "school.h"
#include "library.h"
#include "museum.h"
#include "theater.h"
#include "absolutecinema.h"
#include "restoran.h"
#include "cafe.h"
#include "hotel.h"
#include "airport.h"
#include "railway.h"
#include "bus.h"
#include "park.h"
#include "sad.h"
#include "zoo.h"
#include "apuarium.h"
#include "musumisk.h"
#include "operathe.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int z;
    cout << "Выберите задание от 1 до 30: " << endl;
    cin >> z;

    switch (z) {
    case 1: {
        string am, mod, year, new_mark;
        automobile au;

        cout << "Введите марку, модель и год выпуска автомобиля: " << endl;
        cin >> am;
        cin >> mod;
        cin >> year;

        au.set_inf(am, mod, year);
        cout << au.inf(au) << endl;

        cout << "Введите новую марку: " << endl;
        cin >> new_mark;

        au.new_marka(new_mark);
        cout << au.inf(au) << endl;
        break;
    }

    case 2: {
        string st, last, voz, new_voz;
        student srudent;

        cout << "Введите имя, фамилию и возраст студента: " << endl;
        cin >> st;
        cin >> last;
        cin >> voz;

        srudent.set_inf(st, last, voz);
        cout << srudent.inf(srudent) << endl;

        cout << "Введите новый возраст: " << endl;
        cin >> new_voz;

        srudent.new_age(new_voz);
        cout << srudent.inf(srudent) << endl;
        break;
    }

    case 3: {
        string name, price, kolvo, new_pr;
        product porod;

        cout << "Введите имя, цену и количество товара: " << endl;
        cin >> name;
        cin >> price;
        cin >> kolvo;

        porod.set_inf(name, price, kolvo);
        cout << porod.inf(porod) << endl;

        cout << "Введите новую цену: " << endl;
        cin >> new_pr;

        porod.new_price(new_pr);
        cout << porod.inf(porod) << endl;
        break;
    }

    case 4: {
        string name, lst, dolzh, new_dz;
        sotrudniki sotr;

        cout << "Введите имя, фамилию и должность сотрудника: " << endl;
        cin >> name;
        cin >> lst;
        cin >> dolzh;

        sotr.set_inf(name, lst, dolzh);
        cout << sotr.inf(sotr) << endl;

        cout << "Введите новую должность: " << endl;
        cin >> new_dz;

        sotr.new_dolzh(new_dz);
        cout << sotr.inf(sotr) << endl;
        break;
    }

    case 5: {
        string name, aut, yer, new_at;
        kniga booko;

        cout << "Введите название, автора и год выпуска книги: " << endl;
        cin >> name;
        cin >> aut;
        cin >> yer;

        booko.set_inf(name, aut, yer);
        cout << booko.inf(booko) << endl;

        cout << "Введите нового автора: " << endl;
        cin >> new_at;

        booko.new_aut(new_at);
        cout << booko.inf(booko) << endl;
        break;
    }

    case 6: {
        string am, mod, year, new_mark;
        automobile au;

        cout << "Введите марку, модель и год выпуска автомобиля: " << endl;
        cin >> am;
        cin >> mod;
        cin >> year;

        au.set_inf(am, mod, year);
        cout << au.inf(au) << endl;

        cout << "Введите новую марку: " << endl;
        cin >> new_mark;

        au.new_marka(new_mark);
        cout << au.inf(au) << endl;
        break;
    }

    case 7: {
        string na, lasta, logo, new_lg;
        polzovatel polzo;

        cout << "Введите имя, фамилию и логин пользователя: " << endl;
        cin >> na;
        cin >> lasta;
        cin >> logo;

        polzo.set_inf(na, lasta, logo);
        cout << polzo.inf(polzo) << endl;

        cout << "Введите новый логин: " << endl;
        cin >> new_lg;

        polzo.new_log(new_lg);
        cout << polzo.inf(polzo) << endl;
        break;
    }

    case 8: {
        string name, price, kolvo, new_pr;
        product porod;

        cout << "Введите имя, цену и количество товара: " << endl;
        cin >> name;
        cin >> price;
        cin >> kolvo;

        porod.set_inf(name, price, kolvo);
        cout << porod.inf(porod) << endl;

        cout << "Введите новую цену: " << endl;
        cin >> new_pr;

        porod.new_price(new_pr);
        cout << porod.inf(porod) << endl;
        break;
    }

    case 9: {
        string na, lasta, logo, new_lg;
        teacher polzo;

        cout << "Введите имя, фамилию и предмет учителя: " << endl;
        cin >> na;
        cin >> lasta;
        cin >> logo;

        polzo.set_inf(na, lasta, logo);
        cout << polzo.inf(polzo) << endl;

        cout << "Введите новый предмет: " << endl;
        cin >> new_lg;

        polzo.new_pred(new_lg);
        cout << polzo.inf(polzo) << endl;
        break;
    }

    case 10: {
        string na, lasta, addr, new_ar;
        client polzo;

        cout << "Введите имя, фамилию и адрес клиента: " << endl;
        cin >> na;
        cin >> lasta;
        cin >> addr;

        polzo.set_inf(na, lasta, addr);
        cout << polzo.inf(polzo) << endl;

        cout << "Введите новый адрес: " << endl;
        cin >> new_ar;

        polzo.new_addrs(new_ar);
        cout << polzo.inf(polzo) << endl;
        break;
    }

    case 11: {
        string na, lasta, addr, new_ar;
        store polzo;

        cout << "Введите название, адрес и количество товаров магазина: " << endl;
        cin >> na;
        cin >> lasta;
        cin >> addr;

        polzo.set_inf(na, lasta, addr);
        cout << polzo.inf(polzo) << endl;

        cout << "Введите новое количество товаров: " << endl;
        cin >> new_ar;

        polzo.new_kola(new_ar);
        cout << polzo.inf(polzo) << endl;
        break;
    }

    case 12: {
        string na, lasta, addr, new_ar;
        store polzo;

        cout << "Введите название, адрес и количество клиентов банка: " << endl;
        cin >> na;
        cin >> lasta;
        cin >> addr;

        polzo.set_inf(na, lasta, addr);
        cout << polzo.inf(polzo) << endl;

        cout << "Введите новое количество клиентов: " << endl;
        cin >> new_ar;

        polzo.new_kola(new_ar);
        cout << polzo.inf(polzo) << endl;
        break;
    }

    case 13: {
        string na, lasta, addr, new_ar;
        university kolleg;

        cout << "Введите название, адрес и количество студентов университета: " << endl;
        cin >> na;
        cin >> lasta;
        cin >> addr;

        kolleg.set_inf(na, lasta, addr);
        cout << kolleg.inf(kolleg) << endl;

        cout << "Введите новое количество студентов: " << endl;
        cin >> new_ar;

        kolleg.new_kols(new_ar);
        cout << kolleg.inf(kolleg) << endl;
        break;
    }

    case 14: {
        string na, lasta, addr, new_ar;
        school kolleg;

        cout << "Введите название, адрес и количество учеников школы: " << endl;
        cin >> na;
        cin >> lasta;
        cin >> addr;

        kolleg.set_inf(na, lasta, addr);
        cout << kolleg.inf(kolleg) << endl;

        cout << "Введите новое количество учеников: " << endl;
        cin >> new_ar;

        kolleg.new_kolu(new_ar);
        cout << kolleg.inf(kolleg) << endl;
        break;
    }

    case 15: {
        string na, lasta, addr, new_ar;
        library libro;

        cout << "Введите название, адрес и количество книг библиотеки: " << endl;
        cin >> na;
        cin >> lasta;
        cin >> addr;

        libro.set_inf(na, lasta, addr);
        cout << libro.inf(libro) << endl;

        cout << "Введите новое количество книг: " << endl;
        cin >> new_ar;

        libro.new_kolb(new_ar);
        cout << libro.inf(libro) << endl;
        break;
    }

    case 16: {
        string na, lasta, addr, new_ar;
        museum muss;

        cout << "Введите название, адрес и количество экспонатов музея: " << endl;
        cin >> na;
        cin >> lasta;
        cin >> addr;

        muss.set_inf(na, lasta, addr);
        cout << muss.inf(muss) << endl;

        cout << "Введите новое количество экспонатов: " << endl;
        cin >> new_ar;

        muss.new_kole(new_ar);
        cout << muss.inf(muss) << endl;
        break;
    }

    case 17: {
        string na, lasta, addr, new_ar;
        theater tthe;

        cout << "Введите название, адрес и количество спектаклей театра: " << endl;
        cin >> na;
        cin >> lasta;
        cin >> addr;

        tthe.set_inf(na, lasta, addr);
        cout << tthe.inf(tthe) << endl;

        cout << "Введите новое количество спектаклей: " << endl;
        cin >> new_ar;

        tthe.new_kols(new_ar);
        cout << tthe.inf(tthe) << endl;
        break;
    }

    case 18: {
        string na, lasta, addr, new_ar;
        absolutecinema kino;

        cout << "Введите название, адрес и количество фильмов кинотеатра: " << endl;
        cin >> na;
        cin >> lasta;
        cin >> addr;

        kino.set_inf(na, lasta, addr);
        cout << kino.inf(kino) << endl;

        cout << "Введите новое количество фильмов: " << endl;
        cin >> new_ar;

        kino.new_kolac(new_ar);
        cout << kino.inf(kino) << endl;
        break;
    }

    case 19: {
        string na, lasta, addr, new_ar;
        restoran dish;

        cout << "Введите название, адрес и количество блюд ресторана: " << endl;
        cin >> na;
        cin >> lasta;
        cin >> addr;

        dish.set_inf(na, lasta, addr);
        cout << dish.inf(dish) << endl;

        cout << "Введите новое количество блюд: " << endl;
        cin >> new_ar;

        dish.new_kold(new_ar);
        cout << dish.inf(dish) << endl;
        break;
    }

    case 20: {
        string na, lasta, addr, new_ar;
        cafe cofee;

        cout << "Введите название, адрес и количество напитков кафе: " << endl;
        cin >> na;
        cin >> lasta;
        cin >> addr;

        cofee.set_inf(na, lasta, addr);
        cout << cofee.inf(cofee) << endl;

        cout << "Введите новое количество напитков: " << endl;
        cin >> new_ar;

        cofee.new_kolnap(new_ar);
        cout << cofee.inf(cofee) << endl;
        break;
    }

    case 21: {
        string na, lasta, addr, new_ar;
        hotel hptp;

        cout << "Введите название, адрес и количество номеров отеля: " << endl;
        cin >> na;
        cin >> lasta;
        cin >> addr;

        hptp.set_inf(na, lasta, addr);
        cout << hptp.inf(hptp) << endl;

        cout << "Введите новое количество номеров: " << endl;
        cin >> new_ar;

        hptp.new_kolnom(new_ar);
        cout << hptp.inf(hptp) << endl;
        break;
    }

    case 22: {
        string na, lasta, addr, new_ar;
        airport hptp;

        cout << "Введите название, адрес и количество рейсов аэропорта: " << endl;
        cin >> na;
        cin >> lasta;
        cin >> addr;

        hptp.set_inf(na, lasta, addr);
        cout << hptp.inf(hptp) << endl;

        cout << "Введите новое количество рейсов: " << endl;
        cin >> new_ar;

        hptp.new_kolnom(new_ar);
        cout << hptp.inf(hptp) << endl;
        break;
    }

    case 23: {
        string na, lasta, addr, new_ar;
        airport hptp;

        cout << "Введите название, адрес и количество поездов железнодорожной станции: " << endl;
        cin >> na;
        cin >> lasta;
        cin >> addr;

        hptp.set_inf(na, lasta, addr);
        cout << hptp.inf(hptp) << endl;

        cout << "Введите новое количество поездов: " << endl;
        cin >> new_ar;

        hptp.new_kolnom(new_ar);
        cout << hptp.inf(hptp) << endl;
        break;
    }

    case 24: {
        string na, lasta, addr, new_ar;
        bus hptp;

        cout << "Введите название, адрес и количество автобусов автобусной станции: " << endl;
        cin >> na;
        cin >> lasta;
        cin >> addr;

        hptp.set_inf(na, lasta, addr);
        cout << hptp.inf(hptp) << endl;

        cout << "Введите новое количество автобусов: " << endl;
        cin >> new_ar;

        hptp.new_kolnom(new_ar);
        cout << hptp.inf(hptp) << endl;
        break;
    }

    case 25: {
        string na, lasta, addr, new_ar;
        park hptp;

        cout << "Введите название, адрес и количество деревьев парка: " << endl;
        cin >> na;
        cin >> lasta;
        cin >> addr;

        hptp.set_inf(na, lasta, addr);
        cout << hptp.inf(hptp) << endl;

        cout << "Введите новое количество деревьев: " << endl;
        cin >> new_ar;

        hptp.new_kolnom(new_ar);
        cout << hptp.inf(hptp) << endl;
        break;
    }

    case 26: {
        string na, lasta, addr, new_ar;
        sad hptp;

        cout << "Введите название, адрес и количество цветов сада: " << endl;
        cin >> na;
        cin >> lasta;
        cin >> addr;

        hptp.set_inf(na, lasta, addr);
        cout << hptp.inf(hptp) << endl;

        cout << "Введите новое количество цветов: " << endl;
        cin >> new_ar;

        hptp.new_kolnom(new_ar);
        cout << hptp.inf(hptp) << endl;
        break;
    }

    case 27: {
        string na, lasta, addr, new_ar;
        zoo hptp;

        cout << "Введите название, адрес и количество животных зоопарка: " << endl;
        cin >> na;
        cin >> lasta;
        cin >> addr;

        hptp.set_inf(na, lasta, addr);
        cout << hptp.inf(hptp) << endl;

        cout << "Введите новое количество животных: " << endl;
        cin >> new_ar;

        hptp.new_kolnom(new_ar);
        cout << hptp.inf(hptp) << endl;
        break;
    }

    case 28: {
        string na, lasta, addr, new_ar;
        apuarium hptp;

        cout << "Введите название, адрес и количество рыб аквариума: " << endl;
        cin >> na;
        cin >> lasta;
        cin >> addr;

        hptp.set_inf(na, lasta, addr);
        cout << hptp.inf(hptp) << endl;

        cout << "Введите новое количество рыб: " << endl;
        cin >> new_ar;

        hptp.new_kolnom(new_ar);
        cout << hptp.inf(hptp) << endl;
        break;
    }

    case 29: {
        string na, lasta, addr, new_ar;
        musumisk musso;

        cout << "Введите название, адрес и количество экспонатов музея: " << endl;
        cin >> na;
        cin >> lasta;
        cin >> addr;

        musso.set_inf(na, lasta, addr);
        cout << musso.inf(musso) << endl;

        cout << "Введите новое количество экспонатов: " << endl;
        cin >> new_ar;

        musso.new_kole(new_ar);
        cout << musso.inf(musso) << endl;
        break;
    }

    case 30: {
        string na, lasta, addr, new_ar;
        theater tthe;

        cout << "Введите название, адрес и количество спектаклей театра: " << endl;
        cin >> na;
        cin >> lasta;
        cin >> addr;

        tthe.set_inf(na, lasta, addr);
        cout << tthe.inf(tthe) << endl;

        cout << "Введите новое количество спектаклей: " << endl;
        cin >> new_ar;

        tthe.new_kols(new_ar);
        cout << tthe.inf(tthe) << endl;
        break;
    }
    default:
        break;
    }
    
}