// get(char*, int) 을 이용한 문자열 입력
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char cmd[80];
	cout << "cin.get(char*, int)로 문자열을 읽습니다. " << endl;
	while(true) {
		cout << "종료하려면 exit를 입력하세요 >> ";
		cin.get(cmd, 80); // <Enter> 키까지 문자열로 읽기, 79개 까지 문자 읽음. 80 - 1 을 문자로 읽고, 배열끝엔 '\0' 삽입
		if(strcmp(cmd,"종료") == 0) {
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		}
		else {
			cin.ignore(1); // 버퍼에 남아있는 <Enter> 키 ('\n') 제거
		}
	}
}

// Tip.
// get() 함수로 한글 문자와 한글 문자열 읽기
// cin은 문자를 한 바이트로 다루도록 작성되어 있기 때문에, 한 문자당 2바이트인 한글문자를 읽을 수 없다.
// 하지만, 한글 문자열의 경우 get(char*, int) 함수를 호출하고 읽을 문자 개수의 2배 크기의 배열을 char에 넘겨주면 한글 문자열을 읽어 들일 수 있다.