#include <iostream>
#include <vector>
#include <stdexcept> 
#include <algorithm> 
#include <list>
#include <map>
#include <set>

using namespace std;

template <typename T, typename D>
class Pair {
public:
	Pair(T first, D second) : first{ first }, second{ second } {}
	
	T getfirst() {
		return first;
	}
	D getsecond() {
		return second;
	}
private:
	T first;
	D second;
};

template <typename T>
class Point {
	T x, y;
public: 
	Point(T x, T y) : x(x), y(y) {}

	Point operator+(const Point& other) const { return Point(x + other.x, y + other.y); }

	Point operator-(const Point& other) const { return Point(x - other.x, y - other.y); }

	void print() const { cout << "(" << x << "," << y << ")"; }

	T getX() const { return x; }
	T getY() const { return y; }

	void setX(T x) { this->x = x; }
	void setY(T y) { this->y = y; }
};

template <typename T>
class Stack {
	vector<T> data;
public:
	void push(const T& value) { data.push_back(value); }
	void pop() { data.pop_back(); }
	T top() const { cout << "\n"; return data.back(); }
	bool empty() const { cout << "\n"; return data.empty(); }

	void print() const { cout << "\n";  copy(data.begin(), data.end(), ostream_iterator<T>(cout, " ")); }
};

template <typename T>
class Complex {
	T real, imag;
public:
	Complex(T r = 0, T i = 0) : real(r), imag(i) {}

	Complex operator+(const Complex& other) const {
		return Complex(real + other.real, imag + other.imag);
	}

	Complex operator-(const Complex& other) const {
		return Complex(real - other.real, imag - other.imag);
	}

	void print() const { cout << real << "+" << imag << "i" << "\n"; }
};

template <typename T>
class Queue {
	list<T> data;
public:
	void enqueue(const T& value) { data.push_back(value); }
	void dequeue() { data.pop_front(); }
	T front() const { return data.front(); }
	bool empty() const { return data.empty(); }

	void print() const {
		for (T i : data) {
			cout << i;
		}
	}
};

template <typename T>
class Array {
private:
	vector<T> data;
	int capacity;
public:
	void push(const T& value) { data.push_back(value); }
	void pop() { data.pop_back(); }
	void print() const { cout << "\n";  copy(data.begin(), data.end(), ostream_iterator<T>(cout, " ")); }

	T& operator[](int index) {
		if (index < 0 || index >= capacity)
			throw out_of_range("Index out of bounds");
		return data[index];
	}

	int size() const { return capacity; }
};

template <typename T>
class DynamicArray {
private:
	T* data;
	int capacity;
	int count;
public:
	DynamicArray() : capacity(10), count(0) {
		data = new T[capacity];
	}

	~DynamicArray() {
		delete[] data;
	}

	void add(const T& element) {
		if (count == capacity) {
			resize();
		}
		data[count++] = element;
	}

	void remove(int index) {
		if (index < 0 || index >= count)
			throw out_of_range("Index out of bounds");

		for (int i = index; i < count - 1; ++i) {
			data[i] = data[i + 1];
		}
		count--;
	}

	void resize() {
		capacity *= 2;
		T* newData = new T[capacity];
		for (int i = 0; i < count; ++i) {
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
	}

	int size() const { return count; }
	T& operator[](int index) { return data[index]; }
};

template <typename T>
class Matrix {
private:
	T** data;
	int rows, cols;
public:
	Matrix(int r, int c) : rows(r), cols(c) {
		data = new T * [rows];
		for (int i = 0; i < rows; ++i) {
			data[i] = new T[cols];
		}
	}

	~Matrix() {
		for (int i = 0; i < rows; ++i) {
			delete[] data[i];
		}
		delete[] data;
	}

	Matrix operator+(const Matrix& other) const {
		if (rows != other.rows || cols != other.cols)
			throw invalid_argument("Matrix dimensions must match");

		Matrix result(rows, cols);
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				result.data[i][j] = data[i][j] + other.data[i][j];
			}
		}
		return result;
	}

	Matrix operator-(const Matrix& other) const {
		if (rows != other.rows || cols != other.cols)
			throw invalid_argument("Matrix dimensions must match");

		Matrix result(rows, cols);
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				result.data[i][j] = data[i][j] - other.data[i][j];
			}
		}
		return result;
	}

	T* operator[](int row) { return data[row]; }
	int getRows() const { return rows; }
	int getCols() const { return cols; }
};

template <typename T>
class List {
private:
	struct Node {
		T data;
		Node* next;
		Node* prev;
		Node(const T& d) : data(d), next(nullptr), prev(nullptr) {}
	};

	Node* head;
	Node* tail;
	int count;
public:
	List() : head(nullptr), tail(nullptr), count(0) {}

	~List() {
		while (head) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void pushFront(const T& data) {
		Node* newNode = new Node(data);
		if (!head) {
			head = tail = newNode;
		}
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		count++;
	}

	void pushBack(const T& data) {
		Node* newNode = new Node(data);
		if (!tail) {
			head = tail = newNode;
		}
		else {
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
		count++;
	}

	void popFront() {
		if (!head) throw out_of_range("List is empty");

		Node* temp = head;
		head = head->next;
		if (head) head->prev = nullptr;
		else tail = nullptr;
		delete temp;
		count--;
	}

	void popBack() {
		if (!tail) throw out_of_range("List is empty");

		Node* temp = tail;
		tail = tail->prev;
		if (tail) tail->next = nullptr;
		else head = nullptr;
		delete temp;
		count--;
	}

	int size() const { return count; }
	bool empty() const { return count == 0; }
};

template <typename T>
class Triangle {
private:
	Point<T> p1, p2, p3;
public:
	Triangle(const Point<T>& a, const Point<T>& b, const Point<T>& c)
		: p1(a), p2(b), p3(c) {
	}

	double area() const {
		T x1 = p1.getX(), y1 = p1.getY();
		T x2 = p2.getX(), y2 = p2.getY();
		T x3 = p3.getX(), y3 = p3.getY();

		return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
	}
};

template <typename T>
class Graph {
private:
	map<T, set<T>> adjList;
public:
	void addEdge(const T& src, const T& dest) {
		adjList[src].insert(dest);
		adjList[dest].insert(src); // Для неориентированного графа
	}

	void removeEdge(const T& src, const T& dest) {
		adjList[src].erase(dest);
		adjList[dest].erase(src);
	}

	bool hasEdge(const T& src, const T& dest) const {
		auto it = adjList.find(src);
		if (it != adjList.end()) {
			return it->second.find(dest) != it->second.end();
		}
		return false;
	}
};

template <typename T>
class Cube {
private:
	T edgeLength;
public:
	Cube(T length) : edgeLength(length) {
		if (length <= 0) throw invalid_argument("Edge length must be positive");
	}

	T volume() const {
		return edgeLength * edgeLength * edgeLength;
	}

	T surfaceArea() const {
		return 6 * edgeLength * edgeLength;
	}
};

template <typename T>
class Wrapper {
private:
	T value;
public:
	Wrapper(const T& val = T()) : value(val) {}

	T get() const { return value; }
	void set(const T& val) { value = val; }

	operator T() const { return value; }
	Wrapper& operator=(const T& val) { value = val; return *this; }
};