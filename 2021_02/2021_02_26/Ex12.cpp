#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Product {
protected:
	string name;
	int count;
public:
	void setCount(int count) { this->count = count; }
	int getCount() { return count; }
	string getName() { return name; }
	bool eatCount(int count) {  
			if(this->count <= 0)
				return false;
			else 
				this->count -= count;
		return true;
	}
};

class Coffee : public Product {
public:
	Coffee() {
		name = "Coffee";
		count = 3;
	}
};

class Sugar : public Product {
public:
	Sugar() {
		name = "Sugar";
		count = 3;
	}
};

class CREAM : public Product {
public:
	CREAM() {
		name = "CREAM";
		count = 3;
	}
};

class Water : public Product {
public:
	Water() {
		name = "Water";
		count = 3;
	}
};

class Cup : public Product {
public:
	Cup() {
		name = "Cup";
		count = 3;
	}
};

class Machin {
	Product *p[5];
public:
	Machin() {
		cout << "***** 명품 커피 자판기켭니다 *****" << endl;
		p[0] = new Coffee();
		p[1] = new Sugar();
		p[2] = new CREAM();
		p[3] = new Water();
		p[4] = new Cup();
		printStats();
	}
	
	void printStats() {
		for(int i = 0; i < 5; i++) {
			cout << p[i]->getName() << '\t';
			for(int j = 0; j < p[i]->getCount(); j++)
				cout << "*";
			cout << endl;
		}
	}
	
	void start() {
		while(true) {
			int s = menu();
			if(s == 3) {
				for(int i = 0; i < 5; i++) {
					p[i]->setCount(3);
				}
				cout << "모든 통을 채웁니다." << endl;
				printStats();
				continue;
			} else if (s == 4) {
				cout << "프로그램을 종료합니다." << endl;
				exit(0);
			}
			
			if(p[0]->eatCount(1) == false) {
				cout << "재료가 부족합니다." << endl;
				printStats();
				continue;
			}
			if(p[3]->eatCount(1) == false) {
				cout << "재료가 부족합니다." << endl;
				printStats();
				continue;
			}
			
			if(p[4]->eatCount(1) == false) {
				cout << "재료가 부족합니다." << endl;
				printStats();
				continue;
			}
			
			switch(s) {
				case 0 : 
					if(p[2]->eatCount(1) == false) {
						cout << "재료가 부족합니다." << endl;
						printStats();
						continue;
					}
					
					cout << "맛있는 보통 커피 나왔습니다." << endl;
					printStats();
					break;
				case 1 :
					if(p[1]->eatCount(1) == false) {
						cout << "재료가 부족합니다." << endl;
						printStats();
						continue;
					}
					
					cout << "맛있는 설탕 커피 나왔습니다." << endl;
					printStats();
					break;
				case 2 :
					cout << "맛있는 블랙 커피 나왔습니다." << endl;
					printStats();
					break;
				default :
					cout << "잘못 입력하셨습니다." << endl;
					break;
				
			}
		}
	}
	
	int menu() {
		int num;
		cout << "보통 커피: 0, 설탕 커피: 1, 블랙 커피: 2, 채우기: 3, 종료 : 4 >> ";
		cin >> num;
		return num;
	}
};



int main() {
	cout.setf(ios::left);
	Machin m;
	m.start();
}