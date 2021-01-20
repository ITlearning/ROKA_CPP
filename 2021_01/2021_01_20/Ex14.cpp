#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player {
	string name;
	int num;
	public:
	void setPlayer(string name) { this->name = name; }
	string getPlayer() { return name; }
	void setNum(int num) { this->num = num; }
	int getNum() { return num; }
};

class GamblingGame {
	Player *p;
	string name;
	int num1,num2,num3;
	public:
	GamblingGame() {
		p = new Player[3]; 
	}
	
	void set() {
		cout << "첫번째 선수 이름 >>";
		cin >> name;
		p[0].setPlayer(name);
		cout << endl;
		cout << "두번째 선수 이름 >>";
		cin >> name;
		p[1].setPlayer(name);
	}
	
	void Game() {
		int number = 0;
		string a;
		while(true) {
			cout << p[number].getPlayer() << ": <Enter>" << endl;
			getline(cin, a, '\n');
			
			num1 = rand() % 3;
			num2 = rand() % 3;
			num3 = rand() % 3;
			
			
			cout << num1 << '\t' << num2 << '\t' << num3 << '\t' ;
			if(num1 == num2 && num1 == num3 ){
				cout << p[number].getPlayer() << "님 승리!!" << endl;
				return;
			}else {
				cout << "아쉽군요!" << endl;
			}
			
			if(number >= 2) {
				number = 0;
			}else
				number += 1;
			
		}
	}
};

int main() {
	srand((unsigned)time(0));
	GamblingGame g;
	g.set();
	g.Game();
}