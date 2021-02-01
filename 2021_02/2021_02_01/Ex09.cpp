#include <iostream>
#include <string>
using namespace std;

class Board {
	static string *paper;
	static int cnt;
public:
	static void add(string text) {
		paper[cnt] = text;
		cnt++;
	}
	static void print() {
		cout << "********** 게시판입니다. **********" << endl;
		for(int i = 0; i < cnt; i++) {
			cout << i << ": " << paper[i] << endl;
		}
	}
};


string *Board::paper = new string[50];
int Board::cnt = 0;

int main() {
	Board::add("중간고사는 감독 없는 자율 시험입니다.");
	Board::add("코딩 라운지 많이 이용해 주세요.");
	Board::print();
	Board::add("진소린 학생이 경진대회 입상하였습니다. 축하해주세요!");
	Board::print();
}