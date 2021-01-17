#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	string text;
	srand((unsigned)time(0));
	cout << "아래에 한 줄을 입력하세요. (exit를 입력하면 종료합니다.)" << endl;
	while(true) {
		cout << ">> ";
		getline(cin, text, '\n');
		if(text == "exit") {
			break;
		}
		int num = rand() % text.size();
		text[num] = rand() % (122+1-97) + 97;
		cout << text << endl;
 	}
	
	
	
}