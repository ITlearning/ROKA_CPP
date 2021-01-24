//묵시적 복사 생성에 의해 복사 생성자가 자동 호출되는 경우

#include <iostream>
#include <cstring>
using namespace std;

class Person {
	char* name;
	int id;
public:
	Person(int id, const char* name); // 생성자
	Person(const Person& person); // 복사 생성자
	~Person();
	void changeName(const char* name);
	void show() { cout << id << ',' << name << endl; }
};

Person::Person(int id, const char* name) {
	this->id = id;
	int len = strlen(name);
	this->name = new char [len+1];
	strcpy(this->name, name);
}

Person::Person(const Person& person) { 
	this->id = person.id;   
	int len = strlen(person.name); 
	this->name = new char [len+1];
	strcpy(this->name, person.name);
	cout << "복사 생성자 실행, 원본 객체의 이름 " << this->name << endl;
}

Person::~Person() {
	if(name) {
		delete [] name;
	}
}

void Person::changeName(const char* name) {
	if(strlen(name) > strlen(this->name))
		return;
	strcpy(this->name, name);
}

void f(Person person) { // '값에 의한 호출' 로 객체가 전달될 때 , person 객체의 복사 생성자 호출
	person.changeName("dummy");
}

Person g() {
	Person mother(2, "Jane"); // 함수에서 객체를 리턴할 때, mother 객체의 복사본 생성, 복사본의 복사 생성자 호출
	return mother;
}

int main() {
	Person father(1, "Kitae"); 
	father.show();
	Person son = father; // 객체로 초기화하여 객체가 생성될 때, son 객체의 복사 생성자 호출
	son.show();
	g();
}