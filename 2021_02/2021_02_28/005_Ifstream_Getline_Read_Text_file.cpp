// istream 의 getline() 을 이용하여 텍스트 파일을 읽고 화면 출력
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("/workspace/ROKA_CPP/2021_02/2021_02_28/system.ini");
	if(!fin) {
		cout << "/workspace/ROKA_CPP/2021_02/2021_02_28/system.ini 열기 실패" << endl;
		return 0;
	}
	
	char buf[81]; // 한 라인이 최대 80개의 문자로 구성된다고 가정
	while(fin.getline(buf, 81)) {
		cout << buf << endl;
	}
	
	fin.close();
}