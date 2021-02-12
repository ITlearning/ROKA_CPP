// 오버라이딩과 가상 함수 호출
#include <iostream>
using namespace std;

class Base {
public:
	virtual void f() { cout << "Base::f() called" << endl; } // 가상 함수 선언
};

class Dervied : public Base {
public:
	virtual void f() { cout << "Dervied::f() called" << endl; } //Base의 가상 함수 f()를 재정의
};

int main() {
	Dervied d, *pDer;
	pDer = &d;
	pDer->f(); // Dervied::f() 호출
	
	Base* pBase;
	pBase = pDer; //업 캐스팅
	pBase->f(); // Dervied::f() 호출. 동적 바인딩 발생
	// pBase가 Base 타입의 포인터이므로 다음 코드는 Base::f() 를 호출할 것으로 예상되지만,
	// pBase가 가리키는 객체는 오버라이딩한 Dervied::f() 이므로 동적 바인딩을 통해 Dervied의 f() 가 호출된다.
}