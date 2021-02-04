#include <iostream>
#include <string>
using namespace std;

class Cirlce {
	int radius;
public:
	Cirlce(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << radius << " 인 원" << endl; }
	
	friend Cirlce& operator ++ (Cirlce& op);
	friend Cirlce operator ++ (Cirlce& op, int x);
};

Cirlce& operator ++ (Cirlce& op) {
	op.radius++;
	return op;
}

Cirlce operator ++ (Cirlce& op, int x){
	Cirlce tmp = op;
	op.radius++;
	return tmp;
}

int main() {
	Cirlce a(5), b(4);
	++a;
	b = a++;
	a.show();
	b.show();
}