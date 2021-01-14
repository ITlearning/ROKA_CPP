#include <iostream>
#include <string>
using namespace std;

class WordGame {
	string a;
	string b;
	public:
	void type(string a, string b);
}

void WordGame::type(string a, string b) {
	int asize = a.size();
	if(a.at(asize - 2) == b.at(0) && a.at(asize - 1) == b.at(1)) {
		a = b;
	}else {
		return 0;
	}
}


class player {
	string p;
	public:
	player();
	void name(string s) {
		p = s;
	}
	
	string print() {
		return p;
	}
}

int main() {
	int n;
	string name;
	WordGame g;
	cout << "끝말 잇기 게임을 시작합니다." << endl;
	cout << "게임에 참가하는 인원은 몇명입니까? >> ";
	cin >> n;
	class *p = player[n];
	
	for(int i = 0; i < n; i++) {
		cout << "참가자의 이름을 입력하세요(빈칸없이) : ";
		cin >> name;
		player[i].name(name);
	}
	string startstring = "아버지";
	int startpeople = 0;
	string b;
	cout << "시작하는 단어는 아버지 입니다." << endl; 
	while(true) {
		cout << player[startpeople++].print() << ">> ";
		cin >> b;
		g.type(startstring, b);
	}
}