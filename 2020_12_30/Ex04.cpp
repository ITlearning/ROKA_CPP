#include <iostream>
using namespace std;

int main() {
	double sum[5];
	double num = 0;
	cout << "5 개의 실수를 입력하라. >> ";
	cin >> sum[0] >> sum[1] >> sum[2] >> sum[3] >> sum[4];
	
	for(int i = 0; i < 5; i++) {
		if(num < sum[i]) {
			num = sum[i];
		}
	}
	
	cout << "제일 큰 수 = " << num;
	
	return 0;
}