#include <iostream>
#include <algorithm>
using namespace std;

bool desc(int a, int b) {
	return a > b;
}

template <class T>
void reverseArray(T x[], T a) {
	sort(x, x + a, desc);
}

int main() {
	int x[] = {1,10,100,5,4};
	reverseArray(x,5);
	for(int i = 0; i < 5; i++) cout << x[i] << ' ';
}