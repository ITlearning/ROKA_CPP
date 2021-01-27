#include <iostream>
using namespace std;

class Accumulator {
	int value;
public:
	Accumulator(int value) { this->value = value; }
	Accumulator& add(int n) { 
		 value += n;
		return *this; // this는 자신을 가리키고 있는 포인터의 개념이지만 , *this 는 자신이 가리키고 있는 클래스 그 자체(변수, 함수 등등)
	}
	int get() { return value; }
};

int main() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7);
	cout << acc.get() << endl;
}

