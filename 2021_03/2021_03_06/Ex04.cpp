#include <iostream>
#include <fstream>
using namespace std;

int getFileSize(const char* file) {
	if(file == NULL) throw "파일명이 NULL 입니다.";
	ifstream fin(file);
	if(!fin) throw "열기를 실패하였습니다.";
	fin.seekg(0, ios::end);
	int length = fin.tellg();
	return length;
}

int main() {
	try{
		int n = getFileSize("/workspace/CPP/2021_03/2021_03_03/test.txt");
		cout << "파일 크기 = " << n << endl;
		
		int m = getFileSize("/workspace/CPP/2021_03/2021_03_03/testss.txt");
		cout << "파일 크기 = " << m << endl;
	}
	catch(const char *s) {
		cout << "예외 발생 : " << s << endl;
	}
	
}