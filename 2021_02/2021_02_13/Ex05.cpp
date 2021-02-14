#include <iostream>
using namespace std;

class AbstractGate {
protected:
	bool x,y;
public:
	AbstractGate() {}
	void set(bool x, bool y) { this->x = x; this->y = y; }
	virtual bool operation() = 0;
};

class ANDGate : public AbstractGate {
public:
	bool operation() {
		if(x == true && y == true) {
			return true;
		} else {
			return false;
		}
	}
};

class ORGate : public AbstractGate {
public:
	bool operation() {
		if(x == false && y == false)
			return false;
		else return true;
	}
};

class XORGate : public AbstractGate {
public:
	bool operation() {
		if((x == false && y == false) || (x == true && y == true))
			return false;
		else return true;
	}
};

int main() {
	ANDGate a; // and , or , xor 로 이름을 설정해놓고 컴파일을 돌리면 에러가 남. 왜 그런지는 모르겠음 아무튼 그럼.
	ORGate o;
	XORGate x;
	
	a.set(true, false);
	o.set(true, false);
	x.set(true, false);
	cout.setf(ios::boolalpha); // 불린 값을 "true", "false"문자열로 출력할 것을 지시.
	cout << a.operation() << endl;
	cout << o.operation() << endl;
	cout << x.operation() << endl;
}