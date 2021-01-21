//'값의 의한 호출' 시 매개 변수의 생성자 실행되지 않음

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
	cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "생성자 실행 radius = " << radius << endl;
}

Circle::~Circle() {
	cout << "소멸자 실행 radius = " << radius << endl;
}

//매개 변수 생성자 실행되지 않음
void increase(Circle c) { //waffle의 내용이 그대로 c에 복사
	int r = c.getRadius();
	c.setRadius(r+1);
}

//생성자는 실행되지 않았지만, 소멸자는 실행됨.
//그 이유는 만일 생성자가 실행됐을 경우 Circle() 생성자가 실행이 된다.
//그럴경우 30으로 전달받은 값이 1로 초기화 될 가능성이 농후하다.
//그래서 컴파일러가 알아서 이런 문제를 일으키지 않기위해 생성자를 실행하지 않는것이다.
//그러나 소멸자는 이와는 상관없이 바뀐 값으로 소멸자를 실행시켜도 문제 없기에 실행되는 것 이다.


int main() {
	Circle waffle(30);
	increase(waffle);
	cout << waffle.getRadius() << endl;
}