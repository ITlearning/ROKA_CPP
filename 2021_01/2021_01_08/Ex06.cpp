#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class EverRandom {
	public:
	int next();
	int nextInRange(int a, int b);
};

int EverRandom::next() {
	int r;
	r = rand();
	if(r % 2 == 0) {
		return r;
	}else {
		return r - 1;
	}
	
}

int EverRandom::nextInRange(int a, int b){  //a=2 b =4
	int n = rand()%(b+1-a)+a;
	if(n % 2 == 0){
		return n;
	}else
		return n - 1;
}

int main() {
	srand((unsigned)time(0));
	EverRandom r;
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개 --" << endl;
	for(int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	
	cout << endl << endl << "-- 2에서 " << "10 까지의 랜덤 정수 10 개 --" << endl;
	for(int i = 0; i < 10; i++) {
		int n = r.nextInRange(0, 10);
		cout << n << ' ';
	}
	
	cout << endl;
}

