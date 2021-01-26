#include <iostream>
#include <string>
using namespace std;

class Circle {
private:
	int radius;
	string name;
public:
	Circle() { radius = 1; }
	Circle(string name, int radius) { this->name = name; this->radius = radius; }
	Circle(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
	void show() { cout << name << ' ' << radius << endl; }
	void swap(Circle& a, Circle& b);
};

void Circle::swap(Circle& a, Circle& b) {
	Circle tmp;
	tmp = b;
	b = a;
	a = tmp;
}

int main() {
	Circle a("a", 1);
	Circle b("b", 2);
	
	a.swap(a, b);
	
	a.show();
	b.show();
}