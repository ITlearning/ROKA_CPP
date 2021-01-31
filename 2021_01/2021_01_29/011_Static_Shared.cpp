// static 멤버를 공유의 목적으로 사용하는 예

#include <iostream>
using namespace std;

class Circle {
private:
	static int numOfCircles; // 생성된 원의 개수 기억
	int radius;
public:
	Circle(int r = 1);
	~Circle() { numOfCircles--; }
	double getArea() { return 3.14 * radius * radius; }
	static int getNumOfCircles() { return numOfCircles; }
};

Circle::Circle(int r) {
	radius = r;
	numOfCircles++;
}

int Circle::numOfCircles = 0; // 0으로 초기화
// static 변수는 무조건, 무조건 외부에 전역 변수로 초기화 되어야 한다.

int main() {
	Circle *p = new Circle[10];
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;
	
	delete [] p; // 10개의 소멸자 실행
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;
	
	Circle a; // 생성자 실행
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;
	
	Circle b; // 생성자 실행
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;
}