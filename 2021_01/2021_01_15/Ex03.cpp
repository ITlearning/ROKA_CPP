#include <iostream>
#include <string>
using namespace std;

int main() {
	string text;
	int cnt = 0;
	int index = 0;
	int fal = 1;
	cout << "문자열 입력 >> ";
	getline(cin, text, '\n');
	
	/*
	for(int i = 0; i < text.size(); i++) {
		if(text[i] == 'a' ) {
			cnt++;
		}
	}
	*/
	
	while(fal){
		int number = text.find('a', index);
		if(number != -1) {
			index = number + 1;
			cnt++;
		}else {
			fal = 0;
		}
	}
	
	
	cout << "문자 a는 " << cnt << "개 있습니다." << endl;
}