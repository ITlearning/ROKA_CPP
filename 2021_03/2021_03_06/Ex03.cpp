#include <iostream>
using namespace std;

int get(){
	int a;
	cout << "0~9 사이의 수를 입력 >> ";
	cin >> a;
	if(a < 0) {
		throw "input fault 예외 발생, 계산할 수 없음";
	}
	
	return a;
}

int main() {
	int a = 0;
	int b = 0;
	while(true) {
		try {
			a = get();
			b = get();
			cout << a << "X" << b << " = " << a * b << endl;
		}
		catch(const char *s) {
			cout << s << endl;
		} 
	}
}