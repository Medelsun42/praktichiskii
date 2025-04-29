#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <iomanip>
#include <fstream>
#include <set>
#include <numeric>
#include <sstream>
#include <map>

using namespace std;

template <typename T> void arraySort(vector<T> array) {
	sort(array.begin(), array.end());

	cout << "Отсортированный массив: " << endl;
	for (T i : array) {
		cout << i << " ";
	}
}

void countVowCons(string some) {
	int vowels = 0, consonants = 0;
	some.erase(remove(some.begin(), some.end(), ' '));

	for (char z : some) {
		if (isalpha(z)) {
			z = tolower(z);
			if (z == 'a' || z == 'e' || z == 'i' || z == 'o' || z == 'u') {
				vowels++;
			}
			else {
				consonants++;
			}
		}
	}

	cout << "Гласных: " << vowels << "\n" << "Согласных: " << consonants;
}

void sortSTR(vector<string> lnr) {
	sort(lnr.begin(), lnr.end());
	cout << "\nОтсортированные строки:\n";
	for (const auto& l : lnr) {
		cout << setw(20) << left << l << endl;
	}
}

void multipTab(int num) {
	cout << "Таблица умножения для " << num << ":\n";
	for (int i = 1; i <= 10; ++i) {
		cout << setw(2) << num << " x " << setw(2) << i << " = " << setw(3) << num * i << endl;
	}
}

void countSTR(ifstream& file) {
	int lines = 0, words = 0, chars = 0;
	string line;

	while (getline(file, line)) {
		lines++;
		chars += line.length();
		chars += lines;

		istringstream iss(line);
		string word;
		while (iss >> word) {
			words++;
		}
	}

	cout << "Строк: " << lines << "\nСлов: " << words << "\nСимволов: " << chars << endl;
}

string normalize(const string& word) {
	string result;
	for (char c : word) {
		if (isalpha(c)) {
			result += tolower(c);
		}
	}
	return result;
}

void unikW(ifstream& file) {
	set<string> unique_words;
	string word;

	while (file >> word) {
		word = normalize(word);
		if (!word.empty()) {
			unique_words.insert(word);
		}
	}
	cout << "Уникальные слова:\n";
	for (const auto& w : unique_words) {
		cout << w << endl;
	}
}

void symb(string input) {
	int chars = 0, spaces = 0, punct = 0;

	for (char c : input) {
		chars++;
		if (isspace(c)) {
			spaces++;
		}
		else if (ispunct(c)) {
			punct++;
		}
	}

	cout << left << setw(15) << "Символов:" << chars << '\n' << setw(15) << "Пробелов:" << spaces << '\n' << setw(15) << "Знаков препинания:" << punct << endl;
}

void tabSTR(vector<string> lnr, size_t max_len) {
	for (const auto& l : lnr) {
		cout << setw(max_len) << right << l << endl;
	}
}

void stats(vector<double> numbers) {
	double sum = std::accumulate(numbers.begin(), numbers.end(), 0.0);
	double mean = sum / numbers.size();

	sort(numbers.begin(), numbers.end());
	double median = numbers.size() % 2 == 0 ?
		(numbers[numbers.size() / 2 - 1] + numbers[numbers.size() / 2]) / 2 :
		numbers[numbers.size() / 2];

	map<double, int> counts;
	for (double n : numbers) {
		counts[n]++;
	}
	double mode = numbers[0];
	int max_count = 0;
	for (const auto& pair : counts) {
		if (pair.second > max_count) {
			max_count = pair.second;
			mode = pair.first;
		}
	}

	cout << std::fixed << std::setprecision(2);
	cout << "Среднее: " << mean << "\nМедиана: " << median << "\nМода: " << mode << endl;
}