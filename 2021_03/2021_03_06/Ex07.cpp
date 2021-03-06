// get() 과 put() 을 이용한 이미지 파일 복사
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int a = 0;
	try {
	const char* srcFile = "/workspace/CPP/2021_02/2021_02_28/swift-og.png";
	const char* destFile = "/workspace/CPP/2021_02/2021_02_28/copy-swift-og.png";
	
	ifstream fsrc(srcFile, ios::in | ios::binary);
	if(!fsrc) {
		a = 1;
		throw "/workspace/ROKA_CPP/2021_02/2021_02_28/swift-og.png 열기 오류";
	}
	
	ofstream fdest(destFile, ios::out | ios::binary);
	if(!fdest) {
		a = 2;
		throw "/workspace/ROKA_CPP/2021_02/2021_02_28/copy-swift-og.png 열기 오류";
	}
	
	int c;
	while((c =fsrc.get()) != EOF) {
		fdest.put(c);
	}
	cout << srcFile << "을 " << destFile << "로 복사 완료" << endl;
	fsrc.close();
	fdest.close();
	}
	catch(const char* s) {
		if(a == 1) {
			cout << s << endl;
		} else if (a == 2) {
			cout << s << endl;
		}
	}
	
	
}