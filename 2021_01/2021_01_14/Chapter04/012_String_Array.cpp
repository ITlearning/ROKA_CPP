//string 배열과 문자열 키 입력 응용

#include <iostream>
#include <string>
using namespace std;

int main() {
	string names[5]; //string 배열 선언
	
	for(int i = 0; i < 5; i++) {
		cout << "이름 >>";
		getline(cin, names[i], '\n');
	}
	
	string latter = names[0];
	
	for(int i = 0; i < 5; i++) {
		if(latter < names[i]) {
			latter = names[i];
		}
	}
	
	cout << "사전에서 가장 뒤에 나오는 이름은 " << latter << endl;
}