// ifstream과 >> 연산자를 이용한 텍스트 파일 읽기
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream fin;
	fin.open("/workspace/ROKA_CPP/2021_02/2021_02_27/student.txt");
	if(!fin) {
		cout << "파일을 열 수 없습니다." << endl;
		return 0;
	}
	
	char name[10], dept[20];
	int sid;
	
	//파일 읽기
	fin >> name; // 파일에 있는 문자열을 읽어 name 배열에 저장
	fin >> sid; // 파일에 있는 정수를 읽어 sid에 저장
	fin >> dept; // 파일에 있는 문자열을 읽어 dept 배열에 저장
	
	cout << name << endl;
	cout << sid << endl;
	cout << dept << endl;
	
	fin.close();
}