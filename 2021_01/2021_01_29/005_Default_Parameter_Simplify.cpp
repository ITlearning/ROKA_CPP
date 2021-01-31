// 디폴트 매개 변수를 이용하여 중복 함수 간소화 연습
#include <iostream>
using namespace std;

void fillLine(int n = 25, char c = '*') {
	for(int i=0; i < n; i++) {
		cout << c;
	}
	
	cout << endl;
}

int main() {
	fillLine();
	fillLine(10, '%');
}