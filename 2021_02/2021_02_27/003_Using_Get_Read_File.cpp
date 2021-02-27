// get() 을 이용한 텍스트 파일 읽기
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* file = "/workspace/ROKA_CPP/2021_02/2021_02_27/system.ini"; //읽을 파일명;
	ifstream fin(file, ios::in);
	if(!fin) {
		cout << file << "열기 오류" << endl;
		return 0;
	}
	
	int count = 0;
	int c;
	while((c = fin.get()) != EOF) {
		cout << (char)c;
		count++;
	}
	
	cout << "읽은 바이트 수는 " << count << endl;
	fin.close();
}