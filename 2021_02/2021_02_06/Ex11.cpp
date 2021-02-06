#include <iostream>
using namespace std;

class Stack {
	int *p;
	int cnt;
public:
	Stack() { p = new int [5]; cnt = 0; }
	bool operator ! ();
	Stack& operator << (int push);
	void operator >> (int& pop);
};

bool Stack::operator !() {
	if(cnt == 0) return true;
	else return false;
}

Stack& Stack::operator << (int push) {
	this->p[cnt] = push;
	cnt++;
	return *this;
}

void Stack::operator >> (int& pop) {
	--cnt;
	pop = p[cnt];
}

int main() {
	Stack stack;
	stack << 3 << 5 << 10;
	while(true) {
		if(!stack) break;
		int x;
		stack >> x;
		cout << x << ' ';
	}
	
	cout << endl;
}