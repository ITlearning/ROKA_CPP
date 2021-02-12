// 범위 지정 연산자를 이용한 기본 클래스의 가상 함수 호출
#include <iostream>
using namespace std;

class Shape {
public:
	virtual void draw() {
		cout << "--Shape--";
	}
};

class Circle : public Shape {
public:
	int x;
	void draw() {
		Shape::draw(); //기본 클래스의 draw() 호출
		cout << "Circle" << endl;
	}
};

int main() {
	Circle circle;
	Shape * ps = &circle;
	ps->draw(); // 동적 바인딩 발생. draw()가 virtual 이므로
	ps->Shape::draw(); // 정적 바인딩 발생. 범위 지정 연산자로 인해
}