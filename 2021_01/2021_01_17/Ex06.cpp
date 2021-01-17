#include <iostream>
#include <string>
using namespace std;

int main() {
	string text;
	cout << "아래에 한 줄을 입력하세요. (exit를 입력하면 종료합니다.)" << endl;
	while(true) {
		cout << ">> ";
		getline(cin, text, '\n');
		if(text == "exit") {
			break;
		}
		for(int i = text.size() - 1; i >= 0; i--) {
			cout << text[i];
		}
		cout << endl;
	}
}