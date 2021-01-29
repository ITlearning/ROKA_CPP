// 참조 매개 변수로 인한 함수 중복의 모호성
// 참조 매개 변수로 인한 모호성

#include <iostream>
using namespace std;

int add(int a, int b) {
	return a + b;
}

int add(int a, int& b) {
	b = a + b;
	return b;
}

int main() {
	int s = 10; 
	int t = 20;
	//cout << add(s,t); // 컴파일 오류. 참조 매개 변수로 인해 함수 호출이 모호함
}