#include <iostream>
using namespace std;

void grade(int num) {
	if(num >= 0 && num <= 100) {
		if(num >= 90 && num <= 100) {
			cout << "A" << endl;
		} else if (num >= 80 && num < 90) {
			cout << "B" << endl;
		} else if (num >= 70 && num < 80) {
			cout << "C" << endl;
		} else if (num >= 60 && num < 70) {
			cout << "D" << endl;
		} else {
			cout << "F" << endl;
		}
	} else if( num == 120){
		throw "0과 100 사이의 정수가 아닙니다.";
	} else {
		throw "120이 아닙니다";
	}
}

int main() {
	int a;
	try {
		cin >> a;
		grade(a);
	}
	catch(const char* s) {
		cout << s << endl;
	}
	

}