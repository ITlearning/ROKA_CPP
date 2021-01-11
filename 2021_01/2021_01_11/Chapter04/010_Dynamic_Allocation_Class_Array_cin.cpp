//Circle 배열의 동적 생성 및 반환 활용
//원의 개수를 입력받고 Circle 배열을 동적 생성하라.

#include <iostream>
using namespace std;

class Circle {
	int radius;
	public:
	Circle() { radius = 1; cout << "생성자 실행 radius = " << radius << endl; }
	Circle(int r) { radius = r; cout << "생성자 실행 radius = " << radius << endl; }
	~Circle() { cout << "소멸자 실행 radius = " << radius << endl; }
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; }
};

int main() {
	int n, radius;
	cout << "생성하고자 하는 원의 개수 >> ";
	cin >> n;
	if(n < 0) return 0;
	Circle *pArray = new Circle [n];
	for(int i = 0; i < n; i++) {
		cout << i + 1 << "번째 원 :";
		cin >> radius;
		pArray[i].setRadius(radius);
	}
	
	int count = 0;
	Circle* p = pArray;
	for(int i = 0; i < n; i++) {
		cout << p->getArea() << ' ';
		if(p->getArea() >= 100 && p->getArea() <= 200) {
			count++;
		}
		p++;
	}
	
	cout << endl;
	
	delete [] pArray;
}