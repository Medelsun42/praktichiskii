#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <string>
#include <limits>

using namespace std;

double divideNumbers(double a, double b) {
    if (b == 0) {
        throw runtime_error("Division by zero is not allowed");
    }
    return a / b;
}

void checkAge(int age) {
    if (age < 0 || age > 120) {
        throw out_of_range("Age must be between 0 and 120");
    }
}

int sumArray(const int arr[], int size) {
    if (size < 0) {
        throw invalid_argument("Array size cannot be negative");
    }
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

double calculateSquareRoot(double num) {
    if (num < 0) {
        throw domain_error("Cannot calculate square root of negative number");
    }
    return sqrt(num);
}

int findElement(const int arr[], int size, int element) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == element) {
            return i;
        }
    }
    throw runtime_error("Element not found in array");
}

class Divider {
public:
    static double divide(double a, double b) {
        if (b == 0) {
            throw runtime_error("Division by zero in Divider class");
        }
        return a / b;
    }
};

class Age {
private:
    int age;
public:
    Age(int a) : age(a) {
        if (a < 0 || a > 120) {
            throw out_of_range("Invalid age for Age class (0-120)");
        }
    }
    int getAge() const { return age; }
};

class MyArray {
private:
    vector<int> data;
public:
    MyArray(const int arr[], int size) {
        if (size < 0) {
            throw invalid_argument("Negative size for MyArray");
        }
        data.assign(arr, arr + size);
    }

    int getElement(int index) const {
        if (index < 0 || index >= static_cast<int>(data.size())) {
            throw out_of_range("Index out of bounds in MyArray");
        }
        return data[index];
    }
};

class Fraction {
private:
    int numerator;
    int denominator;
public:
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denom == 0) {
            throw runtime_error("Denominator cannot be zero in Fraction");
        }
    }
    double value() const { return static_cast<double>(numerator) / denominator; }
};

class SquareRoot {
public:
    static double calculate(double num) {
        if (num < 0) {
            throw domain_error("Negative number in SquareRoot class");
        }
        return sqrt(num);
    }
};

class MyCustomException : public exception {
public:
    const char* what() const noexcept override {
        return "This is a custom exception";
    }
};

void functionThatThrowsCustomException() {
    throw MyCustomException();
}

void logErrorToFile(const string& errorMessage) {
    ofstream errorFile("errors.log", ios::app);
    if (errorFile.is_open()) {
        errorFile << errorMessage << endl;
        errorFile.close();
    }
}

void intermediateFunction() {
    try {
        functionThatThrowsCustomException();
    }
    catch (const MyCustomException& e) {
        cout << "Caught in intermediate: " << e.what() << endl;
        throw; // повторный выброс
    }
}

// 1. Класс Calculator
class Calculator {
public:
    static double add(double a, double b) { return a + b; }
    static double subtract(double a, double b) { return a - b; }
    static double multiply(double a, double b) { return a * b; }
    static double divide(double a, double b) {
        if (b == 0) {
            throw runtime_error("Division by zero");
        }
        return a / b;
    }
};

// 2. Функция ввода числа
double getNumberFromUser() {
    double num;
    cout << "Enter a number: ";
    cin >> num;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Input is not a number");
    }

    return num;
}

// 3. Класс Stack
class Stack {
private:
    vector<int> data;
public:
    void push(int value) {
        data.push_back(value);
    }

    int pop() {
        if (data.empty()) {
            throw out_of_range("Stack is empty");
        }
        int value = data.back();
        data.pop_back();
        return value;
    }
};

// 4. Класс Point
class Point {
private:
    double x, y;
public:
    Point(double x, double y) : x(x), y(y) {
        const double limit = 100.0;
        if (x < -limit || x > limit || y < -limit || y > limit) {
            throw out_of_range("Coordinates must be between -100 and 100");
        }
    }

    void print() const {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

// 5. Функция чтения файла
string readFileContent(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("File not found: " + filename);
    }

    string content((istreambuf_iterator<char>(file)),
        istreambuf_iterator<char>());
    file.close();
    return content;
}

// 6. Класс StringArray
class StringArray {
private:
    vector<string> strings;
public:
    void addString(const string& str) {
        strings.push_back(str);
    }

    string getString(int index) const {
        if (index < 0 || index >= static_cast<int>(strings.size())) {
            throw out_of_range("Index out of bounds in StringArray");
        }
        return strings[index];
    }
};

// 7. Класс Square
class Square {
private:
    double side;
public:
    Square(double s) : side(s) {
        if (s < 0) {
            throw invalid_argument("Side length cannot be negative");
        }
    }

    double area() const { return side * side; }
};

// 8. Функция конвертации строки в число
int stringToInt(const string& str) {
    try {
        return stoi(str);
    }
    catch (const invalid_argument&) {
        throw invalid_argument("String cannot be converted to integer: " + str);
    }
    catch (const out_of_range&) {
        throw out_of_range("Number is too large: " + str);
    }
}

// 9. Класс FileHandler
class FileHandler {
private:
    ifstream file;
public:
    explicit FileHandler(const string& filename) {
        file.open(filename);
        if (!file.is_open()) {
            throw runtime_error("Cannot open file: " + filename);
        }
    }

    ~FileHandler() {
        if (file.is_open()) {
            file.close();
        }
    }

    string readLine() {
        string line;
        getline(file, line);
        return line;
    }
};

int main() {

    LC_ALL(setlocale, "RU");

    int pou;
    cout << "Введите номер задания (1 - 27): ";
    cin >> pou;

    switch (pou)
    {
    case 1: {
        // Деление чисел
        try {
            cout << "10 / 2 = " << divideNumbers(10, 2) << endl;
            cout << "10 / 0 = " << divideNumbers(10, 0) << endl;
        }
        catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
            logErrorToFile(e.what());
        }
        break;
    }
    case 2: {
        // Проверка возраста
        try {
            checkAge(25);
            checkAge(-5);
        }
        catch (const out_of_range& e) {
            cout << "Age error: " << e.what() << endl;
        }
        break;
    }
    case 3: {
        // Сумма массива
        int arr[] = { 1, 2, 3, 4, 5 };
        try {
            cout << "Sum: " << sumArray(arr, 5) << endl;
            cout << "Sum: " << sumArray(arr, -1) << endl;
        }
        catch (const invalid_argument& e) {
            cout << "Array error: " << e.what() << endl;
        }
        break;
    }
    case 4: {
        // Квадратный корень
        try {
            cout << "sqrt(16) = " << calculateSquareRoot(16) << endl;
            cout << "sqrt(-1) = " << calculateSquareRoot(-1) << endl;
        }
        catch (const domain_error& e) {
            cout << "Math error: " << e.what() << endl;
        }
        break;
    }
    case 5: {
        // Поиск элемента
        int arr[] = { 1, 2, 3, 4, 5 };
        try {
            cout << "Element 3 found at index: " << findElement(arr, 5, 3) << endl;
            cout << "Element 10 found at index: " << findElement(arr, 5, 10) << endl;
        }
        catch (const runtime_error& e) {
            cout << "Search error: " << e.what() << endl;
        }
        break;
    }
    case 6: {
        // Класс Divider
        try {
            cout << "Divider: " << Divider::divide(10, 2) << endl;
            cout << "Divider: " << Divider::divide(10, 0) << endl;
        }
        catch (const runtime_error& e) {
            cout << "Divider error: " << e.what() << endl;
        }
        break;
    }
    case 7: {
        // Класс Age
        try {
            Age validAge(30);
            Age invalidAge(150);
        }
        catch (const out_of_range& e) {
            cout << "Age class error: " << e.what() << endl;
        }
        break;
    }
    case 8: {
        // Класс MyArray
        int arr[] = { 1, 2, 3, 4, 5 };
        try {
            MyArray myArray(arr, 5);
            cout << "Element at index 2: " << myArray.getElement(2) << endl;
            cout << "Element at index 10: " << myArray.getElement(10) << endl;
        }
        catch (const exception& e) {
            cout << "MyArray error: " << e.what() << endl;
        }
        break;
    }
    case 9: {
        // Класс Fraction
        try {
            Fraction f1(1, 2);
            cout << "Fraction value: " << f1.value() << endl;
            Fraction f2(1, 0);
        }
        catch (const runtime_error& e) {
            cout << "Fraction error: " << e.what() << endl;
        }
        break;
    }
    case 10: {
        // Класс SquareRoot
        try {
            cout << "Square root of 25: " << SquareRoot::calculate(25) << endl;
            cout << "Square root of -25: " << SquareRoot::calculate(-25) << endl;
        }
        catch (const domain_error& e) {
            cout << "SquareRoot error: " << e.what() << endl;
        }
        break;
    }
    case 11: {
        // Пользовательское исключение
        try {
            functionThatThrowsCustomException();
        }
        catch (const MyCustomException& e) {
            cout << "Caught custom exception: " << e.what() << endl;
        }
        break;
    }
    case 12: {
        // Обработка нескольких типов исключений
        try {
            int x = 10;
            if (x > 5) throw logic_error("Logical error");
            if (x < 0) throw out_of_range("Range error");
        }
        catch (const logic_error& e) {
            cout << "Logic error: " << e.what() << endl;
        }
        catch (const out_of_range& e) {
            cout << "Range error: " << e.what() << endl;
        }
        catch (...) {
            cout << "Unknown error" << endl;
        }
        break;
    }
    case 13: {
        // Повторный выброс исключения
        try {
            intermediateFunction();
        }
        catch (const MyCustomException& e) {
            cout << "Caught in main: " << e.what() << endl;
        }
        break;
    }
    case 14: {
        // Calculator
        try {
            cout << "10 / 2 = " << Calculator::divide(10, 2) << endl;
            cout << "10 / 0 = " << Calculator::divide(10, 0) << endl;
        }
        catch (const runtime_error& e) {
            cout << "Calculator error: " << e.what() << endl;
        }
        break;
    }
    case 15: {
        // Ввод числа
        try {
            double num = getNumberFromUser();
            cout << "You entered: " << num << endl;
        }
        catch (const invalid_argument& e) {
            cout << "Input error: " << e.what() << endl;
        }
        break;
    }
    case 16: {
        // Stack
        Stack s;
        try {
            s.push(10);
            cout << "Popped: " << s.pop() << endl;
            cout << "Popped: " << s.pop() << endl;
        }
        catch (const out_of_range& e) {
            cout << "Stack error: " << e.what() << endl;
        }
        break;
    }
    case 17: {
        // Point
        try {
            Point p1(10, 20);
            p1.print();
            Point p2(1000, 2000);
        }
        catch (const out_of_range& e) {
            cout << "Point error: " << e.what() << endl;
        }
        break;
    }
    case 18: {
        // Чтение файла
        try {
            string content = readFileContent("example.txt");
            cout << "File content: " << content << endl;
        }
        catch (const runtime_error& e) {
            cout << "File error: " << e.what() << endl;
        }
        break;
    }
    case 19: {
        // StringArray
        StringArray sa;
        sa.addString("Hello");
        sa.addString("World");
        try {
            cout << "String at 0: " << sa.getString(0) << endl;
            cout << "String at 2: " << sa.getString(2) << endl;
        }
        catch (const out_of_range& e) {
            cout << "StringArray error: " << e.what() << endl;
        }
        break;
    }
    case 20: {
        // Square
        try {
            Square sq1(5);
            cout << "Square area: " << sq1.area() << endl;
            Square sq2(-5);
        }
        catch (const invalid_argument& e) {
            cout << "Square error: " << e.what() << endl;
        }
        break;
    }
    case 21: {
        // Конвертация строки в число
        try {
            cout << "Converted: " << stringToInt("123") << endl;
            cout << "Converted: " << stringToInt("abc") << endl;
        }
        catch (const exception& e) {
            cout << "Conversion error: " << e.what() << endl;
        }
        break;
    }
    case 22: {
        // FileHandler
        try {
            FileHandler fh("nonexistent.txt");
            string line = fh.readLine();
            cout << "First line: " << line << endl;
        }
        catch (const runtime_error& e) {
            cout << "FileHandler error: " << e.what() << endl;
        }
        break;
    }
    case 23: {
        // Обработка разных исключений
        try {
            // Вызов функции, выбрасывающий исключение
            Calculator::divide(10, 0);
        }
        catch (const invalid_argument& e) {
            cout << "Invalid argument: " << e.what() << endl;
        }
        catch (const out_of_range& e) {
            cout << "Out of range: " << e.what() << endl;
        }
        catch (const runtime_error& e) {
            cout << "Runtime error: " << e.what() << endl;
        }
        catch (...) {
            cout << "Unknown error occurred" << endl;
        }
        break;
    }
    default:
        break;
    }
}