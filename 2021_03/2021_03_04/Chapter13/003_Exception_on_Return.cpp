// 리턴 값과 참조 매개 변수를 이용한 오류 처리
// 리턴값을 bool로 처리하여 T or F를 이용하여 오류를 처리하였고, 얻어진 값을 참조 매개 변수로 가져왔다.
#include <iostream>
using namespace std;

bool getExp(int base, int exp, int &ret) {
	if(base <= 0 || exp <= 0) {
		return false;
	} 
	int value = 1;
	for(int n = 0; n < exp; n++) {
		value = value * base;
	}
	ret = value;
	return true;
}

int main() {
	int v = 0;
	if(getExp(2,3,v))
		cout << "2의 3승은 " << v << "입니다." << endl;
	else
		cout << "오류. 2의 3승은 " << "계산할 수 없습니다. " << endl;
	
	int e = 0;
	if(getExp(2,-3,e))
		cout << "2의 -3승은 " << v << "입니다." << endl;
	else
		cout << "오류. 2의 -3승은 " << "계산할 수 없습니다. " << endl;
	
}