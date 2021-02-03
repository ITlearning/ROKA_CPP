// ++연산자 함수를 프렌드로 작성
#include <iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
	
	void show();
	friend Power& operator++(Power& op);	   // 전위 연산자
	friend Power operator++(Power& op, int x); // 후위 연산자
	
};

void Power::show() {
	cout << "Kick = " << kick << " Punch = " << punch << endl;
}

Power& operator++(Power& op) {
	op.kick++;
	op.punch++;
	return op;
}

Power operator++(Power& op, int x) {
	Power tmp = op;
	op.kick++;
	op.punch++;
	return tmp;
}

int main() {
	Power a(3,5), b;
	b = ++a;
	a.show();
	b.show();
	
	b = a++;
	a.show();
	b.show();
}