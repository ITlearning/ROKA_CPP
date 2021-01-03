#include <iostream>
using namespace std;

int main() {
	int num;
	int person;
	int t = 1;
	cout << "***** 승리장에 오신 것을 환영합니다. *****" << endl;
	while(t) {
		cout << "짬뽕:1, 짜장:2, 군만두:3, 종료:4 >> ";
		cin >> num;
		if(num > 4) {
			cout << "다시 주문하세요." << endl;
		}else {
			switch(num) {
				case 1 :{
						cout << "몇인분? ";
						cin >> person ;
						cout << "짬뽕 " << person << "인분 나왔습니다." << endl;
						break;
					}
				case 2 :{
						cout << "몇인분? ";
						cin >> person;
						cout << "짜장 " << person << "인분 나왔습니다." << endl;
						break;
					}
				case 3 :{
						cout << "몇인분? ";
						cin >> person;
						cout << "군만두 " << person << "인분 나왔습니다." << endl;
						break;
					}
				case 4 :{
						cout << "오늘 영업은 끝났습니다. " << endl;
						t = 0;
						break;
					}
			}
		}
	}
}