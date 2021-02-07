// Protected 멤버에 대한 접근
#include <iostream>
#include <string>
using namespace std;

class Point {
protected:
	int x, y;
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class ColorPoint : public Point {
	string color;
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint() { cout << color << ":"; showPoint(); } 
	bool equals(ColorPoint p);
};

bool ColorPoint::equals(ColorPoint p) {
	if(x == p.x && y == p.y && color == p.color)
		return true;
	else
		return false;
}

int main() {
	Point p;
	p.set(2,3);
	p.showPoint();
	ColorPoint cp;
	cp.set(3,4);
	cp.setColor("Red");
	
	ColorPoint cp2;
	cp2.set(3,4);
	cp2.setColor("Red");
	cout << ((cp.equals(cp2))?"true":"false");
}