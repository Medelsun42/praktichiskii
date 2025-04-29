#include <iostream>
#include "TempFunc.h"
#include "TempClass.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    int goon;

    cout << "Выберите задание (1 - 27): ";
    cin >> goon;

    switch (goon)
    {
    case 1: {
        int a, b;
        cout << "Введите два значения: " << endl;
        cin >> a;
        cin >> b;
        swapnums(a, b);
        cout << "Обратный порядок: " << a << ", " << b << endl;
        break;
    }
    case 2: {
        double a;
        string b;
        Pair<double, string> pair{ 24.8, "привет" };
        a = pair.getfirst();
        b = pair.getsecond();
        cout << "Полученные значения из класса: " << a << " и " << b;
        break;
    }
    case 3: {
        int massive[]{ 15, 78, 654684, 1, -1684, 1531 };
        cout << "Массив: " << endl;
        for (int i = 0; i < size(massive); i++) {
            cout << massive[i] << "\n";
        }
        cout << "Минимальный элемент массива: " << minmass(massive, size(massive));
        break;
    }
    case 4: {
        Point<int> twoD1{ 0, 0 };
        twoD1.print();
        Point<int> twoD2{ 15, 4 };
        twoD2.print();

        Point<int> summa = twoD1 + twoD2;
        summa.print();
        Point<int> minus = twoD1 - twoD2;
        minus.print();
        break;
    }
    case 5: {
        double array[]{ 15.4, 895.9, 68468.48, 4.5 };
        cout << "Массив: " << endl;
        for (int i = 0; i < size(array); i++) {
            cout << array[i] << "\n";
        }
        cout << "Сумма элементов массива: " << arraySum(array, size(array));
        break;
    }
    case 6: {
        Stack<int> stk;
        stk.push(135);
        stk.push(34);
        stk.push(908);
        stk.push(12535);
        stk.print();

        stk.pop();
        stk.print();

        cout << stk.top();

        if (stk.empty()) {
            cout << "Стек пустой.";
        }
        else {
            cout << "Стек не пустой.";
        }
        break;
    }
    case 7: {
        int src[5]{ 15, 46, 988, 744, 789456123 };
        int newsrc[5];
        copyArr(src, newsrc, size(src));

        for (int i = 0; i < size(newsrc); i++) {
            cout << newsrc[i] << "\n";
        }
        break;
    }
    case 8: {
        Array<int> arr;
        arr.push(12535);
        arr.push(908);
        arr.push(34);
        arr.push(135);

        cout << arr[15];
        break;
    } 
    case 9: {
        int a = 4;
        int b = 19;
        areEqual(a, b);
        break;
    }
    case 10: {
        Complex<int> comp1{ 15, 44 };
        comp1.print();
        Complex<int> comp2{ 56, 13 };
        comp2.print();

        Complex<int> summa = comp1 + comp2;
        Complex<int> minus = comp1 - comp2;
        summa.print();
        minus.print();
        break;
    }
    case 11: {
        int src[5]{ 15, 46, 988, 744, 789456123 };
        for (int i = 0; i < size(src); i++) {
            cout << src[i] << "\n";
        }
        reverseArray(src, size(src));

        for (int i = 0; i < size(src); i++) {
            cout << src[i] << "\n";
        }
        break;
    }
    case 12: {
        Queue<int> queue;
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        queue.enqueue(4);
        queue.print();

        cout << queue.front();
    }
    case 13: {
        int array[]{ 15, 4, 88 };
        cout << findIndex(array, size(array), 4) << endl;
        cout << findIndex(array, size(array), 158) << endl;
        break;
    }
    case 14: {
        DynamicArray<float> da;
        da.add(1.5f); da.add(2.5f); da.add(3.5f);
        cout << "Dynamic array: ";
        for (int i = 0; i < da.size(); i++) cout << da[i] << " ";
        cout << endl << endl;
        break;
    }
    case 15: {
        int a1[] = { 1, 2 }, a2[] = { 3, 4, 5 };
        int* merged = mergeArrays(a1, 2, a2, 3);
        cout << "Merged arrays: ";
        for (int i = 0; i < 5; i++) cout << merged[i] << " ";
        delete[] merged;
        cout << endl << endl;
        break;
    }
    case 16: {
        Matrix<int> m1(2, 2), m2(2, 2);
        m1[0][0] = 1; m1[0][1] = 2; m1[1][0] = 3; m1[1][1] = 4;
        m2[0][0] = 5; m2[0][1] = 6; m2[1][0] = 7; m2[1][1] = 8;
        auto m3 = m1 + m2;
        cout << "Matrix sum:\n";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) cout << m3[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        break;
    }
    case 17: {
        double vals[] = { 1.0, 2.0, 3.0, 4.0 };
        cout << "Average: " << average(vals, 4) << endl << endl;
        break;
    }
    case 18: {
        List<string> list;
        list.pushBack("first");
        list.pushBack("second");
        list.pushFront("zero");
        cout << "List size: " << list.size() << endl << endl;
        break;
    }
    case 19: {
        int nums[] = { 1, 2, 3, 4, 5, 6 };
        int size;
        int* evens = filterArray(nums, 6, [](int x) { return x % 2 == 0; }, size);
        cout << "Even numbers: ";
        for (int i = 0; i < size; i++) cout << evens[i] << " ";
        delete[] evens;
        cout << endl << endl;
        break;
    }
    case 20: {
        Point<double> p1(0, 0), p2(4, 0), p3(0, 3);
        Triangle<double> triangle(p1, p2, p3);
        cout << "Triangle area: " << triangle.area() << endl << endl;
        break;
    }
    case 21: {
        int nums[] = { 5, 3, 8, 1, 9, 4 };
        cout << "Second max: " << findSecondMax(nums, 6) << endl << endl;
        break;
    }
    case 22: {
        Graph<string> graph;
        graph.addEdge("A", "B");
        graph.addEdge("B", "C");
        cout << "Has edge A-B: " << (graph.hasEdge("A", "B") ? "true" : "false") << endl << endl;
        break;
    }
    case 23: {
        char chars[] = { 'a', 'b', 'c' };
        vector<char> vec = arrayToVector(chars, 3);
        cout << "Vector: ";
        for (char c : vec) cout << c << " ";
        cout << endl << endl;
        break;
    }
    case 24: {
        Cube<double> cube(3.0);
        cout << "Cube volume: " << cube.volume() << ", surface area: " << cube.surfaceArea() << endl << endl;
        break;
    }
    case 25: {
        int a1[] = { 1, 2, 3, 4 }, a2[] = { 3, 4, 5, 6 };
        vector<int> intersection = arrayIntersection(a1, 4, a2, 4);
        cout << "Intersection: ";
        for (int x : intersection) cout << x << " ";
        cout << endl << endl;
        break;
    }
    case 26: {
        Wrapper<int> w(42);
        cout << "Wrapper value: " << w.get() << endl;
        w.set(100);
        cout << "After set: " << w.get() << endl << endl;
        break;
    }
    case 27: {
        float arr[] = { 5.5f, 2.2f, 7.7f, 1.1f };
        bubbleSort(arr, 4);
        cout << "Sorted array: ";
        for (int i = 0; i < 4; i++) cout << arr[i] << " ";
        cout << endl;
        break;
    }
    default:
        break;
    }
};