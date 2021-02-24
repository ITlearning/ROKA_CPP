// Point객체를 스트림에 출력하는 << 연산자 작성
#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}
	friend ostream& operator << (ostream& stream, Point a);
};

ostream& operator << (ostream& stream, Point a) {
	stream << "(" << a.x << "," << a.y << ")";
	return stream;
}

int main() {
	Point p(3,4);
	cout << p << endl;
	
	Point q(1,100), r(2,200);
	cout << q << r << endl;
}