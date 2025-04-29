#include <iostream>
#include "Functions.h"

using namespace std; 

int main()
{
    setlocale(LC_ALL, "RU");
    
    int zad;
    cout << "Введите номер задания (1 - 9): ";
    cin >> zad;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (zad)
    {
    case 1: {
        vector<int> numbers;
        int temp;

        cout << "Введите числа (любая буква для завершения): " << endl;
        while (cin >> temp) {
            numbers.push_back(temp);
        }

        arraySort(numbers);
        break;
    }
    case 2: {
        string input;
        cout << "Введите текст: " << endl;
        getline(cin, input);

        countVowCons(input);
        break;
    }
    case 3: {
        vector<string> lines;
        string line;

        cout << "Введите строки (пустая строка для завершения):\n";
        while (getline(cin, line) && !line.empty()) {
            lines.push_back(line);
        }

        sortSTR(lines);
        break;
    }
    case 4: {
        int num;
        cout << "Введите число: ";
        cin >> num;

        multipTab(num);
        break;
    }
    case 5: {
        ifstream file("input.txt");
        if (!file) {
            cerr << "Ошибка открытия файла" << std::endl;
            return 1;
        }

        countSTR(file);
        break;
    }
    case 6: {
        ifstream file("input.txt");
        if (!file) {
            cerr << "Ошибка открытия файла" << std::endl;
            return 1;
        }

        unikW(file);
        break;
    }
    case 7: {
        string input;
        cout << "Введите строку: ";
        getline(std::cin, input);

        symb(input);
        break;
    }
    case 8: {
        vector<std::string> lines;
        string line;
        size_t max_len = 0;

        cout << "Введите строки (пустая строка для завершения):\n";
        while (getline(cin, line) && !line.empty()) {
            lines.push_back(line);
            max_len = max(max_len, line.length());
        }

        tabSTR(lines, max_len);
    }
    case 9: {
        vector<double> numbers;
        double num; cout << "Введите числа (любая буква для завершения): ";

        while (std::cin >> num) {
            numbers.push_back(num);
        }

        if (numbers.empty()) {
            std::cerr << "Не введено чисел" << std::endl;
            return 1;
        }

        stats(numbers);
    }
    default:
        break;
    }
}