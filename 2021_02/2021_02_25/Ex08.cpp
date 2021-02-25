#include <iostream>
#include <string>
using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius = 1, string name = "") {
		this->radius = radius;
		this->name = name;
	}
	
	friend istream& operator >> (istream& ins, Circle &c);
	friend ostream& operator << (ostream& stream, Circle c);
};

istream& operator >> (istream& ins, Circle &c) {
	cout << "반지름 : ";
	ins >> c.radius;
	cout << "이름 : ";
	ins >> c.name;
	
	return ins;
}

ostream& operator << (ostream& stream, Circle c) {
	cout << "(반지름 " << c.radius << "인 " << c.name << ")";
	return stream;
}

int main() {
	Circle d,w;
	cin >> d >> w;
	cout << d << w << endl;
}