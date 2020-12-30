#include <iostream>
using namespace std;


int main() {
	int num;
	int num2;
	cout << "두 수를 입력하라>> ";
	cin >> num >> num2;
	
	if(num > num2) {
		cout << "큰 수 = ";
		cout << num;
	}else if (num < num2) {
		cout << "큰 수 = ";
		cout << num2;
	}else {
		cout << "두 수가 같습니다.";
	}
	cout << endl;
}