// 예외 상황에 대한 대처가 없는 프로그램 사례
#include <iostream>
using namespace std;

int getExp(int base, int exp) { // base의 exp 지수승을 계산하여 리턴
	int value = 1;
	for(int n = 0; n < exp; n++) {
		value = value * base; // base 를 exp번 곱하여 지수 값 계산
	}
	return value;
}

int main() {
	int v = getExp(2,3);
	cout << "2의 3승은 " << v << "입니다." << endl;
	int e = getExp(2,-3);
	cout << "2의 -3승은 " << e << "입니다." << endl;  // 예외 처리를 해주지 않아 2의 -3승은 1이라고 나와있다. 
	// 답은 1이 아니라 1/8이다.
}