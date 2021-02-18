#include <iostream>
#include <algorithm>
using namespace std;


template <class T>
T biggest(T x[], T a) {
	sort(x, x + a);
	
	return x[a - 1];
}

int main() {
	int x[] = {1,10, 100,200, 5, 2};
	cout << biggest(x,5) << endl;
}