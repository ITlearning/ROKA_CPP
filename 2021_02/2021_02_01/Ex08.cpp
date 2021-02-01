#include <iostream>
#include <string>
using namespace std;

class Trace {
	static string *p;
	static string *s;
	static int cnt;
public:
	static void put(string a, string b) {
		p[cnt] = a;
		s[cnt] = b;
		cnt++;
	}
	
	static void print(string c = "모든") {
		
		if(c == "모든") {
			cout << "----- "<< c << "Trace 정보를 출력합니다." << " -----" << endl;
			for(int i = 0; i < cnt; i++) {
				cout << p[i] << ":" << s[i] << endl;
			}
		}else {
			cout << "----- "<< c << "태그의 Trace 정보를 출력합니다." << " -----" << endl;
			for(int i = 0; i < cnt; i++) {
			if(p[i] == c) {
				cout << p[i] << ":" << s[i] << endl;
				} 
			}
		}
	}
};

string *Trace::p = new string[100];
string *Trace::s = new string[100];
int Trace::cnt = 0;

void f() {
	int a,b,c;
	cout << "두 개의 정수를 입력하세요 >> ";
	cin >> a >> b;
	Trace::put("f()", "정수를 입력 받았음");
	c = a + b;
	Trace::put("f()", "합 계산");
	cout << "합은 " << c << endl;
}

int main() {
	Trace::put("main()", "프로그램 시작합니다.");
	f();
	Trace::put("main()", "종료");
	
	Trace::print("f()");
	Trace::print();
}
