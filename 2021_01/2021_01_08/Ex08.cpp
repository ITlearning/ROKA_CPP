#include <iostream>
#include <string>
using namespace std;

class Integer {
	int num;
	public:
	Integer(int n);
	Integer(string s);
	int get();
	void set(int v);
	int isEven();
};

inline Integer::Integer(int n) {
	num = n;
}

inline Integer::Integer(string s) {
	num = stoi(s);
}

inline int Integer::get() {
	return num;
}

inline void Integer::set(int v) {
	num = v;
}

inline int Integer::isEven() {
	return true;
}

int main() {
	Integer n(30);
	cout << n.get() << ' ';
	n.set(50);
	cout << n.get() << ' ';
	
	Integer m("300");
	cout << m.get() << ' ';
	cout << m.isEven();
	
	cout << endl;
}