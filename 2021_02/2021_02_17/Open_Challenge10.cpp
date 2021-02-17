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
		srand((unsigned)time(0));
		int n = rand() % v.size();
		int tmp = rand() % v.size();
		int b = rand() % 4 + 1;
		int num;
		
		cout << v[n].getEng() << "?" << endl;
		
		if(b == 1) {
			cout << "(1)" << v[n].getKor() << ' ';
			n = rand() % v.size();
			cout << "(2)" << v[n].getKor() << ' ';
			n = rand() % v.size();
			cout << "(3)" << v[n].getKor() << ' ';
			n = rand() % v.size();
			cout << "(4)" << v[n].getKor() << ' ';
		} else if (b == 2) {
			tmp = rand() % v.size();
			cout << "(1)" << v[tmp].getKor() << ' ';
			cout << "(2)" << v[n].getKor() << ' ';
			tmp = rand() % v.size();
			cout << "(3)" << v[tmp].getKor() << ' ';
			tmp = rand() % v.size();
			cout << "(4)" << v[tmp].getKor() << ' ';
		} else if (b == 3) {
			cout << "(1)" << v[tmp].getKor() << ' ';
			tmp = rand() % v.size();
			cout << "(2)" << v[tmp].getKor() << ' ';
			tmp = rand() % v.size();
			cout << "(3)" << v[n].getKor() << ' ';
			tmp = rand() % v.size();
			cout << "(4)" << v[tmp].getKor() << ' ';
		} else if (b == 4) {
			cout << "(1)" << v[tmp].getKor() << ' ';
			tmp = rand() % v.size();
			cout << "(2)" << v[tmp].getKor() << ' ';
			tmp = rand() % v.size();
			cout << "(3)" << v[tmp].getKor() << ' ';
			tmp = rand() % v.size();
			cout << "(4)" << v[n].getKor() << ' ';
		}
		cout << " >> ";
		cin >> num;
		if(num == b) {
			cout << "Excellent!" << endl;
		} else {
			if(0 < num && num < 5) {
				cout << "No . !!" << endl;
			}else {
				break;
			}
		}
	}
	
}