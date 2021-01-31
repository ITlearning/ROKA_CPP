
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;



class person {
	string per;
	
public:
	person() { 
		
	}
	void setName(string name) {
		per = name;
	}
	string getName() { return per; }
};




class UpDownGame {
	static int Randnumber;
	static int Max;
	static int Min;
public:
	static void start();
};
int UpDownGame::Randnumber;
int UpDownGame::Max = 99;
int UpDownGame::Min = 0;

void UpDownGame::start() {
		UpDownGame::Randnumber = rand() % 100;
		person p[2];
		p[0].setName("김인수");
		p[1].setName("오은경");
	
		cout << "게임을 시작합니다." << endl;
		cout << UpDownGame::Randnumber << endl;
		int ss = 0;
		while(true) {
		if(ss >= 2) ss = 0;
		int num;
		cout << p[ss].getName() << ">> ";
		cin >> num;
		if(UpDownGame::Randnumber == num) {
			cout << p[ss].getName() << "가 이겼습니다!" << endl;
			break;
		}else if(num > UpDownGame::Randnumber) {
			UpDownGame::Max = num;
		}else if(num < UpDownGame::Randnumber) {
			UpDownGame::Min = num;
		}
			
			
		
		cout << "답은 " << UpDownGame::Min << "과 " << UpDownGame::Max << "사이에 있습니다." << endl;
		ss++;
		}
}



int main() {
	srand((unsigned)time(0));
	UpDownGame::start();
	
}