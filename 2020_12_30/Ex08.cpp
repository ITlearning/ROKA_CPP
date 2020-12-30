#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char text[50];
	char max[50];
	cout << "5명의 이름을 ';'으로 구분하여 입력하세요." << endl;
	for(int i = 0; i < 5; i++){
		cin.getline(text, 50, ';');
		cout << i+1 << ":" << text << endl;
		if(strlen(max) < strlen(text)){
			strcpy(max, text);
		}
		
	}
	
	cout << "가장 긴 이름은 " << max << endl;
}