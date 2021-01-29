#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;


int main() {
	int a;
	cout << "참여자수를 입력하세요 : ";
	cin >> a;
	string person[a];
	cout << endl;
	for(int i = 0; i < a; i++) {
		cout << i << "번째 참여자의 이름 : ";
		cin >> person[i];
	}
	srand((unsigned)time(0));
	int n = rand();
	n = n % 100;
	int per = 0;
	int num;
	int Max = 0;
	int min = 0;
	cout << "게임을 시작합니다." << endl;
	cout << n << endl;
	while(true) {
		if(per >= 2) per = 0;
		
		cout << person[per] << ">> ";
		cin >> num;
		if(n == num) {
			cout << person[per] << "가 이겼습니다!" << endl;
			break;
		}else if(num > n || num > Max) {
			Max = num;
		}else if(num < n || num < min) {
			min = num;
		}
		
		cout << "답은 " << min << "과 " << Max << "사이에 있습니다." << endl;
		per++;
	}
}