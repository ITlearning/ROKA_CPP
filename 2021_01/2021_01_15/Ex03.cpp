#include <iostream>
#include <string>
using namespace std;

int main() {
	string text;
	int cnt = 0;
	cout << "문자열 입력 >> ";
	getline(cin, text, '\n');
	
	/*
	for(int i = 0; i < text.size(); i++) {
		if(text[i] == 'a' ) {
			cnt++;
		}
	}
	*/
	while(true) {
		int num = 0;
		if(text.find('a', num) != -1) {
			num = text.find('a', num) + 1;
			cnt++;
			
		}
	} 
	
	
	cout << "문자 a는 " << cnt << "개 있습니다." << endl;
}