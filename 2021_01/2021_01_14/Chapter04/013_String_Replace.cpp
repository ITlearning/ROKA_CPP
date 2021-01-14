//문자열을 입력 받고 회전시키기

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	
	cout << "아래에 문자열을 입력하세요. 빈 칸이 있어도 됩니다. (한글은 불가능 ㅇㅇ) " << endl;
	getline(cin, s, '\n');
	
	for(int i = 0 ; i < s.length(); i++) {
		string first = s.substr(0, 1); //맨 앞의 문자 1개를 문자열로 분리
		string sub = s.substr(1, s.length() - 1); //나머지 문자들을 문자열로 분리
		s = sub + first; //두 문자열을 연결하여 새로운 문자열을 만듦
		cout << s << endl;
	}
}