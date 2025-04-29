#include <iostream>
#include <vector>

using namespace std;

class Shape
{
public:
	virtual double area() const = 0;
	virtual ~Shape() {};
};

class Circle : public Shape{
	double radius;
public:
	Circle(double r) : radius(r) {}
	double area() const override { return 3.14159 * radius * radius; }
};

class Rectangle : public Shape {
	double width, height;
public:
	Rectangle(double w, double h) : width(w), height(h) {}
	double area() const override { return width * height; }
};

void shapeDemo() {
	int r, a, b;

	cout << "¬ведите радиус круга: " << endl;
	cin >> r;
	cout << "¬ведите стороны пр€моугольника: " << endl;
	cin >> a;
	cin >> b;

	vector<Shape*> shapes = {
		new Circle(r),
		new Rectangle(a, b)
	};

	for (auto shape : shapes) {
		cout << "ѕлощадь: " << shape->area() << endl;
	}
}