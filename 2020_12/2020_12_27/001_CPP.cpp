#include <iostream>
using namespace std;


double area(int r); //함수의 원형 선언
double area(int r) {
	return 3.14 * r * r;
} 

int main() {
	int n = 3;
	char c = '#';
	cout << c << 5.5 << '-' << n << "hello" << true << endl;
	cout << "n + 5 = " << n + 5 << endl;
	cout << "면적은 " << area(n); 
}
