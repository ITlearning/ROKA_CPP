// 반지름이 r인 원의 면적을 리턴하는 람다식 만들기
#include <iostream>
using namespace std;

int main() {
	double pi = 3.14;
	
	auto calc = [pi](int r) { return pi*r*r; };
	
	cout << "합은 " << calc(3) << endl;
}