// a+b를 위한 +연산자 함수를 프렌드로 작성
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
	friend Power operator+(Power op1, Power op2); // 프렌드 선언
};

void Power::show() {
	cout << "Kick = " << kick << " Punch = " << punch << endl;
}

Power operator+(Power op1, Power op2) {
	Power tmp;
	tmp.kick = op1.kick + op2.kick;
	tmp.punch = op1.punch + op2.punch;
	
	return tmp;
}

int main() {
	Power a(3,5),b(4,6),c;
	a.show();
	b.show();
	c = a + b;
	c.show();
}