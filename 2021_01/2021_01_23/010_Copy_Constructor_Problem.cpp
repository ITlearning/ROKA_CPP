//얕은 복사 생성자를 사용하여 프로그램이 비정상 종료되는 경우


// 같은 주소를 가리키는 복사 생성자와 기존 생성자가 있다.
// 출력되고 같이 바뀌는건 문제가 없다.
// 하지만 소멸할때 먼저 소멸되고 난 뒤에 이미 반환한 메모리를 다시 반환하게 되므로
// 실행 시간 오류가 발생하고 프로그램이 비정상 종료하게 된다.

#include <iostream>
#include <cstring>
using namespace std;

class Person {
	char* name;
	int id;
public:
	Person(int id, const char* name);
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

int main() {
	Person father(1, "Kitae");
	Person daughter(father);
	
	cout << "daughter 객체 생성 직후 ----" << endl;
	
	father.show();
	daughter.show();
	daughter.changeName("Grace");
	cout << "daughter 이름을 Grace로 변경한 후 ----" << endl;
	father.show();
	daughter.show();
	
	return 0;
}