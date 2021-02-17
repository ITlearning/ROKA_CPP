// STL함수 for_each()와 람다식을 이용하여 벡터의 모든 원소 출력
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v = {1,2,3,4,5};
	
	for_each(v.begin(), v.end(), [](int n) { cout << n << ' ';});
}