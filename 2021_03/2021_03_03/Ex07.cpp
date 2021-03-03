#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

void EndPrint(ifstream& fin,ostream& fout) {
	fin.seekg(0, ios::end);
	int fileSize = fin.tellg();
	for(int i = 0; i < fileSize; i++) {
		fin.seekg(fileSize-1-i, ios::beg);
		int c = fin.get();
		fout << (char)c;
	}
}

int main() {
	const char* file = "/workspace/ROKA_CPP/2021_03/2021_03_03/system.ini";
	
	ofstream fout;
	fout.open(file, ios::out | ios::binary);
	if(!fout) {
		cout << "파일 열기 오류" << endl;
		return 0;
	}
	
	
	ifstream fin("/workspace/ROKA_CPP/2021_03/2021_03_03/system.txt");
	if(!fin) {
		cout << "파일을 읽을 수 없습니다." << endl;
		return 0;
	}
	
	EndPrint(fin,fout);
	
	fin.close();
	fout.close();
}