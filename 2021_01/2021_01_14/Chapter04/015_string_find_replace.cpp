//문자열 find 및 replace 
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cout << "여러줄의 문자열을 입력하세요. 입력의 끝은 &입니다. >> ";
	getline(cin, s, '&');
	cin.ignore(); //'&'뒤에 따라오는 엔터 키를 제거하기 위한 코드
	
	string f, r;
	cout << endl << "find: ";
	getline(cin, f, '\n');
	cout << "replace: ";
	getline(cin, r, '\n');
	
	int startIndex = 0;
	while(true) {
		int fIndex = s.find(f, startIndex); //startIndex부터 문자열 f 검색
		if(fIndex == -1)
			break;
		s.replace(fIndex, f.length(), r);   //fIndex부터 문자열 f의 길이만큼 문자열 r로 변경
		startIndex = fIndex + r.length();
	}
	
	cout << s << endl;
}