#include <iostream>
using namespace std;

class Rect { //Rect 클래스 선언
	public:
	int width;
	int height;
	int getArea(); //면적을 계산하여 리턴하는 함수
};

int Rect::getArea() { //Rect 클래스 구현
	return width * height;
}

int main() {
	Rect rect;
	rect.width = 3;
	rect.height = 5;
	
	cout << "사각형의 면적은 " << rect.getArea() << endl;
}