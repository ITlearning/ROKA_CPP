#include <iostream>
using namespace std;

class AbstractGate {
protected:
	bool x,y;
public:
	void set(bool x, bool y) { this->x = x; this->y = y; }
	virtual bool operation() = 0;
};

class ANDGate : public AbstractGate {
public:
	ANDGate() {}
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
	ORGate() {}
	bool operation() {
		if(x == false && y == false)
			return false;
		else return true;
	}
};

class XORGate : public AbstractGate {
public:
	XORGate() {}
	bool operation() {
		if((x == false && y == false) || (x == true && y == true))
			return false;
		else return true;
	}
};

int main() {
	ANDGate and;
	ORGate or;
	XORGate xor;
	
	and.set(true, false);
	or.set(true, false);
	xor.set(true, false);
	cout.setf(ios::boolalpha); // 불린 값을 "true", "false"문자열로 출력할 것을 지시.
	cout << and.operation() << endl;
	cout << or.operation() << endl;
	cout << xor.operation() << endl;
}