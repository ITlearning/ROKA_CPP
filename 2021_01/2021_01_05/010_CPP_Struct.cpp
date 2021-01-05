//C++ 구조체
//C++ 구조체는 클래스와 거의 동일한 포지션을 가지고 있다.
//가장 큰 차이점은, 클래스의 디폴트 접근은 public 이지만 구조체는 private이다.
//이외에 모든 것이 비슷하거나 같다.

#include <iostream>
using namespace std;

struct Rect {
	int width;
	int height;
	public:
	Rect(int w, int h);
	int getArea();
};

Rect::Rect(int w,int h) {
	width = w;
	height = h;
}

int Rect::getArea() {
	return width * height;
}

int main() {
	Rect rect(3, 5);
	
	cout << "사각형의 면적은 " << rect.getArea() << endl;
}