//지역 객체와 전역 객체의 생성 및 소멸 순서
#include <iostream>
using namespace std;

class Circle {
public:
	int radius;
	Circle();
	Circle(int r);
	~Circle(); //소멸자 선언
	double getArea();
};

Circle::Circle() { // 기본 생성자 구현
	radius = 1;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::~Circle() { // 소멸자 구현
	cout << "반지름 " << radius << " 원 소멸" << endl; 
}

double Circle::getArea() {
	return 3.14*radius*radius;
}

Circle globalDonut(1000); //전역 객체 생성
Circle globalPizza(2000); //전역 객체 생성

void f() {
	Circle fDonut(100);   //지역 객체 생성
	Circle fPizza(200);	  //지역 객체 생성
}

int main() {
	Circle mainDount;
	Circle mainPizza(30);
	f();
	
	// 전역객체 지역객체 순으로 생성되고 역순으로 소멸된다.
}