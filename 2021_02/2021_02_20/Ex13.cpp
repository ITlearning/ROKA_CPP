#include <iostream>
#include <string>
#include <map>
using namespace std;

int menu() {
	int num;
	cout << "입력: 1, 조회:2 종료:3 >> ";
	cin >> num;
	return num;
}

int main() {
	int grade;
	string name;
	bool sw = true;
	map<string, int> b;
	cout << "****** 점수 관리 프로그램 HIGH SCORE을 시작합니다 ******" << endl;
	while(sw) {
		int n = menu();
		switch(n) {
			case 1 :
				cout << "이름과 정수 >> ";
				cin >> name >> grade;
				b.insert(make_pair(name, grade));
				break;
			case 2 :
				cout << "이름 >> ";
				cin >> name;
				if(b.find(name) == b.end()) {
					cout << "그런 사람은 없습니다." << endl;
				} else {
					cout << name << "의 점수는 " << b[name] << endl;
				}
				break;
			case 3 :
				sw = false;
				break;
		}
	}
}