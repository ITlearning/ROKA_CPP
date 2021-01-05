#include <iostream>
using namespace std;

int main() {
	cout << "주소를 입력하세요 >> ";
	char address[100];
	
	cin.getline(address, 100, '\n'); //address 문자배열에 , 100 의 크기로 , \n 이 입력될때까지 입력 받겠다. 
	
	cout << "주소는 " << address << "입니다." << endl; 
} 
