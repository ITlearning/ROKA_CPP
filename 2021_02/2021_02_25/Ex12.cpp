#include <iostream>
#include <string>
using namespace std;

class Coffee {
	string CoffeeName;
	int size;
	int cup;
	int water;
public:
	Coffee(string CoffeeName = "", int size = 3) {
		this->CoffeeName = CoffeeName;
		this->size = size;
		cup = 3;
		water = 3;
	}
	
	void printNo() {
		cout << "Water" << '\t';
		for(int i = 0; i < water; i++) {
			cout << "*";
		}
		cout << endl;
		cout << "Cup" << '\t';
		for(int i = 0; i< cup; i++) {
			cout << "*";
		}
		cout << endl;
	}
	void setSize() { size--; cup--; water--;}
	void fillAll() { size = 3; cup = 3; water = 3; }
	int getWater() { return water;}
	int getSize() { return size; }
	int getCup() { return cup; }
	string getName() { return CoffeeName; }
};

class Nomal : public Coffee {
	int cream;
public:
	Nomal(string name = "Coffee", int size = 3) : Coffee(name,size) {
		cream = 3;
	}
	
	void eat() {
		setSize();
		cream--;
	}
	void fill() {
		fillAll();
		cream = 3;
	}
	void print() {
		cout << getName() << '\t';
		for(int i = 0; i < getSize(); i++) {
			cout << "*";
		}
		cout << endl;
		cout << "Cream" << '\t';
		for(int i = 0; i < cream; i++) {
			cout << "*";
		}
		cout << endl;
		printNo();
	}
};

class Black : public Coffee {
	
public:
	Black(string name = "Balck", int size = 3) : Coffee(name, size) {}
	
	void eat() {
		setSize();
	}
	
	void fill() {
		fillAll();
	}
	
	void print() {
		cout << getName() << '\t';
		for(int i = 0; i < getSize(); i++) {
			cout << "*";
		}
		cout << endl;
		printNo();
	}
};

class Sugar : public Coffee {
	int sugar;
public:
	Sugar(string name = "Sugar", int size = 3) : Coffee(name, size) {
		sugar = 3;
	}
	
	void fill() {
		fillAll();
		sugar = 3;
	}
	
	void eat() {
		setSize();
		sugar--;
	}
	void print() {
		cout << getName() << '\t';
		for(int i = 0; i < getSize(); i++) {
			cout << "*";
		}
		cout << endl;
		printNo();
	}
};

void start() {
	cout << "------ 명품 커피 자판기입니다. ------" << endl;
}

int menu() {
	int num;
	cout << "보통 커피:0, 설탕 커피:1, 블랙 커피:2, 채우기:3, 종료:4 >> ";
	cin >> num;
	
	return num;
}


int main() {
	string name;
	int size;
	Nomal n;
	Sugar s;
	Black b;
	bool t = true;
	start();
	while(t) {
		
		n.print();
		s.print();
		b.print();
		int num = menu();
		if(num == 0) {
			n.eat();
		} else if(num == 1) {
			s.eat();
		} else if (num == 2) {
			b.eat();
		} else if (num == 3) {
			n.fill();
			s.fill();
			b.fill();
		} else if (num == 4) {
			break;
		}
	}
	

	
	
}