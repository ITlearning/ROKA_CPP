#include <iostream>
#include <cstring>
using namespace std;

char& find(char a[], char c, bool& success) {
	int num = 0;
	for(int i = 0; i < strlen(a); i++) {
		if(a[i] == c) {
			cout << a[i] << ' ' << c << endl;
			num = i;
			success = true;
		}
	}
	
	return a[num];
}

int main() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);
	if(b == false) {
		cout << "M을 발견할 수 없다." << endl;
		return 0;
	}
	loc = 'm';
	cout << s << endl;
	
}