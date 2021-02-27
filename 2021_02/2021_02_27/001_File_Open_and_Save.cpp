// 키보드로부터 입력 받아 텍스트 파일 저장하기
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	char name[10], dept[20];
	int sid;
	
	cout << "이름 >> ";
	cin >> name;
	cout << "학번 >> ";
	cin >> sid;
	cout << "학과 >> ";
	cin >> dept;
	
	// 없던 파일을 내가 지정한 위치에 생성하고 뒤에 쓰기에 입력된 것들이 같이 입력된 텍스트 파일을 생성
	
	ofstream fout("/workspace/ROKA_CPP/2021_02/2021_02_27/student.txt");  // 파일열기. 파일을 열고 , 출력 스트림 생성
	if(!fout) { // 파일을 열지 못했을때의 조건문
		cout << "/workspace/ROKA_CPP/2021_02/2021_02_27/student.txt 파일을 열 수 없다." << endl;
		return 0;
	}
	
	
	//파일에 쓰기
	fout << name << endl; // name 과 '\n' 입력
	fout << sid << endl;
	fout << dept << endl;
	
	// 파일 닫기. 파일과 연결됐던 것이 끊김.
	fout.close();
}