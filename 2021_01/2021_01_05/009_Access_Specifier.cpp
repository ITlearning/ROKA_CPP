//접근 지정자
//멤버 변수는 private로 지정하는 것이 바람직함

#include <iostream>
using namespace std;

class PrivateAccessError {
	private:
	int a;
	void f();
	PrivateAccessError();
	public:
	int b;
	PrivateAccessError(int x);
	void g();
};

PrivateAccessError::PrivateAccessError() {
	a = 1;
	b = 2;
}

PrivateAccessError::PrivateAccessError(int x) {
	a = x;
	b = x;
}

void PrivateAccessError::f() {
	a = 5;
	b = 5;
}

void PrivateAccessError::g() {
	a = 6;
	b = 6;
}

int main() {
	//PrivateAccessError objA; //생성자 PrivateAccessError() 는 private이므로 main()에서 호출할 수 없다.
	PrivateAccessError objB(100); 
	//objB.a = 10; //a는 private 이므로 main() 에서 호출할 수 없다.
	objB.b = 20;
	//objB.f(); //f() 는 private의 멤버이므로 main() 에서 호출할 수 없다.
	objB.g();
}