// 입력 스트림에 사용되는 조작자 만들기
#include <iostream>
#include <string>
using namespace std;

istream& question(istream& ins) {
	cout << "거울아 거울아 누가 제일 예쁘니 : ";
	return ins;
}

int main() {
	string answer;
	cin >> question >> answer;
	cout << "세상에서 제일 예쁜 사람은 " << answer << "입니다." << endl;
}