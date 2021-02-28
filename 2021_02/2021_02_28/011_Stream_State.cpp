// 스트림 상태 검사
#include <iostream>
#include <fstream>
using namespace std;

void showStreamState(ios& stream) {
	cout << "eof() " << stream.eof() << endl;
	cout << "fail() " << stream.fail() << endl;
	cout << "bad() " << stream.bad() << endl;
	cout << "good() " << stream.good() << endl;
}

int main() {
	const char* noExistFile = "/workspace/ROKA_CPP/2021_02/2021_02_28/wordss.txt"; // 존재하지 않는 파일명
	const char* existFile = "/workspace/ROKA_CPP/2021_02/2021_02_28/words.txt";    // 존재 하는 파일명
	
	ifstream fin(noExistFile);
	if(!fin) {
		cout << noExistFile << " 열기 오류" << endl;
		showStreamState(fin); // 스트림 상태 출력
		
		cout << existFile << " 파일 열기" << endl;
		fin.open(existFile);
		showStreamState(fin);
	}
	
	int c;
	while((c=fin.get()) != EOF) {
		cout.put(char(c));
	}
	
	cout << endl;
	showStreamState(fin); // 스트림 상태 출력
	
	fin.close();
}