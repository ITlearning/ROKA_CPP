#include <iostream>
#include <fstream>
using namespace std;

void printhex(char* text, int size) {
	for(int i = 0; i < size; i++) {
		if(i % 7 == 0) {
			cout << '\t';
		}
		cout.precision(2);
		cout << hex << (int)text[i];
	}
	cout << endl;
}

int main() {
	ifstream fin("/workspace/ROKA_CPP/2021_03/2021_03_03/system.ini");
	if(!fin) {
		cout << "파일을 읽을 수 없습니다." << endl;
		return 0;
	}
	
	char text[80];
	while(fin.getline(text, 81)) {
		printhex(text,81);
	}
}