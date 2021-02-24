#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class AbstractPlayer {
	string name;
protected:
	string gbb[3];
public:
	AbstractPlayer(string name) {
		this->name = name;
		gbb[0] = "가위"; gbb[1] = "바위"; gbb[2] = "보";
	}
	
	virtual string turn() = 0;
	string getName() { return name; }
};

class Human : public AbstractPlayer {
	string rcp;
public:
	Human(string name = "") : AbstractPlayer(name) {}
	string turn() {
		while(true) {
			cout << getName() << ">> ";
			cin >> rcp;
			if(rcp == "가위" || rcp == "바위" || rcp == "보" || rcp == "종료")
				return rcp;
		}
		
	}
};

class Computer : public AbstractPlayer {
	string rcp;
public:
	Computer() : AbstractPlayer("Computer") {
		srand((unsigned)time(0));
	}
	string turn() {
		int n = rand() % 3;
		string a = gbb[n];
		return a;
	}
};


int main() {
	bool t = true;
	string user;
	cout << "***** 컴퓨터와 사람이 가위 바위 보 대결을 펼칩니다 *****" << endl;
	cout << "선수 이름을 입력하세요 >> ";
	cin >> user;
	Human h(user);
	Computer c;
	while(t) {
		string human = h.turn();
		string com = c.turn();
		if(human == "종료") {
			t = false;
			break;
		}
			
		
		cout << c.getName() << ": " << com << endl;
			
		
		
		
			if(human == com) {
				cout << "the same." << endl;
			} else if ((human == "가위" && com == "바위") || (human == "바위" && com == "보")) {
				cout << "Computer Win" << endl;
			} else if ((human == "바위" && com == "가위") || (human == "보" && com == "바위")) {
				cout << "Human Win" << endl;
			}
	}
}