#include <iostream>
#include <random>
using namespace std;

void zadano1()
{
    int xummus[5];
    setlocale(LC_ALL, "RU");
    cout << "Введите 5 целых чисел массива: " << endl;
    for (int i = 0; i <= size(xummus) - 1; i++) {
        cin >> xummus[i];
    }
    cout << (xummus[0] + xummus[1] + xummus[2] + xummus[3] + xummus[4]);
}

void zadano2()
{
    int xummus[10];
    setlocale(LC_ALL, "RU");
    cout << "Введите 10 целых чисел массива: " << endl;
    for (int i = 0; i <= size(xummus) - 1; i++) {
        cin >> xummus[i];
    }
    int max = xummus[0];
    for (int i = 0; i <= 9; i++) {
        if (xummus[i] > max)
            max = xummus[i];
    }
    cout << max;
}

void zadano3()
{
    int xummus[10];
    setlocale(LC_ALL, "RU");
    cout << "Введите 10 целых чисел массива: " << endl;
    for (int i = 0; i <= size(xummus) - 1; i++) {
        cin >> xummus[i];
    }
    int min = xummus[0];
    for (int i = 0; i <= 9; i++) {
        if (xummus[i] < min)
            min = xummus[i];
    }
    cout << min;
}

void zadano4() {

    int xummus[6];
    double sum = 0;
    setlocale(LC_ALL, "RU");
    cout << "Введите 6 целых чисел массива: " << endl;
    for (int i = 0; i <= size(xummus) - 1; i++) {
        cin >> xummus[i];
    }

    for (int i = 0; i <= 5; i++)
    {
        sum += xummus[i];
    }
    sum /= 6;
    cout << sum;
}

void zadano5() {
    {
        int xummus[5];
        setlocale(LC_ALL, "RU");
        cout << "Введите 5 целых чисел массива: " << endl;
        for (int i = 0; i <= size(xummus) - 1; i++) {
            cin >> xummus[i];
        }

        for (int i = 4; i >= 0; i--)
        {
            cout << xummus[i];
        }
    }
}

void zadano6() {
    int plus = 0;
    int minus = 0;
    int xummus[10];
    setlocale(LC_ALL, "RU");
    cout << "Введите 10 целых чисел массива: " << endl;
    for (int i = 0; i < size(xummus); i++) {
        cin >> xummus[i];
    }

    for (int i = 0; i < size(xummus); i++) {
        if (xummus[i] > 0)
        {
            plus++;
        }
        else if (xummus[i] < 0)
        {
            minus++;
        }
    }
    cout << "Положительных чисел: " << plus << endl;
    cout << "Отрицательных чисел: " << minus << endl;
}

void zadano7()
{
    {

        int a;
        int xummus[10];
        setlocale(LC_ALL, "RU");
        cout << "Введите 10 целых чисел массива: " << endl;
        for (int i = 0; i <= size(xummus) - 1; i++) {
            cin >> xummus[i];
        }
        cout << "Введите число которое хотите найти: " << endl;
        cin >> a;

        for (int i = 0; i <= 9; i++) {
            if (xummus[i] = a)
            {
                cout << "индекс нужного числа = " << i;
            }


        }
    }
}

void zadano8() {
    int xummus[5];
    setlocale(LC_ALL, "RU");
    cout << "Введите 5 целых чисел массива: " << endl;
    for (int i = 0; i <= size(xummus) - 1; i++) {
        cin >> xummus[i];
    }
    for (int i = 0; i <= 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if (xummus[j] > xummus[j + 1])
            {
                swap(xummus[j], xummus[j + 1]);
            }

        }
    }
    for (int i = 0; i <= 4; i++) {
        cout << xummus[i] << ' ';
    }
}

void zadano9()
{
    vector<int> xummus(10);
    int n;

    cout << "Введите 10 целых чисел:" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> xummus[i];
    }
    cout << "введите какое число по счету вы хотиде удолить из массива";
    cin >> n;
    xummus.erase(xummus.begin() + n - 1);
    for (int i = 0; i < xummus.size(); i++)
    {
        cout << xummus[i] << " ";
    }
}

void zadano10()
{
    setlocale(LC_ALL, "RU");
    int xummus[5];
    int copy[5];


    cout << "Введите 5 целых чисел: " << endl;
    for (int i = 0; i < 5; i++) {
        cin >> xummus[i];
    }


    for (int i = 0; i < 5; i++) {
        copy[i] = xummus[i];
    }

    cout << "Скопированные элементы: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << copy[i] << ' ';
    }
}

void zadano11()
{
    setlocale(LC_ALL, "RU");
    int xummus1[3];
    int xummus2[3];
    int bavabeba[size(xummus1) + size(xummus2)];

    if (size(xummus1) == size(xummus2)) {
        cout << "Введите 3 целых чисел первого массива: " << endl;
        for (int i = 0; i <= size(xummus1) - 1; i++) {
            cin >> xummus1[i];
        }
        cout << "Введите 3 целых чисел второго массива: " << endl;
        for (int i = 0; i <= size(xummus2) - 1; i++) {
            cin >> xummus2[i];
        }

        for (int i = 0; i <= size(xummus1) - 1; i++){
            bavabeba[i] = xummus1[i];
        }
        for (int i = 3; i <= size(bavabeba) - 1; i++) {
            bavabeba[i] = xummus2[i-3];
        }

        cout << "Массивы вместе: " << endl;
        for (int i = 0; i <= size(bavabeba) - 1; i++) {
            cout << bavabeba[i];
        }
    }
    else {
        cout << "Размеры массивов не равны.";
    }
}

void zadano12() {
    int xummus[10];
    vector<int> chet;
    vector<int> nechet;

    cout << "Введите 10 целых чисел: " << endl;
    for (int i = 0; i < 10; i++) {
        cin >> xummus[i];
    }
    for (int i = 0; i < 10; i++)
    {
        if (xummus[i] % 2 == 0)
        {
            chet.push_back(xummus[i]);

        }
        else
        {
            nechet.push_back(xummus[i]);
        }

    }
    cout << "Чётные : ";
    for (int i = 0; i < chet.size(); i++)
    {
        cout << chet[i] << " ";
    }
    cout << "Нёчетные: ";
    for (int i = 0; i < nechet.size(); i++)
    {
        cout << nechet[i] << " ";
    }
}

void zadano13()
{
    setlocale(LC_ALL, "RU");
    int xummus[6];
    bool symmetry = true;
    int j = size(xummus) - 1;

    cout << "Введите 6 целых чисел массива: " << endl;
    for (int i = 0; i <= size(xummus) - 1; i++) {
        cin >> xummus[i];
    }

    for (int i = 0; i <= j; i++, j--) {
        char a = xummus[i];
        char b = xummus[j];
        
        if (a != b) {
            symmetry = false;
        }
    }

    if (symmetry == false) {
        cout << "Массив не симметричен.";
    }
    else {
        cout << "Массив симметричен.";
    }
}

void zadano14()
{
    int xummus[5];
    vector<int> kvadrat;


    cout << "Введите 5 целых чисел: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> xummus[i];
    }
    for (int i = 0; i < 5; i++)
    {
        kvadrat.push_back(pow(xummus[i], 2));
    }
    cout << "Квадрат чисел в массиве: ";
    for (int i = 0; i < kvadrat.size(); i++)
    {
        cout << kvadrat[i] << " ";
    }
}

void zadano15() 
{
    int cheto = 0;
    int necheto = 0;
    int xummus[6];
    setlocale(LC_ALL, "RU");
    cout << "Введите 6 целых чисел массива: " << endl;
    for (int i = 0; i <= size(xummus) - 1; i++) {
        cin >> xummus[i];
    }

    for (int i = 0; i <= size(xummus) - 1; i++) {
        if (xummus[i] % 2 == 0)
        {
            cheto++;
        }
        else if (xummus[i] % 2 != 0)
        {
            necheto++;
        }
    }
    cout << "Количество нечётных элементов массива: " << necheto << endl;
    cout << "Количество чётных элементов массива: " << cheto << endl;
}

void zadano16() {
    int xummus[10];
    bool dublicat = false;

    cout << "Введите 5 целых чисел: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> xummus[i];
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (xummus[i] == xummus[j] && i != j)
                dublicat = true;
            break;
        }
    }
    if (dublicat)
    {
        cout << "В массиве есть дубликат.";
    }
    else {
        cout << "Дубликата нет";
    }
}

void zadano17() 
{
    setlocale(LC_ALL, "RU");
    int xummus[6];
    cout << "Введите 6 целых чисел массива: " << endl;
    for (int i = 0; i <= size(xummus) - 1; i++) {
        cin >> xummus[i];
    }
    int end = xummus[0];

    for (int i = 0; i <= size(xummus) - 1; i++) {
        xummus[i] = xummus[i + 1];
    }
    xummus[size(xummus) - 1] = end;
    cout << "Массив со сдвигом влево: " << endl;
    for (int i = 0; i <= size(xummus) - 1; i++) {
        cout << xummus[i] << endl;
    }
}

void zadano18()
{
    int xummus[8];
    setlocale(LC_ALL, "RU");
    cout << "Введите 8 целых чисел: " << endl;
    for (int i = 0; i <= size(xummus) - 1; i++) {
        cin >> xummus[i];
    }

    int max = 0;
    int resultMax = 0;

    for (int i = 0; i <= size(xummus) - 1; i++) {
        if (xummus[i] > max) {
            max = xummus[i];
        }
    }
    for (int i = 0; i <= size(xummus) - 1; i++) {
        if (xummus[i] > resultMax) {
            if (resultMax < max && max != xummus[i]) {
                resultMax = xummus[i];
            }
        }
    }
    cout << "Второе наибольшее число массива: " << resultMax << endl;;
}

void zadano19()
{
    setlocale(LC_ALL, "RU");
    int xummus[10];
    random_device rndbn;
    mt19937 gdr(rndbn());
    uniform_int_distribution<> dis(0, 1500);

    for (int i = 0; i <= size(xummus) - 1; i++) {
        xummus[i] = dis(gdr);
    }
    cout << "Массив случайных чисел: " << endl;
    for (int i = 0; i <= size(xummus) - 1; i++) {
        cout << xummus[i] << endl;
    }
}

void zadano20()
{
    setlocale(LC_ALL, "RU");
    int xummus1[6];
    int xummus2[6];
    bool ravnost = true;
    int j = 0;

    cout << "Введите 6 целых чисел первого массива: " << endl;
    for (int i = 0; i <= size(xummus1) - 1; i++) {
        cin >> xummus1[i];
    }
    cout << "Введите 6 целых чисел второго массива: " << endl;
    for (int i = 0; i <= size(xummus2) - 1; i++) {
        cin >> xummus2[i];
    }

    for (int i = 0; i <= size(xummus1) - 1; i++, j++) {
        char a = xummus1[i];
        char b = xummus2[j];

        if (a != b) {
            ravnost = false;
        }
    }

    if (ravnost == false) {
        cout << "Массивы не равны.";
    }
    else {
        cout << "Массивы равны.";
    }
}

int main()
{
    setlocale(LC_ALL, "RU");
    int nomer;
    cout << "Введите номер задания: " << endl;
    cin >> nomer;

    switch (nomer)
    {
    case 1:
        zadano1();
        break;
    case 2:
        zadano2();
        break;
    case 3:
        zadano3();
        break;
    case 4:
        zadano4();
        break;
    case 5:
        zadano5();
        break;
    case 6:
        zadano6();
        break;
    case 7:
        zadano7();
        break;
    case 8:
        zadano8();
        break;
    case 9:
        zadano9();
        break;
    case 10:
        zadano10();
        break;
    case 11:
        zadano11();
        break;
    case 12:
        zadano12();
        break;
    case 13:
        zadano13();
        break;
    case 14:
        zadano14();
        break;
    case 15:
        zadano15();
        break;
    case 17:
        zadano17();
        break;
    case 18:
        zadano18();
        break;
    case 19:
        zadano19();
        break;
    case 20:
        zadano20();
        break;
    default:
        break;
    }
}