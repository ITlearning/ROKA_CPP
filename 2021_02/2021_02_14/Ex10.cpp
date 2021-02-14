#include <iostream>
#include <string>
using namespace std;

class Shape {
	Shape* next;
protected:
	virtual void draw() = 0;
public:
	Shape() { next = NULL; }
	virtual ~Shape() { }
	void paint() { draw(); }
	Shape* add(Shape* p) { this->next = p; return p; }
	Shape* getNext() { return next; }
	void setNext(Shape *p) { this->next = p->next; }
};
class Circle : public Shape {
protected:
	virtual void draw() {
		cout << "Circle" << endl;
	}
};
class Rect : public Shape {
protected:
	virtual void draw() {
		cout << "Rectangle" << endl;
	}
};
class Line : public Shape {
protected:
	virtual void draw() {
		cout << "Line" << endl;
	}
};

class UI {
public:
	static int main_memu() {
		int n;
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
		cin >> n;
		return n;
	}
	static int one_menu() {
		int n;
		cout << "선:1, 원:2, 사각형:3 >> ";
		cin >> n;
		return n;
	}
	static int two_menu() {
		int n;
		cout << "삭제하고자 하는 도형의 인덱스 >> ";
		cin >> n;
		return n;
	}
};

class GraphicEditor {
	Shape *pStart;
	Shape *pLast;
	int count;
public:
	GraphicEditor() { pStart = NULL; count = 0; }
	void create(int num) {
		switch (num) {
		case 1:
			if (count == 0) {
				pStart = new Line();
				pLast = pStart;
			}
			else
				pLast = pLast->add(new Line());
			count++;
			break;

		case 2:
			if (count == 0) {
				pStart = new Circle();
				pLast = pStart;
			}
			else
				pLast = pLast->add(new Circle());
			count++;
			break;

		case 3:
			if (count == 0) {
				pStart = new Rect();
				pLast = pStart;
			}
			else
				pLast = pLast->add(new Rect());
			count++;
			break;

		}
	}
	void indelete(int num) {
		Shape *p = pStart;
		Shape *del = pStart;

		if (num < count) {
			for (int i = 0; i<num; i++) {
				p = del;
				del = del->getNext();
			}
			if (num == 0)
				pStart = p->getNext();
			else
				p->setNext(del);
			count--;
			if (count == 1) pLast = pStart;
			delete del;

		}
		else
			cout << "인덱스를 잘못 입력하셨습니다." << endl;
	}
	void call() {
		bool exit = true;
		cout << "그래픽 에디터입니다." << endl;
		while (exit) {
			switch (UI::main_memu()) {
			case 1:
				create(UI::one_menu());
				break;
			case 2:
				indelete(UI::two_menu());
				break;
			case 3: {
				Shape* p = pStart;
				for (int i = 0; i< count; i++) {
					cout << i << ": "; p->paint();
					p = p->getNext();
				}
				break;
			}
			case 4:
				exit = false;
				break;

			}
		}
	}
};

int main() {
	GraphicEditor* editor = new GraphicEditor;
	editor->call();
	delete editor;
}