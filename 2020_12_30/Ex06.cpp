#include <iostream>
#include <string>
using namespace std;

int main() {
	string Privnum0;
	string Privnum1;
	
	cout <<"새 암호를 입력하세요 >> "; 
	cin >> Privnum0;
	//getline(cin, Privnum0);
	cout << "새 암호를 다시 한번 입력하세요 >> ";
	cin >> Privnum1;
	//getline(cin, Privnum1);
	
	if(Privnum0 == Privnum1) {
		cout << "같습니다." << endl;
	}else {
		cout << "다릅니다." << endl;
	}
}