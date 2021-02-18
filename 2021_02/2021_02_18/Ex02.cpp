#include <iostream>
using namespace std;

template <class T>
bool equalArrays(T x[], T y[], T a) {
	for(int i = 0; i < a; i++) {
		if(x[i] != y[i]) {
			return false;
		}
	}
	
	return true;
}

int main() {
	int x[] = {2,10,100,5,4};
	int y[] = {1,10,100,5,4};
	if(equalArrays(x,y,5)) cout << "같다";
	else cout << "다르다";
	cout << endl;
}