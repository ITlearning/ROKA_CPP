// STL함수 for_each() 를 이용하여 벡터의 모든 원소 출력
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(int n) {
	cout << n << ' ';
}

int main() {
	vector<int> v = {1,2,3,4,5};
	
	// for_each() 는 벡터 v의 첫번째 원소 (v.begin()) 부터 (v.end()) 까지 검색하면서,
	// 각원소에 대해 3번째 매개 변수인 print(int n) 호출, 매개 변수 n에 원소 값 전달
	
	for_each(v.begin(), v.end(), print);
}