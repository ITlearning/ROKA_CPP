#include <iostream>
#include <string>
using namespace std;

int main() {
	string name;
	string add;
	int age;
	
	cout << "이름은? ";
	getline(cin,name, '\n');
	cout << "주소는? ";
	getline(cin, add, '\n');
	cout << "나이는? ";
	cin >> age;
	
	cout << name << ", " << add << ", " << age << endl;
}