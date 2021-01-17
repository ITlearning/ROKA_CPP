#include <iostream>
using namespace std;

class Sample {
	int *p;
	int size;
	public:
	Sample(int n) {
		size = n;
		p = new int[n];
	}
	
	void read(); // 동적 할당받은 정수 p에 사용자로부터 정수를 입력 받음
	void write(); // 정수 배열을 화면에 출력
	int big(); // 정수 배열에서 가장 큰 수 리턴
	~Sample();
};

void Sample::read() {
	cout << "정수 10개를 입력하세요." << endl;
	for(int i = 0; i < 10; i++) {
		cin >> p[i];
	}
}

void Sample::write() {
	for(int i = 0; i < size; i++){
		cout << p[i] << ' ';
	}
	cout << endl;
}

int Sample::big() {
	int Max = 0;
	for(int i = 0; i < size; i++) {
		if(Max < p[i]) {
			Max = p[i];
		} 
	}
	return Max;
}

Sample::~Sample() {
	
}

int main() {
	Sample s(10);
	s.read();
	s.write();
	cout << "가장 큰 수는 " << s.big() << endl;
}
