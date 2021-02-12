// 상속이 반복되는 경우 가상 함수 호출
#include <iostream>
using namespace std;

class Base {
public: virtual void f() { cout << "Base::f() called" << endl; }
};

class Dervied : public Base {
public: void f() { cout << "Dervied::f() called" << endl; }
};

class GrandDerived : public Dervied {
public: void f() { cout << "GrandDerived::f() called" << endl; }
};

int main() {
	GrandDerived g;
	Base *bp;
	Dervied *dp;
	GrandDerived *gp;
	bp = dp = gp = &g; // 모든 포인터가 객체 g를 가리킴
	
	bp->f();
	dp->f();
	gp->f();
	// 동적 바인딩에 의해 모두 GrandDerived 의 함수 f() 호출
}