#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

Circle getCircle() {
	Circle tmp(30);
	return tmp; //객체 tmp를 리턴한다.
} //tmp 객체의 복사본 리턴

int main() {
	Circle c; //객체가 생성된다. radius = 1로 초기화 한다.
	cout << c.getArea() << endl;
	
	c = getCircle(); //tmp객체가 c에 복사, c의 radius는 30이 된다.
	cout << c.getArea() << endl;
}