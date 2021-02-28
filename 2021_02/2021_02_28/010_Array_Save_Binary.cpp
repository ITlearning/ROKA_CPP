// int 배열과 double 변수를 바이너리 파일에 저장하고 다시 열기
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* file = "/workspace/ROKA_CPP/2021_02/2021_02_28/data.dat";
	
	ofstream fout;
	fout.open(file, ios::out | ios::binary);
	if(!fout) {
		cout << "파일 열기 오류" << endl;
		return 0;
	}
	
	int n[] = {0,1,2,3,4,5,6,7,8,9};
	double d = 3.15;
	fout.write((char*)n, sizeof(n)); // int 배열 n을 한 번에 파일에 쓴다.
	fout.write((char*)&d, sizeof(d)); // double 값 하나를 파일에 쓴다.
	fout.close();
	// 배열 n과 d 값을 임의의 값으로 변경
	for(int i = 0; i < 10; i++) {
		n[i] = 99;
		d = 8.15;
	}
	
	// 배열 n과 d 값을 파일에서 읽어온다.
	ifstream fin(file, ios::in);
	if(!fin) {
		cout << "파일 열기 오류" << endl;
		return 0;
	}
	
	fin.read((char*)n, sizeof(n));
	fin.read((char*)(&d),sizeof(d));
	for(int i = 0 ; i < 10; i++) {
		cout << n[i] << ' ';
	}
	
	cout << endl << d << endl;
	fin.close();
}