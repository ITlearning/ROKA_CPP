#include <iostream>
using namespace std;

class Statistics {
	int *num;
	int cnt;
public:
	Statistics() { num = new int [8]; cnt = 0;}
	bool operator !();
	Statistics& operator << (int x);
	void operator ~();
	void operator >> (int& avg);
};

bool Statistics::operator !() {
	if(cnt != 0) return true;
	else return false;
}

Statistics& Statistics::operator << (int x) {
		this->num[cnt] = x;
		cnt++;
		return *this;
		
	}

void Statistics::operator ~() {
	for(int i = 0; i < cnt; i++) {
		cout << num[i] << ' ';
	}
	cout << endl;
}

void Statistics::operator >> (int& avg) {
	avg = 0;
	for(int i = 0; i < cnt; i++) {
		avg += num[i];
	}
	avg /= cnt;
}

int main() {
	Statistics stat;
	if(!stat) cout << "현재 통계 데이터가 없습니다." << endl;
	
	int x[5];
	cout << "5개의 정수를 입력하세요 >> ";
	for(int i = 0; i < 5; i++) cin >> x[i];
	
	for(int i = 0; i < 5; i++) stat << x[i];
	stat << 100 << 200;
	~stat;
	int avg;
	stat >> avg;
	cout << "avg = " << avg << endl;
}