#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream fin("/workspace/ROKA_CPP/2021_03/2021_03_03/system.ini");
	if(!fin) {
		cout << "파일을 읽을 수 없습니다." << endl;
		return 0;
	}
	string word;
	while(getline(fin, word)) {
		cout << word << endl;
	}

	fin.close();
}