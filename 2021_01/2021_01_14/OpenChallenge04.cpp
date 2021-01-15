#include <iostream>
#include <string>
using namespace std;

class Player {
	string name;
	public:
	void setName(string name) { this->name = name; }
	string getName() { return name; }
};

class WordGame {
	int num;
	string name;
	Player *p;
	public:
	WordGame(int num) {
		this->num = num;
		p = new Player[num];
	}
	
	void Game() {
		for(int i = 0; i < this->num; i++) {
			cout << "참가자의 이름을 입력하세요. 빈칸없이 입력하세요. >> "; 
			cin >> name;
			p[i].setName(name);
		}
		cout << "시작하는 단어는 아버지 입니다." << endl;
		string a = "아버지";
		string b;
		int set = 0;
		while(true) {
			
			if(set > num - 1){
				set = 0;
			}
			cout << p[set++].getName() << " >> "; 
			cin >> b;
		
		if(a.at(a.size() - 3) == b.at(0) && a.at(a.size() - 2) == b.at(1) && a.at(a.size() - 1) == b.at(2)) {
			a = b;
		}else {
			cout << "끝" << endl;
			break;
		}
		}
		
	}
};



int main() {
	int num;
	cout << "끝말 잇기 게임을 시작합니다." << endl;
	cout << "게임에 참여하는 인원은 몇명입니까? >> ";
	cin >> num;
	WordGame WordGame(num);
	WordGame.Game();
}