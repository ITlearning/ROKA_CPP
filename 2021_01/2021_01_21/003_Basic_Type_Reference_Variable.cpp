//기본 타입 변수에 대한 참조
//기본 타임 변수에 대한 참조 변수를 선언하고 사용하는 사례를 보인다.
#include <iostream>
using namespace std;

int main() {
	cout << "i" << '\t' << "n" << '\t' << "refn" << endl;
	int i = 1;
	int n = 2;
	int &refn = n; // 참조 변수 refn 선언. refn은 n에 대한 별명
	n = 4;
	refn++;
	cout << i << '\t' << n << '\t' << refn << endl;
	
	refn = i; // refn = 1 , i = 1;
	refn++; // refn = 2; n = 2; i = 1;
	cout << i << '\t' << n << '\t' << refn << endl;
	
	int *p = &refn; // p는 refn의 주소를 가짐. 즉 p는 n의 주소.
	*p = 20;
	cout << i << '\t' << n << '\t' << refn << endl;
}