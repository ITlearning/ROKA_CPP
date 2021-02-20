#include <iostream>
#include <string>
#include <map>
using namespace std;

void start() {
	cout << "암호 관리 프로그램 WHO를 시작합니다." << endl;
}

int menu() {
	int num;
	cout << "삽입: 1, 검사:2 종료:3 >> ";
	cin >> num;
	return num;
}

int main() {
	bool sw = true;
	string name;
	string password;
	map<string, string> m;
	start();
	
	while(sw) {
		int n = menu();
		switch(n) {
			case 1 :
				cout << "이름 암호 >> ";
				cin >> name >> password;
				m.insert(make_pair(name,password));
				break;
			case 2 :
				while(true) {
					cout << "이름? ";
					cin >> name;
					if(m.find(name) == m.end()) {
					cout << "그런 사람은 없습니다. 이름을 다시 생각해보세요." << '\n';
					} else {
						break;
					}
				}
				while(true) {
					cout << "암호? ";
					cin >> password;
					if(m.at(name) == password) {
						cout << "통과!!" << endl;
						break;
					} else {
						cout << "실패.." << endl;
					}
				}
				break;
			case 3 :
				cout << "프로그램을 종료합니다..." << endl;
				sw = false;
				break;
		}
		
		if(n > 0 && n < 4) {
			
		} else {
			sw = false;
		}
	}
	
}