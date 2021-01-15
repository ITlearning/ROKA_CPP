#include <iostream>
using namespace std;

int main() {
	double max;
	int *p = new int[5];
	cout << "정수 5개 입력 >> ";
	for(int i = 0 ; i < 5; i++) {
		
		cin >> p[i];
		max += p[i];
	}
	
	cout << "평균 : " << max / 5 << endl;
	
	
}