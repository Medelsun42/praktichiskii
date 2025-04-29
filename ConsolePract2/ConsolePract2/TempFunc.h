#include <iostream>
#include <vector>
#include <stdexcept> 
#include <algorithm> 
#include <list>
#include <map>
#include <set>

using namespace std;

template <typename T> void swapnums(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T> int minmass(T mass[], int size) {
	T temp = mass[0];
	for (int i = 0; i < size; i++) {
		if (mass[i] < temp) {
			temp = mass[i];
		}
	}
	return temp;
}

template <typename T> T arraySum(const T array[], int size) {
	T sum = 0;
	for (int i = 0; i < size; i++) {
		sum += array[i];
	}
	return sum;
}

template <typename T> void copyArr(const T arr1[], T arr2[], int size) {
	for (int i = 0; i < size; ++i) {
		arr2[i] = arr1[i];
	}
}

template <typename T> void areEqual(const T& a, const T& b) {
	if (a == b) {
		cout << "Числа равны.";
	}
	else {
		cout << "Числа не равны";
	}
}

template <typename T>
void reverseArray(T arr[], int size) {
	for (int i = 0; i < size / 2; ++i) {
		swap(arr[i], arr[size - 1 - i]);
	}
}

template <typename T>
int findIndex(const T arr[], int size, const T& value) {
	for (int i = 0; i < size; ++i) {
		if (arr[i] == value) {
			return i;
		}
	}
	return -1; // Not found
}

template <typename T>
T* mergeArrays(const T arr1[], int size1, const T arr2[], int size2) {
	T* result = new T[size1 + size2];
	for (int i = 0; i < size1; ++i) {
		result[i] = arr1[i];
	}
	for (int i = 0; i < size2; ++i) {
		result[size1 + i] = arr2[i];
	}
	return result;
}

template <typename T>
double average(const T arr[], int size) {
	if (size <= 0) throw invalid_argument("Array size must be positive");

	T sum = arraySum(arr, size);
	return static_cast<double>(sum) / size;
}

template <typename T, typename Predicate>
T* filterArray(const T arr[], int size, Predicate pred, int& resultSize) {
	resultSize = 0;
	for (int i = 0; i < size; ++i) {
		if (pred(arr[i])) {
			resultSize++;
		}
	}

	T* result = new T[resultSize];
	int index = 0;
	for (int i = 0; i < size; ++i) {
		if (pred(arr[i])) {
			result[index++] = arr[i];
		}
	}

	return result;
}

template <typename T>
T findSecondMax(const T arr[], int size) {
	if (size < 2) throw invalid_argument("Array must have at least 2 elements");

	T max1 = max(arr[0], arr[1]);
	T max2 = min(arr[0], arr[1]);

	for (int i = 2; i < size; ++i) {
		if (arr[i] > max1) {
			max2 = max1;
			max1 = arr[i];
		}
		else if (arr[i] > max2) {
			max2 = arr[i];
		}
	}

	return max2;
}

template <typename T> vector<T> arrayToVector(const T arr[], int size) {
	vector<T> result;
	for (int i = 0; i < size; ++i) {
		result.push_back(arr[i]);
	}
	return result;
}

template <typename T> vector<T> arrayIntersection(const T arr1[], int size1, const T arr2[], int size2) {
	set<T> set1(arr1, arr1 + size1);
	set<T> set2(arr2, arr2 + size2);
	vector<T> result;

	set_intersection(set1.begin(), set1.end(),
		set2.begin(), set2.end(),
		back_inserter(result));

	return result;
}

template <typename T>
void bubbleSort(T arr[], int size) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}