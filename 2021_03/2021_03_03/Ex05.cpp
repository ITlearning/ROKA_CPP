#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Remark(string src) {
	for(int i = 0; i < src.length(); i++) {
		if(src[i] == '/' && src[i+1] == '/') {
			break;
		}
		cout << src[i];
	}
	
	cout << endl;
}

int main() {
	fstream fin("/workspace/ROKA_CPP/2021_02/2021_02_28/010_Array_Save_Binary.cpp");
	if(!fin) {
		cout << "파일을 열 수 없습니다." << endl;
		return 0;
	}
	string word;
	while(getline(fin, word)) {
		Remark(word);
	}
	
	fin.close();
}