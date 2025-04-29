#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <string>
using namespace std;

int zadano1(int* ukaz, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(ukaz + i);
    }
    return sum;
}

void zadano2()
{
    int xummus[6];

    cout << "Введите 6 целых чисел массива: " << endl;
    for (int i = 0; i <= size(xummus) - 1; i++) {
        cin >> xummus[i];
    }
    
    int max = xummus[0];

    for (int i = 0; i <= size(xummus) - 1; i++) {
        int *p{ &xummus[i]};
        if (*p > max) {
            max = *p;
        }
    }

    cout << "Максимальное число массива: " << max << endl;
}

void zadano3()
{
    int xummus[6];

    cout << "Введите 6 целых чисел массива: " << endl;
    for (int i = 0; i <= size(xummus) - 1; i++) {
        cin >> xummus[i];
    }

    int min = xummus[0];

    for (int i = 0; i <= 4; i++) {
        int* pmass{ &xummus[i] };
        if (*pmass < min) {
            min = *pmass;
        }
    }

    cout << "Минимальный элемент: " << min << endl;
}

void zadano4(int mas[5], int size)
{
    int* start = mas;
    int* end = mas + size - 1;

    while (start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
    for (int i = 0; i < size; i++)
    {
        cout << mas[i] << " ";
    }
}

void zadano5()
{
    int xummus[5];
    int key, result = -1;

    cout << "Введите 5 целых чисел массива: " << endl;
    for (int i = 0; i <= size(xummus) - 1; i++) {
        cin >> xummus[i];
    }

    cout << "Введите какой элемент хотите найти в массиве: ";
    cin >> key;
    cout << "" << endl;
    for (int i = 0; i <= size(xummus) - 1; i++) {
        int *p{ &xummus[i] };
        if (*p == key) {
            result = i;
            break;
        }
    }

    if (result != -1) {
        cout << "Массив находится на индексе: " << result << endl;
    }
    else {
        cout << result << endl;
    }
}

void zadano6()
{
    int size = 5;
    int mas[] = { 6, 22, 8, 3, 10 };

    int* arr = mas;

    cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int element;
    cout << "Введите элемент для удаления: ";
    cin >> element;


    int* p = arr;
    int* end = arr + size;

    for (; p < end; ++p) {
        if (*p == element) {
            for (int* q = p; q < end - 1; ++q) {
                *q = *(q + 1);
            }
            --size;
            break;
        }
    }
    cout << "Массив после удаления элемента: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

void zadano7(int mas1[], int mas2[]) {
    vector<int> obedinenie(int mas1[5], int mas2[5]);
    
    vector <int> obed;
    for (int i = 0; i < 5; i++)
    {
        int* ukaz{ &mas1[i] };
        obed.push_back(*ukaz);
    }
    for (int i = 0; i < 5; i++)
    {
        int* ukaz{ &mas2[i] };
        obed.push_back(*ukaz);
    }
    
    for (int i : obed) {
        cout << i << endl;
    }
}

void zadano8() {
    vector<int> arr = { 45, 1388, 1437, 52, 48, 52, 1388 };
    set<int> uniqueelements;

    for (int num : arr) {
        uniqueelements.insert(num);
    }

    for (int i : uniqueelements) {
        cout << i << endl;
    }
}

void zadano9()
{
    int xummus[7];
    int sizeo = size(xummus);

    cout << "Введите 7 целых чисел массива: " << endl;
    for (int i = 0; i <= size(xummus) - 1; i++) {
        cin >> xummus[i];
    }

    int* arr = xummus;
    cout << "Исходный массив: ";
    for (int i = 0; i < sizeo; ++i) {
        cout << arr[i] << " ";

    }
    cout << endl;
    //сортировка массива методом пузырька
    for (int i = 0; i < sizeo - 1; ++i) {
        for (int j = 0; j < sizeo - i - 1; ++j) {
            if (*(arr + j) > *(arr + j + 1)) {
                //меняем местами элементы
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
    cout << "Отсортированный массив: ";
    for (int i = 0; i < sizeo; ++i) {
        cout << arr[i] << " ";

    }
    cout << endl;

}

int zadano10(int mas1[5], int mas2[5])
{

    int sumobed = 0;
    for (int i = 0; i < 5; i++)
    {
        int* ukaz{ &mas1[i] };
        sumobed += *ukaz;

    }
    for (int i = 0; i < 5; i++)
    {
        int* ukaz{ &mas2[i] };
        sumobed += *ukaz;

    }
    return sumobed;
}

void zadano11() 
{
    int xummus[8];
    int copirka[size(xummus)];

    cout << "Введите 8 целых чисел массива: " << endl;
    for (int i = 0; i <= size(xummus) - 1; i++) {
        cin >> xummus[i];
    }

    for (int i = 0; i <= size(copirka) - 1; i++) {
        int* p{ &xummus[i] };
        copirka[i] = *p;
    }

    cout << "" << endl;

    for (int i = 0; i <= size(copirka) - 1; i++) {
        cout << copirka[i] << endl;
    }
}

void zadano12() {
    const int size1 = 5;
    const int size2 = 5;
    int mas1[] = { 6, 22, 8, 3, 10 };
    int mas2[] = { 23, 2, 18, 34, 11 };
    int* arr1 = mas1;
    int* arr2 = mas2;
    int result = 0;

    cout << "массив 1: ";
    for (int i = 0; i < size1; ++i) {
        cout << arr1[i] << " ";

    }
    cout << endl;
    cout << "массив 2: ";
    for (int i = 0; i < size2; ++i) {
        cout << arr2[i] << " ";

    }
    cout << endl;

    if (size1 < size2) result = -1;
    else if (size1 > size2) result = 1;
    else {

        for (int i = 0; i < size1; ++i) {
            if (*(arr1 + i) < *(arr2 + i)) {
                result = -1;
                break;
            }
            else if (*(arr1 + i) > *(arr2 + i)) {
                result = 1;
                break;
            }
        }
    }
}

void zadano13(int mas[5], int size)
{
    int* start = mas;
    int* end = mas + size - 1;

    while (start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
    for (int i = 0; i < size; i++)
    {
        cout << mas[i] << " ";
    }
}

void zadano14()
{
    int xummus[10];

    cout << "Введите 10 целых чисел массива: " << endl;
    for (int i = 0; i <= size(xummus) - 1; i++) {
        cin >> xummus[i];
    }

    int* p{ xummus };

    cout << "Количество элементов в массиве: " << size(xummus) << endl;

}

void zadano15()
{
    vector<int> arr = { 12, 88, 17, 32, 43, 51, 58 };
    set<int> uniqueelements;

    for (int num : arr) {
        uniqueelements.insert(num);
    }

    for (int i : uniqueelements) {
        cout << i << endl;
    }
}

void zadano16(int a) {
    vector <int> zadano16;
    int facto = 1;
    vector <int> result;
    for (int i = 1; i <= a; i++)
    {
        facto *= i;
        result.push_back(facto);
    }
    for (int i : result) {
        cout << i << endl;
    }
}

void zadano17()
{
    int n, result = 0;
    cout << "Введите число n: ";
    cin >> n;

    vector<int> mass;

    for (int i = 0; i <= n; i++) {
        mass.push_back(result);
        result += ((pow((1 + sqrt(5)), i) - pow((1 - sqrt(5)), i)) / (pow(2, i) * sqrt(5)));
    }

    cout << "Числа Фибоначчи от 0 до n: " << endl;
    cout << 0 << endl;
    for (int i : mass) {
        cout << i << endl;
    }
}

void zadano18()
{
    int chis, step;

    cout << "Введите число: ";
    cin >> chis;
    cout << "Введите степень: ";
    cin >> step;

    if (step < 0) {
        cout << "Степень должна быть положительным целым числом." << endl;
    }

    vector<int> powers;

    for (int i = 0; i <= step; ++i) {
        powers.push_back(pow(chis, i));
    }

    cout << "Степени числа " << chis << " до степени " << step << ":" << endl;
    for (int i = 0; i <= step; ++i) {
        cout << chis << "^" << i << " = " << powers[i] << endl;
    }

}

void zadano19(int a) 
{
    vector<int> prosto(int a);
    vector<int> prostoe;
    bool prime = true;

    if (a == 0 || a < 0 || a == 1) {
        cout << "данные введены не корректно ";
    }
    else {
        for (int i = 2; i <= sqrt(abs(a)); i++) {
            if (a % i == 0) {
                prime = false;
                break;
            }
        }

        if (prime) {
            cout << "Число простое" << endl;
            for (int num = 2; num <= a; num++) {
                bool isPrime = true;
                for (int i = 2; i <= sqrt(num); i++) {
                    if (num % i == 0) {
                        isPrime = false;
                        break;
                    }
                }
                if (isPrime) {
                    prostoe.push_back(num);
                }
            }
        }
        else {
            cout << "Число составное" << endl;
        }
    }
    for (int i : prostoe) {
        cout << i << endl;
    }
}

void zadano20()
{
    string xummus;

    cout << "Введите строку: " << endl;
    cin >> xummus;
    vector<char> sigmo;

    for (int i = size(xummus) - 1; i >= 0; i--) {
        sigmo.push_back(xummus[i]);
    }

    cout << "" << endl;

    for (char i : sigmo) {
        cout << i;
    }
}

void zadano21()
{
    const int size1 = 5;
    const int size2 = 5;
    int mas1[] = { 6, 22, 8, 3, 10 };
    int mas2[] = { 23, 2, 18, 34, 11 };
    int* arr1 = mas1;
    int* arr2 = mas2;
    int result = 0;

    cout << "массив 1: ";
    for (int i = 0; i < size1; ++i) {
        cout << arr1[i] << " ";

    }
    cout << endl;
    cout << "массив 2: ";
    for (int i = 0; i < size2; ++i) {
        cout << arr2[i] << " ";

    }
    cout << endl;

    if (size1 < size2) result = -1;
    else if (size1 > size2) result = 1;
    else {

        for (int i = 0; i < size1; ++i) {
            if (*(arr1 + i) < *(arr2 + i)) {
                result = -1;
                break;
            }
            else if (*(arr1 + i) > *(arr2 + i)) {
                result = 1;
                break;
            }
        }
    }

    if (result == 0) {
        std::cout << "0. Массивы равны." << std::endl;
    }
    else if (result == -1) {
        std::cout << "-1. Первый массив меньше второго." << std::endl;
    }
    else {
        std::cout << "1. Первый массив больше второго." << std::endl;
    }

}

void zadano22(string str) {
    vector<char> glas(string str);
    vector<char> vowels;
    const string vowelsString = "aeiouAEIOU";

    for (char ch : str) {

        if (vowelsString.find(ch) != string::npos) {
            vowels.push_back(ch);
        }
    }

    for (char i : vowels) {
        cout << i << endl;
    }
}

void zadano23()
{
    string xummus;
    char zam, zom;

    cout << "Введите строку: " << endl;
    cin >> xummus;
    vector<char> sigmo;

    cout << "Введите символ для замены: ";
    cin >> zam;
    cout << "Введите заменяющий символ: ";
    cin >> zom;

    for (int i = 0; i <= size(xummus) - 1; i++) {
        if (xummus[i] == zam) {
            sigmo.push_back(zom);
        }
        else {
            sigmo.push_back(xummus[i]);
        }
    }

    cout << "" << endl;

    for (char i : sigmo) {
        cout << i;
    }
}

void zadano24()
{
    string xummus;

    cout << "Введите строку: " << endl;
    cin >> xummus;
    vector<char> viktor;

    for (int i = size(xummus) - 1; i >= 0; i--) {
        viktor.push_back(xummus[i]);
    }

    cout << "" << endl;

    for (char i : viktor) {
        cout << i << endl;
    }
}

void zadano25() {
    const int size1 = 5;
    const int size2 = 5;
    int mas1[] = { 6, 22, 8, 3, 10 };
    int mas2[] = { 23, 2, 18, 34, 11 };
    int* arr1 = mas1;
    int* arr2 = mas2;
    int result = 0;

    cout << "массив 1: ";
    for (int i = 0; i < size1; ++i) {
        cout << arr1[i] << " ";

    }
    cout << endl;
    cout << "массив 2: ";
    for (int i = 0; i < size2; ++i) {
        cout << arr2[i] << " ";

    }
    cout << endl;

    if (size1 < size2) result = -1;
    else if (size1 > size2) result = 1;
    else {

        for (int i = 0; i < size1; ++i) {
            if (*(arr1 + i) < *(arr2 + i)) {
                result = -1;
                break;
            }
            else if (*(arr1 + i) > *(arr2 + i)) {
                result = 1;
                break;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "RU");
    int nomer;
    cout << "Введите номер задания: " << endl;
    cin >> nomer;

    int vareni4ki[] = { 45, 1388, 1437, 52, 48, 52, 1388 };
    int* ukaz{ vareni4ki };
    int sizemas = sizeof(vareni4ki) / sizeof(vareni4ki[0]);
    int n;
    int a = 11;
    string strgo = "asdhsahdhassaHSAKDHKASdh";

    int mas1[]{ 1,2,3,4,5 };
    int mas2[]{ 6,7,8,9,10 };
    int fac = 10;

    switch (nomer) {
    case 1:
        cout << zadano1(ukaz, sizemas);
        break;
    case 2:
        zadano2();
        break;
    case 3:
        zadano3();
        break;
    case 4:
        zadano4;
        break;
    case 5:
        zadano5();
        break;
    case 6:
        zadano6();
        break;
    case 7:
        zadano7;
        break;
    case 8:
        zadano8();
        break;
    case 9:
        zadano9();
        break;
    case 10:
        zadano10;
        break;
    case 11:
        zadano11();
        break;
    case 12:
        zadano12();
        break;
    case 13:
        zadano13;
        break;
    case 14:
        zadano14();
        break;
    case 15:
        zadano15();
        break;
    case 16:
        zadano16(a);
        break;
    case 17:
        zadano17();
        break;
    case 18:
        zadano18();
        break;
    case 19:
        zadano19(a);
        break;
    case 20:
        zadano20();
        break;
    case 21:
        zadano21();
        break;
    case 22:
        zadano22(strgo);
        break;
    case 23:
        zadano23();
        break;
    case 24:
        zadano24();
        break;
    case 25:
        zadano25();
        break;
    default:
        break;
    }
}