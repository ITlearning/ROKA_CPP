#include <iostream>
#include <string>
using namespace std;

class Phone {
	string name;
	string telnum;
	string add;
public:
	Phone(string name = "", string telnum = "", string add = "") {
		this->name = name;
		this->telnum = telnum;
		this->add = add;
	}
	friend istream& operator >> (istream& ins, Phone &p);
	friend ostream& operator << (ostream& stream, Phone p);
};

istream& operator >> (istream& ins, Phone &p) {
	cout << "이름 : ";
	getline(ins, p.name);
	cout << "전화번호 : ";
	getline(ins, p.telnum);
	cout << "주소 : ";
	getline(ins, p.add);
	return ins;
}

ostream& operator << (ostream& stream, Phone p) {
	cout << "(" << p.name << ',' << p.telnum << ',' << p.add << ")";
	return stream;
}

int main() {
	Phone girl, boy;
	cin >> girl >> boy;
	cout << girl << boy << endl;
}