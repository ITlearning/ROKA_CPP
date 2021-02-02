// 두 개의 Power 객체를 더하는 += 연산자 작성

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
	Power& operator+= (Power op2); // +=연산자 함수 선언 
	// 위 Power&는 참조를 리턴하지 않을 경우 자칫하면 복사된 객체에 더하기를 실행 할 수 있기 때문이다.
};

void Power::show() {
	cout << "kick = " << kick << ',' << "punch = " << punch << endl;
}

Power& Power::operator+= (Power op2) {
	kick = kick + op2.kick; 	//a의 kick에 b의 kick을 더함
	punch = punch + op2.punch;	//b의 punch에 b의 punch를 더함
	return *this; // 리턴 타입이 Power& 이므로 객체 자신의 참조가 리턴된다.
}

int main() {
	Power a(3,5), b(4,6), c;
	a.show();
	b.show();
	c = a += b; // 파워 객체 더하기
	a.show();
	c.show();
}