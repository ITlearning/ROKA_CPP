#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	const char* file = "/workspace/ROKA_CPP/2021_03/2021_03_03/system.txt";
	
	ofstream fout;
	fout.open(file, ios::out | ios::binary);
	if(!fout) {
		cout << "파일 열기 오류" << endl;
		return 0;
	}
	
	
	ifstream fin("/workspace/ROKA_CPP/2021_03/2021_03_03/system.ini");
	if(!fin) {
		cout << "파일을 읽을 수 없습니다." << endl;
		return 0;
	}
	
	char word[219/10];
	int ten = 10;
	int sum = 0;
	while(!fin.eof()) {
		fin.read(word, 219/10);
		fout.write(word, 219/10);
		if(fin.gcount() == 219/10) {
			cout << '.' << fin.gcount() << "B " << ten << "%" << endl;
			ten += 10;
		}
		sum += fin.gcount();
	}
	
	cout << sum << "B " << "복사 완료" << endl;
	
	fin.close();
	fout.close();

}