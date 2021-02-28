// get() 과 put() 을 이용한 이미지 파일 복사
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* srcFile = "/workspace/ROKA_CPP/2021_02/2021_02_28/swift-og.png";
	const char* destFile = "/workspace/ROKA_CPP/2021_02/2021_02_28/copy-swift-og.png";
	
	ifstream fsrc(srcFile, ios::in | ios::binary);
	if(!fsrc) {
		cout << srcFile << " 열기 오류" << endl;
		return 0;
	}
	
	ofstream fdest(destFile, ios::out | ios::binary);
	if(!fdest) {
		cout << destFile << " 열기 오류" << endl;
		return 0;
	}
	
	int c;
	while((c =fsrc.get()) != EOF) {
		fdest.put(c);
	}
	cout << srcFile << "을 " << destFile << "로 복사 완료" << endl;
	fsrc.close();
	fdest.close();
	
}