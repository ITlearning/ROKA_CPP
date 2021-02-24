#include <iostream>
using namespace std;

int main() {
	char a;
	int cnt = 0;
	while(true) {
		cin.get(a);
		cnt++;
		if(cin.eof()) break;
		if(a == ';')
			cin.ignore(cnt);
		cout.put(a);
		if(a == '\n')
			break;
	}
	
}