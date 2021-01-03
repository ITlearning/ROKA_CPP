//멤버 변수 초기화와 위임 생성자 활용
#include <iostream>
using namespace std;

class Point {
	int x, y;
	public:
	Point(); //위임 생성자
	Point(int a, int b); //타겟 생성자
	void show() { cout << "(" << x << ", " << y << ")" << endl; }
};

Point::Point() : Point(0,0) { } //Point(int a, int b) 생성자 호출. 호출 a,b에 모두 0 전달

Point::Point(int a, int b) : x(a), y(b) { }

int main() {
	Point origin;
	Point target(10, 20);
	
	origin.show();
	target.show();
}