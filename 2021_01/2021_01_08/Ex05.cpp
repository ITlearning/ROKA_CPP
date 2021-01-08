#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Random {
	int num;
	public:
	Random();
	int next();
	int nextInRange(int a, int b);
};


Random::Random() {
	num = 0;
}

int Random::next() {
	
	num = rand();
	return num;
}

int Random::nextInRange(int a, int b){  //a=2 b =4
	num = rand()%(b+1-a)+a;
	return num;
}

int main() {
	srand((unsigned)time(0));
	Random r;
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개 --" << endl;
	for(int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	
	cout << endl << endl << "-- 2에서 " << "4 까지의 랜덤 정수 10 개 --" << endl;
	for(int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4);
		cout << n << ' ';
	}
	
	cout << endl;
}

