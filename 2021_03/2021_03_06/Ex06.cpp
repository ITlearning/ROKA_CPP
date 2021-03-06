#include <iostream>
using namespace std;

int* concat(int a[], int sizea, int b[], int sizeb) {
	int* p = new int [sizea+sizeb];
	int* ap = a;
	if(sizea == 0 || sizeb == 0) {
		throw 001;
	} else if (ap == NULL || b[0] == '\0') {
		throw 002;
	} else if (sizea < 0 || sizeb < 0) {
		throw 003;
	}
	int i = 0;
	for(;i < sizea; i++) {
		p[i] = a[i];
	}
	int k = 0;
	for(int j = i; j < sizea+sizeb; j++) {
		p[j] = b[k++];
	}
	
	return p;
}


int main() {
	int z[] = {};
	int x[] = {1,2,3,4,5};
	int y[] = {10,20,30,40};
	try {
		int* p = concat(z,5,y,-1);
		for(int n = 0; n < 9; n++) cout << p[n] << ' ';
		cout << endl;
		delete [] p;
	}
	catch(int failCode) {
		cout << "오류코드 : " << failCode << endl;
	}
}