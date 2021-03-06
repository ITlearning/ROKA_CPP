#include <iostream>
using namespace std;

void gugudan(int num, int &a) {
	int total = 0;
	if(num < 0 || num > 10) {
		a = 0;
		throw "잘못된 입력입니다. 1~9 사이의 정수만 입력하세요";
	} else if (cin.fail()) {
		a = 1;
		throw "입력 오류가 발생하어 더 이상 입력되지 않습니다. 프로그램을 종료합니다.";
		
	}
	
	for(int i = 1; i <= 9; i++) {
		cout << num << "x" << i << '=' << num*i << ' ';
	}
}

int main() {
	int n;
	int a = 0;
	while(true) {
		try {
			cout << "양수 입력 : ";
			cin >> n;
			gugudan(n, a);
			cout << endl;
		}
		catch(const char* s) {
			cout << s << endl;
			if (a == 1)
				break;
		}
		
	}
	
}