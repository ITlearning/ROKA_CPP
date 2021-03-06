#include <iostream>
#include <fstream>
using namespace std;

int* copy(int* src, int size) {
	int* p = NULL;
	if(size <= 0) {
		throw "Too Small";
		return NULL;
	} else if (size >= 100) {
		throw "Too Big";
		return NULL;
	}
	p = new int [size];
	if(p == NULL) {
		throw "Memery Short";
		return NULL;
	}
	else if (src == NULL) {
		throw "NULL Source";
		return NULL;
	}else {
			for(int n = 0; n < size; n++) {
			p[n] = src[n];
		}
			return p;
	}
		

}

int main() {
	int x[] = {1,2,3};
	
	try{
		int *p = copy(x,3);
		for(int i = 0; i < 3; i++) cout << p[i] << ' ';
		cout << endl;
		delete [] p;
	}
	catch(const char *s)  {
		cout << s << endl;
	}
}