//Circle 객체의 동적 생성 및 반환 응용
//정수 값으로 반지름을 입력받고 Circle 객체를 동적 생성하여 면적을 출력.
//음수를 입력하면 프로그램은 종료된다.

#include <iostream>
using namespace std;

class Circle {
	int radius;
	public:
	Circle() { radius = 1; cout << "생성자 실행 radius = " << radius << endl; }
	Circle(int r) { radius = r; cout << "생성자 실행 radius = " << radius << endl; }
	~Circle() { cout << "소멸자 실행 radius = " << radius << endl; }
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; }
};

int main() {
	int radius;
	while(true) {
		cout << "정수 반지름 입력(음수이면 종료) >> ";
		cin >> radius;
		if(radius < 0) break;
		Circle *p = new Circle(radius);
		cout << "원의 면적은 " << p->getArea() << endl;
		cout << endl;
		delete p;
	}
}