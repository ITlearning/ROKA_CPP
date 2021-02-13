#include <iostream>
using namespace std;

class LoopAdder { // 추상 클래스
	string name; // 루프의 이름
	int x,y,sum; // x에서 y까지의 합은 sum
	void read(); // x,y 값을 읽어들이는 함수
	void write(); // sum 을 출력하는 함수 
protected:
	LoopAdder(string name = "") { // 루프의 이름을 받는다. 초기값은 ""
		this->name = name;
	}
	
	int getX() { return x; }
	int getY() { return y; }
	virtual int calc() = 0; //순수 가상함수. 루프를 돌며 합을 구하는 함수
public:
	void run(); // 연산을 진행하는 함수
};

void LoopAdder::read() { // x,y 입력
	cout << name << ": " << endl;
	cout << "처음 수에서 두번째 수까지 더합니다. 두 수를 입력하세요 >> ";
	cin >> x >> y;
}

void LoopAdder::write() {
	cout << x << "에서 " << y << " 까지의 합 = " << sum << "입니다." << endl;
}

void LoopAdder::run() {
	read(); // x,y를 읽는다.
	sum = calc(); //루프를 돌면서 계산한다.
	write(); //결과 sum을 출력한다.
}


class ForLoopAdder : public LoopAdder {
public:
	ForLoopAdder(string name) : LoopAdder(name) {}
	int calc() {
		int tmp = 0;
		for(int i = getX(); i <= getY(); i++) {
			tmp += i;
		}
		return tmp;
	}
};

int main() {
	ForLoopAdder fo("For Loop");
	fo.run();
}