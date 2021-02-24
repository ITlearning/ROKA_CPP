// Point 객체를 스트림에서 입력받는 >> 연산자 작성
#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}
	friend istream& operator >> (istream& ins, Point &a);
	friend ostream& operator << (ostream& stream, Point a);
};

istream& operator >> (istream& ins, Point &a) {
	cout << "x좌표 :";
	ins >> a.x;
	cout << "y좌표 :";
	ins >> a.y;
	return ins;
}

ostream& operator << (ostream& stream, Point a) {
	stream << "(" << a.x << "," << a.y << ")";
	return stream;
}

int main() {
	Point p;
	cin >> p;
	cout << p;
}