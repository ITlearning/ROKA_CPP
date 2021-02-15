// 제네릭 스탟의 제네릭 타입을 포인터나 클래스로 구체화 하는 예
#include <iostream>
using namespace std;

template <class T>
class MyStack {
	int tos;
	T data [100];
public:
	MyStack();
	void push(T element); // T 타입 원소 element 를 data[] 배열에 삽입
	T pop(); // 스택에 탑에 있는 데이터를 data[] 배열에서 리턴
};

template <class T>
MyStack<T>::MyStack() { // 생성자
	tos = -1; 
}

template <class T>
void MyStack<T>::push(T element) {
	if(tos == 99) {
		cout << "Stack Full." << endl;
		return;
	}
	tos++;
	data[tos] = element;
}

template <class T>
T MyStack<T>::pop() {
	T retData;
	if(tos == -1){
		cout << "Stack Empty. " << endl;
		return 0;
	}
	retData = data[tos--];
	return retData;
}


class Point {
	int x,y;
public:
	Point(int x = 0, int y = 0) { this->x = x; this->y = y; }
	void show() { cout << '(' << x << ',' << y << ')' << endl; }
};

int main() {
	MyStack<int *> ipStack; // int* 만 저장하는 스택
	int *p = new int [3];
	for(int i = 0; i < 3; i++) {
		p[i] = i*10;
	}
	ipStack.push(p); // 포인터 푸시
	int *q = ipStack.pop();
	for(int i = 0; i < 3; i++) cout << q[i] << ' ';
	cout << endl;
	delete [] p;
	
	MyStack<Point> pointStack;
	Point a(2,3), b;
	pointStack.push(a); // Point 객체 푸시, 복사되어 저장
	b = pointStack.pop();
	b.show();
	
	MyStack<Point*> pStack;
	pStack.push(new Point(20,30));
	Point* pPoint = pStack.pop();
	pPoint->show();
	
	MyStack<string> sStack;
	string s = "C++";
	sStack.push(s);
	sStack.push("JAVA");
	cout << sStack.pop() << endl;
	cout << sStack.pop() << endl;
}