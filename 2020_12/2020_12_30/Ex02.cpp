#include <iostream>
using namespace std;

int main(){
	int sum = 0;
	for(int i = 1; i < 10; i++) {
		for(int j = 1; j < 10; j++) {
			sum = j * i;
			cout << j << "x" << i << "=" << sum << "\t";
		}
		cout << endl;
	}
	
	return 0;
}