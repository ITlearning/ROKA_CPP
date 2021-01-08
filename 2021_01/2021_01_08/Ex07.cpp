#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class SelectableRandom {
	public:
	int next();
	int nextInRange(int a, int b);
};

int SelectableRandom::next() {
	int r;
	r = rand();
	if(r % 2 == 0) {
		return r;
	}else {
		return r - 1;
	}
	
}

int SelectableRandom::nextInRange(int a, int b){  //a=2 b =4
	int n = rand()%(b+1-a)+a;
	if(n % 2 != 0){
		return n;
	}else
		return n + 1;
}

int main() {
	srand((unsigned)time(0));
	SelectableRandom r;
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 짝수 정수 10 개 --" << endl;
	for(int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	
	cout << endl << endl << "-- 2에서 " << "9 까지의 랜덤 홀수 정수 10 개 --" << endl;
	for(int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 9);
		cout << n << ' ';
	}
	
	cout << endl;
}

