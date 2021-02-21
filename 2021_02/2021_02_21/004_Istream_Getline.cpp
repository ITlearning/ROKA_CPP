// istream의 getline() 함수로 한 줄 읽기
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char line[80];
	cout << "cin.getline() 함수로 라인을 읽습니다." << endl;
	cout << "exit를 입력하면 루프가 끝납니다." << endl;
	int no = 1; // 라인 번호
	while(true) {
		cout << "라인 " << no << " >> ";
		cin.getline(line, 80); // 한 라인의 문자열 읽기. 79개까지 문자 읽음.
		int n = cin.gcount(); // getline으로 읽은 문자의 개수. 하지만 마지막 <Enter>키 혹은 '\0' 문자 까지도 읽어내 입력한 문자의 개수보다 한개 더 많은 숫자가 반환된다.
		
		if(strcmp(line, "exit") == 0)
			break;
		cout << "echo --> ";
		cout << line << endl;  // 읽은 라인을 화면에 출력
		cout << "문자 수 --> ";
		cout << n - 1 << endl; // 따라서 -1을 해줬다.
		no++;
	}
}