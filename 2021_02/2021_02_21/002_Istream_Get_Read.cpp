// get()과 get(char&)을 이용한 한 줄의 문자 읽기
#include <iostream>
using namespace std;

void get1() {
	cout << "cin.get()로 <Enter> 키까지 입력 받고 출력합니다 >> ";
	int ch; // EOF와의 비교를 위해 int 타입으로 선언
	while((ch = cin.get()) != EOF) { // 문자 읽기
		cout.put(ch); //읽은 문자 출력
		if(ch == '\n')
			break; // <Enter> 키가 입력되면 읽기 중단
	}
}

void get2() {
	cout << "cin.get(char&)로 <Enter> 키까지 입력 받고 출력합니다. >>";
	char ch;
	while(true){
		cin.get(ch); // 문자 읽기
		if(cin.eof()) break; // EOF를 만나면 읽기 종료
		cout.put(ch);
		if(ch == '\n')
			break;
	}
}

int main() {
	get1();
	get2();
}