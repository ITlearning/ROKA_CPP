#include <iostream>
#include <string>
using namespace std;

int main() {
	string cmd;
	while(true) {
		cout << "종료하려면 exit를 입력하세요 >> ";
		getline(cin,cmd); // <Enter> 키까지 문자열로 읽기, 79개 까지 문자 읽음. 80 - 1 을 문자로 읽고, 배열끝엔 '\0' 삽입
		if(cmd == "exit") {
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		}
	}
}
