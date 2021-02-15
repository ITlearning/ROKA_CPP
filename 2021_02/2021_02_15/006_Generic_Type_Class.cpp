// 제네릭 스택 클래스 만들기
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

int main() {
	MyStack<int> iStack;
	iStack.push(3);
	cout << iStack.pop() << endl;
	
	MyStack<double> dStack;
	dStack.push(4.5);
	cout << dStack.pop() << endl;
	
	MyStack<char> *p = new MyStack<char>();
	p->push('d');
	cout << p->pop() << endl;
	
	delete p;
}