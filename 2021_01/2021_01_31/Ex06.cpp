#include <iostream>
using namespace std;

class ArrayUtility2 {
public:
	static int* concat(int s1[], int s2[], int size) {
		int *p = new int [size*2];
		for(int i = 0; i < size; ++i) {
			p[i] = s1[i];
		}
		for(int i = 0; i < size; ++i) {
			p[i+size] = s2[i];
		}
		
		
		return p;
 		
	}
	static int* remove(int s1[], int s2[], int size, int& retSize) {
		int *b = new int[size];
   	 	retSize = size;
    	bool sw;
   		 for (int i = 0; i < size; ++i) {
       	 	sw = false;
        	for (int j = 0; j < size; ++j) {
            	if (s1[i] == s2[j]) {
                	sw = true;
                	--retSize;
                	break;
            	}
       	 	}
        	if (!sw) b[i] = s1[i];
		}
    	return b;
	}
};

	
int main() {
	int x[5];
	int y[5];
	int *z;
	int retSize = 0;
	
	cout << "정수 5개를 입력하세요. 배열 x에 삽입합니다. >> ";
	for(int i = 0; i < 5; i++) {
		cin >> x[i];
	}
	
	cout << "정수 5개를 입력하세요. 배열 y에 삽입합니다. >> ";
	for(int i = 0; i < 5; i++) {
		cin >> y[i];
	}
	
	cout << endl;
	cout << "합친 정수 배열을 출력한다." << endl;
	z = ArrayUtility2::concat(x,y,5);
	
	for(int i = 0; i < 10; i++) {
		cout << z[i] << ' ';
	}
	cout << endl;
	z = ArrayUtility2::remove(x,y,5,retSize);
	cout << "배열 x[] 에서 y[]를 뺀 결과를 출력한다. 개수는 " << retSize << endl;
	
	for(int i = 0; i < retSize; i++) {
		cout << z[i] << ' ';
	}
	cout << endl;
}
	
	
