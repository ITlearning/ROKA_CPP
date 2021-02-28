// 파일 크기 알아내기
#include <iostream>
#include <fstream>
using namespace std;

long getFileSize(ifstream& fin) {
	fin.seekg(0, ios::end); // get pointer를 파일의 맨 끝으로 옮김
	long length = fin.tellg(); // get pointer의 위치를 알아냄
	
	return length; // length 는 파일의 크기와 동일
}

int main() {
	const char* file = "/workspace/ROKA_CPP/2021_02/2021_02_28/words.txt";
	
	ifstream fin(file); // 파일 열기
	if(!fin) {
		cout << file << " 열기 오류" << endl;
		return 0;
	}
	cout << file << "의 크기는 " << getFileSize(fin) << endl;
	fin.close();
}