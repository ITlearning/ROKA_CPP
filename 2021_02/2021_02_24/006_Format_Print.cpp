// width(), fill(), precision() 을 사용한 포멧 출력

#include <iostream>
using namespace std;

void showWidth() {
	cout.width(10);
	cout << "Hello" << endl;
	cout.width(5);
	cout << 12 << endl;
	
	cout << '%';
	cout.width(10);
	cout << "Korea/" << "Seoul/" << "City" << endl;
}

int main() {
	showWidth(); // width() 사용 사례
	cout << endl;
	
	cout.fill('^'); // fill()을 적용한 후의 사례
	showWidth();
	cout << endl;
	
	cout.precision(5); // precision() 의 사용 예
	cout << 11./3. << endl;
}