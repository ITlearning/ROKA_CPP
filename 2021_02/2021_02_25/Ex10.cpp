#include <iostream>
#include <string>
using namespace std;

istream& prompt(istream& ins) {
	cout << "암호? ";
	return ins;
}

int main() {
	string password;
	while(true) {
		cin >> prompt >> password;
		if(password == "C++"){
			cout << "Login Success!" << endl;
			break;
		} else {
			cout  << "Login Fail." << endl;
		}
	}
}