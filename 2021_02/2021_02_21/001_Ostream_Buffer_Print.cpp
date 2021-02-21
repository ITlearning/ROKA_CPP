// ostream의 멤버 함수를 이용한 문자 출력 
// ostream은 문자 단위 출력 스트림이다. istream은 문자 단위 입력 스트림, iostream은 문자 단위로 입출력을 동시에 할 수 있는 스트림 클래스 이다.
#include <iostream>
using namespace std;

int main() {
	// "HI!"를 출력하고 다음 줄로 넘어간다.
	cout.put('H');
	cout.put('I');
	cout.put(33); // ASCII 코드 33은 !문자임
	cout.put('\n');
	
	cout.put('C').put('+').put('+').put(' '); // put() 함수를 연결하여 사용할 수 있다
	
	char str[] = "I Love Programming";
	cout.write(str,6).put('\n'); //str배열의 6개의 문자 I Love를 스트림에 출력
}