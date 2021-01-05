#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char text[100];
	while(true) {
		cout << "종료하고 싶으면 yes를 입력하세요. >> ";
		cin.getline(text, 100, '\n');
		if(strcmp(text,"yes") == 0) {
			cout << "종료합니다. . ." << endl;
			break;
		}
	}
}