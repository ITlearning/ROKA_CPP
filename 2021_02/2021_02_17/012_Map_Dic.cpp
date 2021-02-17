// Map으로 영한 사전 만들기
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	map<string, string> dic; // 맵 컨테이너 생성. 키는 영어 단어, 값은 한글 단어
	
	// 단어 3개를 map에 저장
	dic.insert(make_pair("love", "사랑"));
	dic.insert(make_pair("apple", "사과"));
	dic["cherry"] = "체리"; // 위와 같은 의미
	
	cout << "저장된 단어 개수 " << dic.size() << endl;
	string eng;
	while(true) {
		cout << "찾고 싶은 단어 >> ";
		getline(cin, eng);
		if(eng == "exit")
			break;
		
		if(dic.find(eng) == dic.end()) // dic.find(eng) 의 결과가 dic.end() 의 리턴 값과 같다면 dic에는 eng가 없음.
			cout << "없음" << endl;
		else
			cout << dic[eng] << endl;
	}
	
	cout << "종료합니다." << endl;
}