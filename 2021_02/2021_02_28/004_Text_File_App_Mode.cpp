// 텍스트 파일 연결

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* firstFile = "/workspace/ROKA_CPP/2021_02/2021_02_28/student.txt";
	const char* secondFile = "/workspace/ROKA_CPP/2021_02/2021_02_28/system.ini";
	
	fstream fout(firstFile, ios::out | ios::app); // 쓰기모드로 파일 열기
	if(!fout) {
		cout << firstFile << " 열기 오류";
		return 0;
	}
	
	fstream fin(secondFile, ios::in);  // 읽기 모드로 파일 열기
	if(!fin) {
		cout << secondFile << " 열기 오류";
		return 0;
	}
	
	int c;
	while((c = fin.get()) != EOF) { // 파일 끝까지 문자 읽기
		fout.put(c);		  // 읽은 문자 기록
	}
	
	fin.close();	// 입력 파일 닫기
	fout.close();	// 출력 파일 닫기
}