// vector 컨테이너 활용
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	
	for(int i = 0; i < 3; i++)
		cout << v[i] << " ";
	cout << endl;
	
	v[0] = 10; // 벡터의 첫 번째 원소를 10으로 변경
	int m = v[2]; // m에 3 저장
	v.at(2) = 5;  // 벡터의 3번째 원소를 5로 변경
	
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << ' '; // v[i] 는 벡터의 i 번째 원소
	cout << endl;
}