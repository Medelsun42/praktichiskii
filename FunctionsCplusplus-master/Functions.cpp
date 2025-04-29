#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <list>
#include <algorithm>
using namespace std;

//Задание 1

/*int summa(int a);

int main()
{
    setlocale(LC_ALL, "RU");

    int z;

    cout << "Введите число Z: " << endl;;
    cin >> z;

    cout << "Сумма чисел от 1 до Z: " << summa(z) << endl;
}

int summa(int a) {
    int n = 0;

    for (int i = 1; i <= a; i++) {
        i % 2 == 0 ? n += i : n += 0;
    }
    return n;
}*/

//Задание 2

/*string polind(string palo);

int main() {
    setlocale(LC_ALL, "RU");

    string polin;

    cout << "Введите слово: " << endl;
    cin >> polin;
    cout << endl;

    cout << polind(polin) << endl;
}

string polind(string palo) {
    int k = palo.length() - 1;
    bool symmetry = true;

    for (int i = 0; i > k; i++, k--) {
        char b = palo[i];
        char a = palo[k];
        if (b != a) {
            symmetry = false;
            break;
        }
    }
    if (symmetry == false) {
        return "Не является палиндромом.";
    }
    else {
        return "Является палиндромом!";
    }
}*/

//Задание 3

/*string tsin(int num);

int main() {
    setlocale(LC_ALL, "RU");

    int h;

    cout << "Введите число h: " << endl;
    cin >> h;
    cout << tsin(h) << endl;
}

string tsin(int num) {
    int min = to_string(num)[0] - 48;
    char newmin;
    int max = to_string(num)[0] - 48;
    char newmax;

    for (int i = 0; i <= to_string(num).length() - 1; i++) {
        newmin = to_string(num)[i];
        int(newmin) - 48 <= min ? min = int(newmin) - 48 : min;
    }
    for (int i = 0; i <= to_string(num).length() - 1; i++) {
        newmax = to_string(num)[i];
        if (int(newmax) - 48 >= max) {
            max = int(newmax) - 48;;
        }
    }
    return to_string(min) + to_string(max);
}*/

//Задание 4

/*void roma(int n);

int main()
{
    setlocale(LC_ALL, "RU");

    int z;

    cout << "Введите число z" << endl;
    cin >> z;
    roma(z);
}

void roma(int n) {
    int units = n % 10;
    int tens = n / 10 % 10;
    int hundreds = n / 100 % 10;
    int thousands = n / 1000 % 10;
    switch (thousands)
    {
    case 1:
        cout << "M";
        break;
    case 2:
        cout << "MM";
        break;
    case 3:
        cout << "MMM";
        break;
    default:
        break;
    }
    switch (hundreds)
    {
    case 1:
        cout << "C";
        break;
    case 2:
        cout << "CC";
        break;
    case 3:
        cout << "CCC";
        break;
    case 4:
        cout << "CD";
        break;
    case 5:
        cout << "D";
        break;
    case 6:
        cout << "DC";
        break;
    case 7:
        cout << "DCC";
        break;
    case 8:
        cout << "DCCC";
        break;
    case 9:
        cout << "CM";
        break;
    default:
        break;
    }
    switch (tens)
    {
    case 1:
        cout << "X";
        break;
    case 2:
        cout << "XX";
        break;
    case 3:
        cout << "XXX";
        break;
    case 4:
        cout << "XL";
        break;
    case 5:
        cout << "L";
        break;
    case 6:
        cout << "LX";
        break;
    case 7:
        cout << "LXX";
        break;
    case 8:
        cout << "LXXX";
        break;
    case 9:
        cout << "XC";
        break;
    default:
        break;
    }
    switch (units)
    {
    case 1:
        cout << "I";
        break;
    case 2:
        cout << "II";
        break;
    case 3:
        cout << "III";
        break;
    case 4:
        cout << "IV";
        break;
    case 5:
        cout << "V";
        break;
    case 6:
        cout << "VI";
        break;
    case 7:
        cout << "VII";
        break;
    case 8:
        cout << "VIII";
        break;
    case 9:
        cout << "IX";
        break;
    default:
        break;
    }

}*/

//Задание 5

/*int factorn(int g);

int main() {
    setlocale(LC_ALL, "RU");

    int zov;

    cout << "Введите число zov: " << endl;
    cin >> zov;
    cout << factorn(zov) << endl;
}

int factorn(int g) {
    int a = 1;
    int result = 0;

    for (int i = 1; i <= g; i++) {
        a *= i;
        result += a;
    }
    return result;
}*/

//Задание 6
/*int sumquadro(int n);

int main()
{
    setlocale(LC_ALL, "RU");

    int u;

    cout << "Введите число u: ";
    cin >> u;

    int result = sumquadro(u);
    cout << "Сумма квадратов чисел от 1 до u: " << result;
}

int sumquadro(int n)
{
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += pow(i, 2);
    }
    return sum;
}*/

//Задание 7

/*int loga(int n, int b);

int main() {
    setlocale(LC_ALL, "RU");

    int h, m;

    cout << "Введите аргумент логарифма: " << endl;
    cin >> h;
    cout << "Введите основание логарифма: " << endl;
    cin >> m;
    cout << loga(h, m) << endl;
}
int loga(int n, int b) {
    int result;

    result = log(n) / log(b);

    return result;
}*/

//Задание 8
/*int summachisel(int n);

int main()
{
    setlocale(LC_ALL, "RU");

    int q;

    cout << "Введите число q: ";
    cin >> q;
    int result = summachisel(q);

    cout << "сумма цифр числа q = " << result;
}

int summachisel(int n)
{
    int sumaa = 0;
    while (n > 0) {
        sumaa += n % 10;
        n /= 10;
    }
    return sumaa;
}*/

//Задание 9

/*string perfect(int a);

int main() {
    setlocale(LC_ALL, "RU");

    int p;

    cout << "Введите аргумент логарифма: " << endl;
    cin >> p;
    cout << perfect(p) << endl;
}

string perfect(int a) {
    list<int> listo{};
    int zaglo = 0;

    for (int i = 1; i < a; i++) {
        if (a % i == 0) {
            listo.push_back(i);
        }
    }
    list<int>::iterator iter = listo.begin();
    for (int i = 0; i < listo.size(); i++) {
        zaglo += *iter;
        iter++;
    }
    if (zaglo == a) {
        return "Число является совершенным!";
    }
    else {
        return "Число не является совершенным!";
    }
}*/

//Задание 10

/*void drobi(int x1, int x2, int x3, int x4);

int main() {

    setlocale(LC_ALL, "RU");

    int x1, x2, x3, x4;
    
    cout << "Введите делимое первой дроби: ";
    cin >> x1;
    cout << "Введите делитель первой дроби: ";
    cin >> x2;
    cout << "Введите делимое второй дроби: ";
    cin >> x3;
    cout << "Введите делитель второй дроби: ";
    cin >> x4;

    drobi(x1, x2, x3, x4);
}

void drobi(int x1, int x2, int x3, int x4) {
    float obschidelitel = x2 * x4;
    float obschidelimoe = (x1 * x4) + (x3 * x2);

    if (obschidelimoe >= obschidelitel) {
        int wholePart = obschidelimoe / obschidelitel;

        if (obschidelimoe == 0) {
            cout << wholePart;
        }
        else {
            cout << (obschidelimoe / obschidelitel) << endl;
        }
    }
    else {
        cout << obschidelimoe << '/' << obschidelitel;
    }
}*/

//Задание 11

/*string deliteli(int x);

int main() {
    setlocale(LC_ALL, "RU");

    int f;

    cout << "Введите число: ";
    cin >> f;

    cout << "Все делители числа: " << endl;
    cout << deliteli(f);
}

string deliteli(int x) {
    list<int> dels;

    for (int i = 1; i <= x; i++) {
        if (x % i == 0) {
            dels.push_back(i);
        }
    }
    for (int i : dels) {
        cout << i << endl;
    }
    return "";
}*/

//Задание 12

/*int NODs(int a, int b);

int main() {
    int xa, xb;
    setlocale(LC_ALL, "RU");

    cout << "Введите первое число: ";
    cin >> xa;
    cout << "Введите второе число: ";
    cin >> xb;

    int nod = NODs(xa, xb);

    cout << "Наибольший общий делитель" << xa << " " << xb << " = " << nod << endl;
}

int NODs(int a, int b) {
    while (b != 0) {
        int c = b;
        b = a % b;
        a = c;
    }
    return a;
}*/

//Задание 13

/*int summafib(int b);

int main() {
    setlocale(LC_ALL, "RU");

    int g;
    
    cout << "Введите число: ";
    cin >> g;

    cout << "Сумма чисел фибоначи: " << summafib(g) << endl;
}

int summafib(int b) {
    int zaglo = 1;
    if (b == 0) {
        return 0;
    }
    else if (b == 1) {
        return 1;
    }
    else {
        for (int i = 2; i <= b; i++) {
            zaglo += (pow((1 + sqrt(5)), i) - pow((1 - sqrt(5)), i)) / (pow(2, i) * sqrt(5));
        }
        return zaglo;
    }
}*/

//Задание 14
/*void sortString(string str) {
    int n = str.length();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (str[j] > str[j + 1]) {
                swap(str[j], str[j + 1]);
            }
        }
    }
}

int main() {
    string input;
    setlocale(LC_ALL, "RU");
    cout << "Введите строку: ";
    cin >> input;

    sortString(input);

    cout << "Отсортированная строка: " << input << endl;
}*/

//Задание 15

/*string anogrammo(string first, string second);

int main() {
    setlocale(LC_ALL, "RU");

    string ano, grammo;

    cout << "Введите первое слово: ";
    cin >> ano;
    cout << "Введите второе слово: ";
    cin >> grammo;
    cout << endl;

    cout << anogrammo(ano, grammo) << endl;
}

string anogrammo(string first, string second) {
    bool babobe = true;
    list<int> zaglo;

    if (first.length() == second.length()) {
        sort(first.begin(), first.end());
        sort(second.begin(), second.end());

        if (first == second) {
            return "Строки являются анаграммами!";
        }
        else {
            return "Строки не являются анаграммами.";
        }
    }
    else {
        return "Строки не являются анаграммами.";
    }
}*/

//Задание 16

/*string operation(string str1, string str2, size_t length);

int main() {
    string str1, str2;
    size_t length;
    setlocale(LC_ALL, "RU");
    cout << "Введите первую строку: ";
    cin >> str1;
    cout << "Введите вторую строку: ";
    cin >> str2;
    cout << "Введите максимальную длину строки: ";
    cin >> length;

    string result = operation(str1, str2, length);

    cout << "Результат : " << result;


}

string operation(string str1, string str2, size_t length) {

    string result = str1 + str2;
    if (result.length() > length)
    {
        result = result.substr(0, length);
    }
    return result;
}*/

//Задание 17

/*string deleto(string str);

int main() {
    setlocale(LC_ALL, "RU");

    string stroko;

    cout << "Введите строку: ";
    cin >> stroko;

    cout << "Сортированная строка без повторения символов: ";
    cout << deleto(stroko);
}

string deleto(string str) {
    unique_copy(str.begin(), str.end(), ostreambuf_iterator<char>(cout));
    return "";
}*/

//Задание 18

/*int showsravnenie(int a, int b, int c, int d);

int main()
{
    int x1, x2, x3, x4;
    setlocale(LC_ALL, "RU");
    cout << "Введите делимое первой дроби: ";
    cin >> x1;
    cout << "Введите делитель первой дроби: ";
    cin >> x2;
    cout << "Введите делимое второй дроби: ";
    cin >> x3;
    cout << "Введите делитель второй дроби: ";
    cin >> x4;

    int result = showsravnenie(x1, x2, x3, x4);

    cout << "Результат сравнения: " << result << endl;
}

int showsravnenie(int a, int b, int c, int d) {
    double brob1 = a / b;
    double brob2 = c / d;

    if (brob1 > brob2) {
        return 1;
    }
    else if (brob1 < brob2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}*/

//Задание 19

/*string uppero(string str);

int main() {
    setlocale(LC_ALL, "RU");

    string str;

    cout << "Введите строку: ";
    cin >> str;

    cout << "Строка с символами верхнего регистра: ";
    cout << uppero(str);
}

string uppero(string str) {
    for (int i = 0; i <= str.length() - 1; i++) {
        str[i] = toupper(str[i]);
    }
     return str;
}*/


//Задание 20
/*void armstrongnumber(string n);

int main()
{
    string n;
    setlocale(LC_ALL, "RU");
    cout << "Введите число n: ";
    cin >> n;
    armstrongnumber(n);

}

void armstrongnumber(string n) {
    int length = n.length();
    int sum = 0;
    for (int i = 0; i < n.length(); i++)
    {
        char a = n[i];
        int number = a - 48;
        sum += pow(number, length);

    }
    int c = stoi(n);
    if (c == sum)
    {
        cout << "Это число армстронга!" << endl;
    }
    else
    {
        cout << "Это не число армстронга." << endl;
    }
}*/