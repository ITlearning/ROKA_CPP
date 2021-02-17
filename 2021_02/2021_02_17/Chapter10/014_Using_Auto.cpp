// auto를 이용한 변수 선언
#include <iostream>
#include <vector>
using namespace std;

int square(int x) { return x*x; }

int main() {
	auto a = 'a'; //char 타입으로 결정
	auto pi = 3.14; // double 타입으로 결정
	auto ten = 10; // int 타입으로 결정
	auto *p = &ten; // 변수 p는 int* 타입으로 결정
	cout << a << " " << pi << " " << ten << " " << *p << endl;
	
	auto ret = square(3); // square() 함수의 리턴 타입이 int 이므로 ret 는 int 로 결정
	cout << *p << " " << ret << endl;
	
	vector<int> v = {1,2,3,4,5};
	vector<int>::iterator it;
	for(it = v.begin(); it != v.end(); it++)
		cout << *it << ' ';
	cout << endl;
	
	// 텝플릿에 auto를 사용하여 복잡한 선언의 간소화
	for(auto it = v.begin(); it != v.end(); it++)
		cout << *it << ' ';
	cout << endl;
}