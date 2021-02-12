// 파생 클래스에서 함수를 재정의하는 사례
#include <iostream>
using namespace std;

class Base {
public:
	void f() { cout << "Base::f() called" << endl; }
};

class Dervied : public Base {
public:
	void f() { cout << "Dervied::f() called" << endl; } //Base의 멤버 함수 f()를 재정의
};

int main() {
	Dervied d, *pDer;
	pDer = &d; // 객체 d를 가리킨다
	pDer->f(); // Dervied의 멤버 f() 호출
	
	Base* pBase;
	pBase = pDer; // 업캐스팅. 객체 d를 가리킨다.
	pBase->f(); // Base의 멤버 f() 호출
}