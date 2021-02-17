// 매개변수 x,y 의 합을 출력하는 람다식 만들기
#include <iostream>
using namespace std;

int main() {
	[](int x, int y) { cout << "합은 " << x + y; }(2,3); // 람다식 실행. 5출력
}