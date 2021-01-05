#include <iostream>
using namespace std;

int main() {
	char text[100];
	int xo = 0;
	cout << "문자들을 입력하라(100자 미만)." << endl;
	
	cin.getline(text, 100, '\n');
	
	for(int i = 0; i < 100; i++){
		if(text[i] == 'x'){
			xo += 1;
		}
	}
	
	cout << "x의 개수는 " << xo << endl;
}