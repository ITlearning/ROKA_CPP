#include <iostream>
using namespace std;

template <class T1,class T2>
T1 * concat(T1 a[], T2 sizea, T1 b[], T2 sizeb) {
	T1 tmp[sizea + sizeb];
	for(int i = 0; i < sizea; i++) {
		tmp[i] = a[i];
	}
	for(int i =sizea; i < sizeb + sizea; i++) {
		tmp[i] = b[i];
	}
	
	return tmp;
}

int main() {
	double a[] = {1,2,3,5};
	double b[] = {6,7,8,9};
	
	concat(a,4,b,4);
	for(int i = 0; i < 8; i++) {
		cout << a[i] << ' '	;
	}
}