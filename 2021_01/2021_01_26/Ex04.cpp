#include <iostream>
using namespace std;

bool bigger(int a, int b, int& big) {
	if(a < b) {
		big = b;
		return false;
	}else if(a > b) {
		big = a;
		return false;
	} else {
		return true;
	}
}

int main() {
	int a, b;
	int big;
	cout << "a의 값을 입력하세요 = ";
	cin >> a;
	cout << "b의 값을 입력하세요 = ";
	cin >> b;
	
	bool par = bigger(a, b, big);
	
	if(par == 0) {
		cout << big << "이(가) 더 큽니다" << endl;
	}else {
		cout << "같거나 숫자가 아닙니다." << endl;
	}
}