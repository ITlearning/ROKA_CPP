//참조 매개 변수를 가진 함수 만들기 연습

#include <iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	double getArea() { return 3.14 * radius * radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
};

Circle::Circle() {
	radius = 1;
}

Circle::Circle(int r) {
	radius = r;
}

Circle::~Circle() {
}
//문제 시작
void ReadRadius(Circle &c) {
	int r;
	cout << "정수 값으로 반지름을 입력하세요 >> ";
	cin >> r;
	c.setRadius(r);
} 
//문제 끝
int main() {
	Circle donut;
	ReadRadius(donut);
	cout << "donut의 면적 = " << donut.getArea() << endl;
}