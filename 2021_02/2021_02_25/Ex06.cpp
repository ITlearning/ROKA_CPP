#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void showNum(const double &num) {
	cout << setw(15) << setfill('_') << num;
}

void showSqrt(const double &num) {
	cout << setprecision(3) << setw(15) << setfill('_') << sqrt(num) << endl;
}

int main() {
	cout.setf(ios::left);
	cout << setw(15) << "Number";
	cout << setw(15) << "Square";
	cout << setw(15) << "Square Root" << endl;
	
	for(double i = 0; i < 50; i += 5) {
		cout.precision(4);
		showNum(i);
		showNum(i*i);
		showSqrt(i);
	}
}