#include <iostream>
#include <string>
using namespace std;

class Cirlce {
	int radius;
public:
	Cirlce(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << radius << " 인 원" << endl; }
	
	friend Cirlce operator + (int num,Cirlce op);
};

Cirlce operator + (int num, Cirlce op) {
	op.radius += num;
	return op;
}


int main() {
	Cirlce a(5), b(4);
	b = 1 + a;
	a.show();
	b.show();
}