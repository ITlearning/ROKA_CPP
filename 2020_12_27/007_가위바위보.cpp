#include <iostream>
#include <string>
using namespace std;

string r(string s, string t) {
	if(s == "가위" && t == "보" || s == "바위" && t == "가위" || s == "보" && t == "바위") {
		cout << "로미오가 이겼습니다." << endl;
	}
	else if (s == t){
			cout << "비겼습니다." << endl;
	} else {
		cout << "줄리엣이 이겼습니다." << endl;
	
	}
}

int main() {
	
	while(true) {
	
		string s;
		cout << "로미오 >> ";
		cin >> s;
		
		string t;
		cout << "줄리엣 >> ";
		cin >> t;
	
		r(s,t);
		
		if(r(s,t) != "비겼습니다." ) {
			break; 
		}
	} 
	
	
	return 0;
}
