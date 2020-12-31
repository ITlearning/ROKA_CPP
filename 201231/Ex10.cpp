#include <iostream>
#include <string>
using namespace std;

int main() {
	string text;
	int a = 0;
	
	cout << "문자열 입력 >> ";
	getline(cin, text, '\n');
	
	for(int i = 0; i < text.size(); i++) {
		for(int j = 0; j <= i; j++) {
			cout << text[a];
			a++;
		}
		a = 0;
		cout << endl;
	}
	
	
	
}