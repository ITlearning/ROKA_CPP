//기본 생성자
//클래스에 어떤 생성자도 없을 때 컴파일러가 자동으로 생성해주는 생성자

#include <iostream>
using namespace std;

class Rectangle {
	public:
	int width, height;
	Rectangle();
	Rectangle(int w, int h); //이렇게 다른 생성자가 선언 되었을 경우, 기본 생성자를 생성하지 않는다. 따라서 기본 생성자 또한 같이 선언 해 주어야 한다.
	Rectangle(int length);
	bool isSquare();
};

Rectangle::Rectangle() {
	width = height = 1;
}

Rectangle::Rectangle(int w, int h) {
	width = w; height = h;
}

Rectangle::Rectangle(int length) {
	width = height = length;
}

bool Rectangle::isSquare() {
	if(width == height) return true;
	else return false;
}

int main() {
	Rectangle rect1;
	Rectangle rect2(3, 5);
	Rectangle rect3(3);
	
	if(rect1.isSquare()) cout << "rect1은 정사각형이다. " << endl;
	if(rect2.isSquare()) cout << "rect2는 정사각형이다. " << endl;
	if(rect3.isSquare()) cout << "rect3는 정사각형이다. " << endl;
}