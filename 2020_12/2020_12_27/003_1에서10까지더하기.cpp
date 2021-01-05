#include <iostream>
using namespace std;

int sum(int r) {
	int a = 0;
	for (int i = r; i < 11; i++) {
		a = i + a;
	}
	
	return a;
} 

int main() {
	cout << "1에서 10까지 더한 결과는 " << sum(1) << " 입니다." << endl;
}
