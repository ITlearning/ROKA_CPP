#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Shape {
protected:
	virtual void draw() = 0;
public:
	void paint();
};

void Shape::paint() {
	draw();
}

class Circle : public Shape {
protected:
	virtual void draw();
};

void Circle::draw() {
	cout << "Circle" << endl;
}

class Line : public Shape {
protected:
	virtual void draw(); 
};

void Line::draw() {
	cout << "Line" << endl;
}

class Rect : public Shape {
protected:
	virtual void draw();
};

void Rect::draw() {
	cout << "Rect" << endl;
}

void start() {
	cout << "그래픽 에디터입니다. "<< endl;
}

int menu() {
	int m;
	cout << "삽입 : 1, 삭제 : 2, 모두보기 : 3, 종료 : 4 >> ";
	cin >> m;
	return m;
}

int select() {
	int n;
	cout << "선 : 1, 원 : 2, 사각형 : 3 >> ";
	cin >> n;
	return n;
}

int main() {
	vector<Shape*> v;
	int sh;
	bool sw = true;
	while(sw) {
		int n = menu();
		if(n == 1) {
			int m = select();
			if(m == 1)
				v.push_back(new Line());
			else if (m == 2)
				v.push_back(new Circle());
			else if (m == 3)
				v.push_back(new Rect());
		} else if ( n == 2 ) {
			cout << "삭제하고자 하는 도형의 인덱스 >>";
			int num;
			cin >> num;
			vector<Shape*>::iterator it = v.begin();
			for(int i = 0; i < v.size(); i++) {
				Shape *p = *it;
				if(num == i) {
					it = v.erase(it);
					delete p;
				} else {
					it++;
				}
				
			}
		} else if (n == 3) {
			int i=0;
			vector<Shape*>::iterator it;
        	for(it = v.begin();it!=v.end(); it++, i++){
            	cout << i << ": ";
            	v.at(i)->paint();
       		 }
		} else {
			sw = false;
		}
	}
}