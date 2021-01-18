#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	public:
	Person() { name = " "; }
	void setName(string name) { this->name = name; }
	string getName() { return name; }
};


class Family {
	Person *p; //Person 배열 포인터
	int size;
	string name;
	public:
	Family(string name, int size) { 
		this->name = name;
		this->size = size;
		p = new Person [size]; 
	}
	void setName(int size, string name) {
		p[size].setName(name);
	}
	void show() {
		cout << name << "가족은 다음과 같이 " << size << "명 입니다." << endl; 
		for(int i = 0; i < size; i++) {
			cout << p[i].getName() << ' ';
		}
		cout << endl;
	}
	~Family() {}
};
int main() {
	Family *simpson = new Family("Simpson", 3);
	simpson->setName(0, "Mr. simpson");
	simpson->setName(1, "Mrs. simpson");
	simpson->setName(2, "Bart simpson");
	simpson->show();
	delete simpson;
	
}