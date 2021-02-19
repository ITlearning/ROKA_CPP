#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Nation {
	string nation;
	string capital;
public:
	Nation(string nation = "", string capital = "") {
		this->nation = nation;
		this->capital = capital;
	}
	bool same(Nation n) {
		if(this->nation == n.nation && this->capital == n.capital) return true;
		else return false;
	}
	string getNation() { return nation; }
	string getCapital() { return capital; }
};

int main() {
	vector<Nation> v;
	int n;
	string nation;
	string capital;
	string answer;
	v.push_back(Nation("미국", "와싱턴"));
	v.push_back(Nation("한국", "서울"));
	v.push_back(Nation("독일", "리스본"));
	v.push_back(Nation("영국", "런던"));
	v.push_back(Nation("중국", "베이징"));
	v.push_back(Nation("일본", "도쿄"));
	v.push_back(Nation("북한", "평양"));
	v.push_back(Nation("러시아", "모스크바"));
	v.push_back(Nation("베트남", "하노이"));
	cout << "***** 나라의 수도 맞추기 게임을 시작합니다. *****" << endl;
	while(true) {
		cout << "정보입력 : 1, 퀴즈 : 2, 종료 : 3 >> ";
		cin >> n;
		if(n == 3)
			break;
		switch(n) {
			case 1 : 
				cout << "현재 " << v.size() << "개의 나라가 입력되어 있습니다." << endl;
				cout << "나라와 수도를 입력하세요. (no no 이면 입력끝)" << endl;
				while(true) {
					cout << v.size() + 1 << ">> ";
					cin >> nation >> capital;
					for(int i = 0; i < v.size(); i++) {
						if(v[i].getNation() == nation && v[i].getCapital() == capital)
							cout << "already exists !!" << endl;
						else 
							v.push_back(Nation(nation, capital));
	
					} 
					
					if(nation == "no" && capital == "no")
						break;
				}
				break;
			case 2 :
				while(true){
					srand((unsigned)time(0));
					int n = rand() % v.size();
					cout << v[n].getNation() << "의 수도는? > ";
					cin >> answer;
					if(answer == "exit")
						break;
					if(v[n].getCapital() == answer)
						cout << "Correct!!!" << endl;
					else 
						cout << "No !!" << endl;
				}
				break;
		}
	}
}