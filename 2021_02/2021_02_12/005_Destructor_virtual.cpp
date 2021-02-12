// 소멸자를 가상 함수로 선언
#include <iostream>
using namespace std;

class Base {
public:
	virtual ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base {
public:
	virtual ~Derived() { cout << "~Derived()" << endl; }
};

int main() {
	Derived *dp = new Derived();
	Base *bp = new Derived();
	
	delete dp; //Derived 의 포인터로 소멸
	delete bp; //Base 의 포인터로 소멸
}