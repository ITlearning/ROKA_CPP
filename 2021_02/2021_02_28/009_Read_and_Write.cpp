// read() / write() 로 이미지 파일 복사
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* srcFile = "/workspace/ROKA_CPP/2021_02/2021_02_28/swift-og.png";
	const char* destFile = "/workspace/ROKA_CPP/2021_02/2021_02_28/copy-swift-og.png";
	
	
	// 소스 파일 열기
	ifstream fsrc(srcFile, ios::in | ios::binary);
	if(!fsrc) {
		cout << srcFile << " 열기 오류" << endl;
		return 0;
	}
	
	// 목적 파일 열기
	ofstream fdest(destFile, ios::out | ios::binary);
	if(!fdest) {
		cout << destFile << " 열기 오류" << endl;
		return 0;
	}
	
	
	// 소스파일에서 목적 파일로 복사하기
	char buf[1024];
	while(!fsrc.eof()) {
		fsrc.read(buf,1024);
		int n = fsrc.gcount();
		fdest.write(buf,n);
	}
	
	cout << srcFile << "을 " << destFile << "로 복사 완료" << endl;
	fsrc.close();
	fdest.close();
}