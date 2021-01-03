#include <iostream>
using namespace std;

//다음 코드에서 donut 객체와 pizza 객체의 생성자가 각각 실행된다.
class Circle {
	public:
	int radius;
	Circle();	//기본 생성자
	Circle(int r);	// 매개 변수 있는 생성자. 둘 다 특징은 리턴 타입을 선언하지 않는다.
	double getArea();
};

Circle::Circle() {
	radius = 1; // 반지름 값 초기화
	cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::Circle(int r) {
	radius = r; //반지름 값 초기화. 이 경우에는 매개 변수가 있는 생성자이기에 불러온 매개변수로 지정을 한다.
	cout << "반지름 " << radius << " 원 생성" << endl;
}

double Circle::getArea() {
	return radius * radius * 3.14;
}

int main() {
	Circle donut; //매개 변수 없는 생성자 호출
	double area = donut.getArea();
	cout << "donut 면적은 " << area << endl;
	
	Circle pizza(30);
	area = pizza.getArea();
	cout << "pizza 면적은 " << area << endl;
}