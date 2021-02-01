#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Random {
public:
	static void seed() { srand((unsigned)time(0)); }
	
	static int nextInt(int min = 0, int max = 32767) {
		return rand() % (max+1-min) + min;
	}
	
	static char nextAlphabet() {
		return rand() % (122+1-65) + 65;
	}
	static double nextDouble() {
		return rand() % 32767;
	}
};


int main() {
	Random::seed();
	cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다." << endl;
	for(int i = 0; i < 10; i++) {
		cout << Random::nextInt(1,100) << ' ';
	}
	cout << endl;
	cout << "알파벳을 랜덤하게 10개 출력합니다." << endl;
	for(int i = 0; i < 10; i++)
		cout << Random::nextAlphabet() << ' ';
	cout << endl;
}