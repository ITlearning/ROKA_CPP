#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius, string name) {
		this->radius = radius;
		this->name = name;
	}
	double getArea() { return 3.14 * radius * radius; }
	string getName() { return name; }
};

void start() {
	cout << "원을 삽입하고 삭제하는 프로그램입니다." << endl;
}

int menu() {
	int num;
	cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
	cin >> num;
	return num;
}

int main() {
	vector<Circle*> v;
	bool sw = true;
	start();
	string name;
	int radius;
	while(sw) {
		int n = menu();
			if(n == 1) {
				cout << "생성하고자 하는 원의 반지름과 이름은 >> ";
				
				cin >> radius >> name;
				v.push_back(new Circle(radius, name));
			} else if (n == 2) {
				cout << "삭제하고자 하는 원의 이름은 >> ";
                cin >> name;
                vector<Circle*>::iterator it = v.begin();
                while(it != v.end()){
                    Circle *p = *it;
                    if(p->getName() == name){
                        it = v.erase(it);
                        delete p;
                    }
                    else
                        it++;
                }
			} else if (n == 3) {
				vector<Circle*>::iterator it;
                for(it=v.begin(); it!=v.end(); it++){
                    Circle *p = *it;
                    cout << p->getName() << endl;
                }
                cout << endl;
			} else if (n == 4) {
				sw = false;
			} else {
				sw = false;
			}
	}
}