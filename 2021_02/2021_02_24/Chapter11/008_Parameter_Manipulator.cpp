//매개 변수를 가진 조작자 사용
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout << showbase;
	
	// 타이틀을 출력한다.
	cout << setw(8) << "Number";
	
	cout << setw(10) << "Octal";
	cout << setw(10) << "Hexa" << endl;
	
	for(int i = 0; i < 50; i+=5) {
		cout << setw(8) << setfill('.') << dec << i; // 10진수
		cout << setw(10) << setfill(' ') << oct << i; // 8진수
		cout << setw(10) << setfill(' ') << hex << i << endl; //16진수
	}
}