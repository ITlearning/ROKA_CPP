#include <iostream>
using namespace std;

int big(int a, int b, int c = 100) {
	int Max = 0;
	if(a > b) {
		Max = a;
	}else if(a < b){
		Max = b;
	}
	
	if(Max < c) return Max;
	else return c;
}

int main() {
	int x = big(3,5);
	int y = big(300,50);
	int z = big(30,60,50);
	
	cout << x << ' ' << y << ' ' << z << ' ' << endl;
}