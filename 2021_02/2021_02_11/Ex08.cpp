#include <iostream>
#include <string>
using namespace std;

class Printer {
	int Printcnt; //인쇄 매수
	int availableCount; // 인쇄 종이 잔량
	string ModelName; // 모델명
	string Manufacter; // 제조사
public:
	Printer(int Printcnt = 0, int availableCount = 0, string ModelName = "", string Manufacter = "") {
		this->Printcnt = Printcnt;
		this->availableCount = availableCount;
		this->ModelName = ModelName;
		this->Manufacter = Manufacter;
	}
	~Printer() {}
	void print(int pages) {
		Printcnt = pages;
		if(Printcnt > availableCount) {
			cout << "용지가 없어서 프린트 할 수 없습니다." << endl;
		}else {
			cout << "프린트 했습니다" << endl;
			availableCount -= Printcnt;
		}
			
		
	}
	int getPrintcnt() { return Printcnt; }
	int getAvailableCount() { return availableCount; }
	string getModelName() { return ModelName; }
	string getManufacter() { return Manufacter; }
};

class InkJet : public Printer {
	int availableInk;
public:
	InkJet(int Printcnt = 0, int availableCount = 0, string ModelName = "", string Manufacter = "", int availableInk = 0) : Printer(Printcnt, availableCount, ModelName, Manufacter) {
		this->availableInk = availableInk;
	}
	~InkJet() {}
	void printInkJet(int pages) {
		if(this->availableInk > 0) {
			print(pages);
			availableInk -= pages;
		}
	}
	int getAvailableInk() { return availableInk; }
};

class Toner : public Printer {
	int availableToner;
public:
	Toner(int Printcnt = 0, int availableCount = 0, string ModelName = "", string Manufacter = "", int availableToner = 0) : Printer(Printcnt, availableCount, ModelName, Manufacter) {
		this->availableToner = availableToner;
	}
	~Toner() {}
	void printToner(int pages) {
		
		if(this->availableToner > 0) {
			print(pages);
			this->availableToner -= pages;
		}
	}
	int getAvailableToner() { return availableToner; }
};

int main() {
	int select, pages;
	string button;
	InkJet ink(0,5,"Office V40", "HP", 10);
	Toner to(0, 3, "SCX-6x45","삼성전자", 20);
	cout << "현재 작동중인 2대의 프린터는 아래와 같다." << endl;
	while(true) {
		cout << "잉크젯 : " << ink.getModelName() << " ," << ink.getManufacter() << " , 남은종이 : " << ink.getAvailableCount() << " , 남은 잉크 : " << ink.getAvailableInk() << endl;
		cout << "레이저 : " <<  to.getModelName() << " ," << to.getManufacter() << " , 남은종이 : " << to.getAvailableCount() << " , 남은 토너 : " << to.getAvailableToner() << endl;
		cout << endl << endl;
		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력 >> ";
		cin >> select >> pages;
		if(select == 1) {
			ink.printInkJet(pages);
		} else if (select == 2) {
			to.printToner(pages);
		} else {
			cout << "다시 입력해주세요." << endl;
		}
		
		
		cout << "잉크젯 : " << ink.getModelName() << " ," << ink.getManufacter() << " , 남은종이 : " << ink.getAvailableCount() << " , 남은 잉크 : " << ink.getAvailableInk() << endl;
		cout << "레이저 : " <<  to.getModelName() << " ," << to.getManufacter() << " , 남은종이 : " << to.getAvailableCount() << " , 남은 토너 : " << to.getAvailableToner() << endl;
		cout << "계속 프린트 하시겠습니까?(y/n) >> ";
		cin >> button;
		if(button == "n")
			break;
		else if (button != "y" && button != "n") {
			cout << "입력이 올바르지 않습니다. 종료합니다." << endl;
			break;
		}
	}
		
}