#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

void fileRead(vector<string> &v, ifstream &fin) {
	string line;
	while(getline(fin,line)) {
		v.push_back(line);
	}
}

void start() {
	for(int i = 0; i < 20; i++) {
		cout << "-";
	}
	cout << endl;
	cout << "지금부터 행맨 게임을 시작합니다." << endl;
	for(int i = 0; i < 20; i++) {
		cout << "-";
	}
	cout << endl;
}

int printWord(vector<string> &w, string &m) {
	srand((unsigned)time(0));
		int n = rand() % 30;
		string Pword = w[n];
		
		while(true) {
			char rn1 = rand() % 26 + 'a';
			char rn2 = rand() % 26 + 'a';
			if(Pword.find(rn1) != string::npos && Pword.find(rn2) != string::npos) {
				char line = '-';
				replace(Pword.begin(), Pword.end(),rn1, line);
				replace(Pword.begin(), Pword.end(),rn2, line);
				m = Pword;
				break;
			}
	}
	
	return n;
}

bool game(vector<string> &v, int len, string z) {
	string Nword = v[len];
	string Pword = z;
	int cnt = 5;
	bool t = true;
	while(t) {
		cout << Pword << endl;
		cout << ">> ";
		string answer;
		cin >> answer;
		cnt--;
		if(cnt < 0) {
				string b;
				cout << "5번 실패하였습니다." << endl;
				cout << Nword << endl;
				cout << "Next(y/n)? ";
				cin >> b;
				if(b == "n") {
					return false;
				}else {
					break;
				}
			}
		if(Nword.find(answer) != string::npos) {
				for(int i = 0; i < Nword.length(); i++) {
					if(Nword.compare(i,1,answer) == 0) {
						if(Pword.compare(i,1,"-") == 0) {
							Pword.replace(i,1,answer);
						} else {
							cout << "이미 존재하는 알파벳입니다." << endl;
						}
					}
				}
				cout << Pword << endl;
				
				if(Nword == Pword) {
					cout << "Next(y/n) > ";
					string yorn;
					cin >> yorn;
					
					if(yorn == "n") {
						return false;
					} else {
						break;
					}
				}
		}
	}
	
	return true;
} 

int main() {
	vector<string> Word;
	string name;
	bool t = true;
	ifstream fin("/workspace/ROKA_CPP/2021_03/2021_03_01/words.txt");
	if(!fin) {
		cout << "words.txt 파일을 열 수 없습니다." << endl;
		return 0;
	}
	
	fileRead(Word, fin);
	fin.close();
	
	start();
	while(t) {
		int a = printWord(Word, name);
		t = game(Word, a, name);
	}
	
}