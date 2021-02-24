// 출력 스트림에 사용되는 조작자 만들기
#include <iostream>
using namespace std;

ostream& fivestar(ostream& outs) {
	return outs << "*****";
}

ostream& rightarrow(ostream& outs) {
	return outs << "---->";
}

/*
ostream& beep(ostream& outs) {
	return outs << '\a';
}
*/

int main() {
	cout << "벨이 울립니다." << endl;
	cout << "C" << rightarrow << "C++" << rightarrow << "Java" << endl;
	cout << "Visual" << fivestar << "C++" << endl;
}