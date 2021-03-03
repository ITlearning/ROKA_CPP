#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("/workspace/ROKA_CPP/2021_03/2021_03_03/test.txt");
	if(!fin) {
		cout << "파일을 열 수 없습니다." << endl;
		return 0;
	}
	
	char buf[30];
	while(fin.getline(buf,30)) {
		cout << buf << endl;
	}
	
	fin.close();
}