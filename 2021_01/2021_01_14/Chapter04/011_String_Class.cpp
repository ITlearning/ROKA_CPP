//string 클래스를 이용한 문자열 생성 및 출력

#include <iostream>
#include <string>
using namespace std;

int main() {
	//스트링 생성
	string str;
	string address("서울시 성북구 삼선동 389");
	string copyAddress(address); //address의 문자열을 복사한 스트링 객체 생성
	
	char text[] = {'L', 'o', 'v', 'e', ' ', 'C', '+', '+', '\0'}; //C-스트링
	string title(text);
	
	cout << str << endl; //빈 스트링. 아무것도 출력되지 않음.
	cout << address << endl;
	cout << copyAddress << endl;
	cout << title << endl;
}