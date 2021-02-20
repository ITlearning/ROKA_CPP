#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class Word {
	string kor;
	string eng;
public:
	Word(string kor, string eng) {this->eng = eng; this->kor = kor; }
	void set(string eng, string kor) { this->eng = eng; this->kor = kor; }
	string getEng() { return eng; }
	string getKor() { return kor; }
};

int main() {
	vector<Word> v;
	string eng;
	string kor;
	int cnt = 0;
	v.push_back(Word("아기", "Baby"));
	v.push_back(Word("인간", "Human"));
	v.push_back(Word("감정", "Emotion"));
	v.push_back(Word("동물", "Animal"));
	v.push_back(Word("그림", "Painting"));
	v.push_back(Word("인형", "Doll"));
	v.push_back(Word("사회", "Society"));
	v.push_back(Word("거래", "Trade"));
	v.push_back(Word("사진", "Photo"));
	
	cout << "영어 어휘 테스트를 시작합니다. 1~4이외 다른 입력시 종료합니다." << endl;
	while(true) {
		int but;
		cout << "어휘 삽입: 1, 어휘 테스트: 2, 프로그램 종료 : 그외키 >> ";
		cin >> but;
		switch(but) {
			case 1 :
				cout << "영어단어에 exit를 입력하면 입력 끝" << endl;
				while(true) {
					if(cnt == 0) {
					cout << "영어 >>";
					cin >> eng;
					if(eng == "exit")
						break;
					cnt = 1;
					} else if (cnt == 1) {
					cout << "한글 >> ";
					cin >> kor;
					cnt = 0;
					}
					v.push_back(Word(kor, eng));
				}
				
				
				break;
			case 2 :
				while(true) {
					srand((unsigned)time(0));
					int n = rand() % v.size();
					int tmp = rand() % v.size();
					int answer = rand() % 4 + 1;
					int num;
					bool t = true;
					cout << v[n].getEng() << "? " << endl;
					for(int i = 0; i < 4; i++) {
						cout << "(" <<  i + 1 << ")" ;
						if(answer == 1) {
							if(i == 0) {
								cout << v[n].getKor();
							} else {
								tmp = rand() % v.size();
								while(t) {
									if(v[tmp].getKor() == v[n].getKor()) {
									tmp = rand() % v.size();
									} else {
										t = false;
									}
								}
								cout << v[tmp].getKor();
							}
						} else if (answer == 2){
							if(i == 1) {
								cout << v[n].getKor();
							} else {
								tmp = rand() % v.size();
								while(t) {
									if(v[tmp].getKor() == v[n].getKor()) {
									tmp = rand() % v.size();
									} else {
										t = false;
									}
								}
								cout << v[tmp].getKor();
							}
						} else if (answer == 3) {
							if (i == 2) {
								cout << v[n].getKor();
							} else {
								tmp = rand() % v.size();
								while(t) {
									if(v[tmp].getKor() == v[n].getKor()) {
									tmp = rand() % v.size();
									} else {
										t = false;
									}
								}
								cout << v[tmp].getKor();
							}
						} else if (answer == 4) {
							if (i == 3) {
								cout << v[n].getKor();
							} else {
								tmp = rand() % v.size();
								while(t) {
									if(v[tmp].getKor() == v[n].getKor()) {
										tmp = rand() % v.size();
									} else {
										t = false;
									}
								}
								cout << v[tmp].getKor();
							}
						}
					}
					cin >> num;
					if(num > 0 && num < 5) {
						if (num == answer){
						cout << "Excellent !!" << endl;
						} else if (num != answer) {
							cout << "No !!" << endl;
						}
					} else {
						break;
					}
				}
			break;
		}
		if(but != 1 && but != 2) {
			break;
		}
	}
}