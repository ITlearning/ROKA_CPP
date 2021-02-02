// 두 개의 Power 객체를 더하는 + 연산자 작성

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
	Power operator+ (Power& op2); // +연산자 함수 선언
};

void Power::show() {
	cout << "kick = " << kick << ',' << "punch = " << punch << endl;
}

Power Power::operator+(Power& op2) { //+ 연산자 멤버 함수 구현
	Power tmp;
	tmp.kick = this->kick + op2.kick; // this는 a op2는 b
	tmp.punch = this->punch + op2.punch;
	return tmp;	
}

int main() {
	Power a(3,5), b(4,6), c;
	c = a + b;  //객체 a의 operator+() 멤버 함수 호출
	a.show();
	b.show();
	c.show();
}