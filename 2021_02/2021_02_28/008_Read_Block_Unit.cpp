// read() 를 이용하여 블록 단위로 텍스트 파일 읽기
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* file = "/workspace/ROKA_CPP/2021_02/2021_02_28/system.ini";
	
	ifstream fin;
	fin.open(file, ios::in | ios::binary);
	if(!fin) {
		cout << "파일 열기 오류" << endl;
		return 0;
	}
	
	int count = 0;
	char s[32]; // 블록 단위로 읽어들일 버퍼
	while(!fin.eof()) {
		fin.read(s, 32);
		int n = fin.gcount(); // 실제 읽어들인 배열 수
		cout.write(s,n);
		count += n;
	}
	
	cout << "읽은 바이트 수는 " << count << endl;
	fin.close();
}

// 바이너리 모드로 읽을 경우 파일의 바이트 수를 정확히 카운트 할 수 있다.