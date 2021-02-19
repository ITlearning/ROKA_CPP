#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v;
	
	vector<int>::iterator it;
	
	int n;
	double tmp;
	while(true) {
		
		cout << "정수를 입력하세요(0을 입력하면 종료) >> ";
		cin >> n;
		if(n == 0) {
			break;
		}
		v.push_back(n);
		for(it = v.begin(); it != v.end(); it++)
			cout << *it << ' ';
		tmp += n;
		cout << endl;
		cout << "평균 : " << tmp / v.size() << endl;
	}
}