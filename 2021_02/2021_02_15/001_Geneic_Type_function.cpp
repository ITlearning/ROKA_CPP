// 제네릭 myswap() 함수 만들기
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
};

template <class T>  // 템플릿의 역할은 그저 함수의 틀이다. 제네릭 함수를 선언하고, 컴파일 시점에 구체화 시키기 위한 틀을 만드는 것이다.
void myswap(T & a, T & b) { // 제네릭 함수
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int a = 4, b = 5;
	myswap(a,b);
	cout << "a= " << a << ", " << "b= " << b << endl;
	
	
	double c = 0.3, d = 4.223;
	myswap(c,d);
	cout << "c = " << c << ", " << "d = " << d << endl;
	
	Circle donut(5), pizza(30);
	myswap(donut, pizza);
	cout << "donut의 반지름 = " << donut.getRadius() << endl;
	cout << "pizza의 반지름 = " << pizza.getRadius() << endl;
}