#include <iostream>
using namespace std;

class Circle {
	int radius;
	public:
	void setRadius(int radius);
	double getArea();
};

void Circle::setRadius(int radius) {
	this->radius = radius;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle c;
	int size;
	int cnt = 0;
	int num;
	
	cout << "원의 개수 >>";
	cin >> num;
	
	Circle *p = new Circle [num];
	
	for(int i = 0; i < num; i++) {
		cout << "원 " << i+1 << "의 반지름 >> ";
		cin >> size;
		p[i].setRadius(size);
	}
	
	for(int i = 0; i < num; i++) {
		if(p[i].getArea() > 100) {
			cnt++;	
		}
	}
	
	cout << "면적이 100보다 큰 원은 " << cnt << "개 입니다." << endl;
}