#include <iostream>
using namespace std;

int sum(int a, int b) {
	if(a <= 0 || sum <= 0) {
		throw "음수 처리 안 됨";
	}
	return a * b;
}

int main() {
	try {
		cout << sum(2,5) << endl;
		cout << sum(-1,4) << endl;
	}
	catch(const char* s) {
		cout << s << endl;
	}
}