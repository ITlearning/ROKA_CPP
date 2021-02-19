#include <iostream>
using namespace std;

template <class T>
T * remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retSize) {
	
	bool sw;
	T *p = new T[sizeSrc];
	
	for(int i = 0; i < sizeSrc; ++i) {
		sw = true;
		for(int j = 0; j < sizeMinus; ++j) {
			if(src[i] == minus[j]) {
				sw = false;
				break;
			}
		}
		
		if (sw) {
			p[retSize] = src[i];
			++retSize;
		}
	}
	return p;
}

int main() {
	int src[] = {1,2,3,4,6,7,8,9};
	int minus[] = {1,2,4,5,3,7,8};
	int size = 0;
	int *p = remove(src,8,minus, 7, size);
	for(int i = 0; i < size; ++i)
		cout << p[i] << ' ';
	cout << endl;
	delete [] p;
	
}