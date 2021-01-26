#include <iostream>
using namespace std;

class MyIntStack {
	int p[10];
	int tos;
public:
	MyIntStack() { tos = -1;} ;
	bool push(int n);
	bool pop(int &n);
};

bool MyIntStack::push(int n) {
	++tos;
	if(tos < 10) {
		p[tos] = n;
		return true;
	}else {
		return false;
	}
	
}

bool MyIntStack::pop(int &n) {
	--tos;
	if(tos >= 0) {
		n = p[tos];
		return true;
	}else {
		return false;
	}
}

int main() {
	MyIntStack a;
	for(int i = 0; i< 11; i++) {
		if(a.push(i)) cout << i << ' ';
		else cout << endl << i + 1 << "번째 stack full" << endl;
	}
	
	int n;
	for(int i = 0; i < 11; i++) {
		if(a.pop(n)) cout << n << ' ';
		else cout << endl << i + 1 << "번째 stack empty" << endl;
	}
	
	cout << endl;
}