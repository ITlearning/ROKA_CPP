#include <iostream>
using namespace std;

class Dept {
	int size;
	int* scores;
public:
	Dept(int size) {
		this->size = size;
		scores = new int[size];
	}
	//Dept(const Dept& dept);
	~Dept();
	int getSize() { return size; }
	void show() { for(int i = 0; i < size; i++) cout << scores[i] << ' ';}
	void read();
	bool isOver60(int index);
};

/*Dept::Dept(const Dept& dept) {
	this->size = dept.size;
	this->scores = new int[dept.size];
	for(int i = 0; i < dept.size; i++) {
		this->scores[i] = dept.scores[i];
	}
}*/

Dept::~Dept() {
	delete [] scores;
}

void Dept::read() {
	cout << "10개 입력 >> ";
	for(int i = 0; i < size; i++) {
		int n;
		cin >> n;
		scores[i] = n;
	}
}

bool Dept::isOver60(int index) {
	if(60 < scores[index]) return true;
	else return false;
}

int countPass(Dept& dept) {
	int count = 0;
	for(int i = 0; i < dept.getSize(); i++) {
		if(dept.isOver60(i)) count++;
	}
	return count;
}

int main() {
	Dept com(10);
	com.read();
	com.show();
	cout << endl;
	int n = countPass(com);
	// 이 부분에서 복사 생성자가 실행된다.
	// 복사 생성자가 실행되면 컴파일러는 디폴트 복사 생성자를 호출하게 된다. 
	// 디폴트 복사생성자는 동적 할당을 취급하지 않는다. 따라서 에러가 나기 마련이다.
	// 그래서 countPass에 &를 추가해주어 디폴트 복사 생성자가 실행되지 않고, 값의 의한 호출로 인해 복사생성자가 호출 되기 떄문에 에러가 나지않고 정상적으로 프로그램이 실행된다.
	cout << "60점 이상은 " << n << "명" << endl;
}
