#include <iostream>
using namespace std;

class Container {
	int size;
	public:
	Container() { size = 10; }
	void fill() { //최대량(10)으로 채우기
		size = 10;
	}
	
	void consume() { // 1 만큼 소모하기
		size--;
	}
	
	int getSize() { //현재 크기 리턴
		return size;
	}
};

class CoffeeVendingMachine {
	Container tong[3];  // tong[0] = 커피, tong[1] = 물, tong[2] = 설탕통을 나타냄 
	void fill() { // 3개의 통을 모두 10으로 채움
		for(int i = 0; i < 3; i++) {
			tong[i].fill();
		}
	}
	
	void selectEspresso() { //커피 1 물 1 소모
		if(tong[0].getSize() <= 0 || tong[1].getSize() <= 0 || tong[2].getSize() <= 0){
			cout << "원료가 부족합니다." << endl;
		}else {
			cout << "에스프레소 드세요." << endl;
			tong[0].consume();
			tong[1].consume();
		}
		
		
		
		
	}
	
	void selectAmericano() { //커피 1 물 2 소모
		if(tong[0].getSize() <= 0 || tong[1].getSize() <= 0 || tong[2].getSize() <= 0){
			cout << "원료가 부족합니다." << endl;
		}else {
			cout << "아메리카노 드세요." << endl;
			tong[0].consume();
			
			tong[1].consume();
			tong[1].consume();
		}
	}
	
	void selectSugarCoffee() { //커피 1 물 2 설탕 1 소모
		if(tong[0].getSize() <= 0 || tong[1].getSize() <= 0 || tong[2].getSize() <= 0){
			cout << "원료가 부족합니다." << endl;
		}else {
			cout << "설탕커피 드세요." << endl;
			tong[0].consume();
			
			tong[1].consume();
			tong[1].consume();
			
			tong[2].consume();
		}
	}
	
	void show() { //현재 커피 물 설탕 잔량)
		cout << "커피 : " << tong[0].getSize() << ' ';
		cout << "물 : " << tong[1].getSize() << ' ';
		cout << "설탕 : " << tong[2].getSize() << endl;
	}
	
	public:
	void run() { //커피 자판기 작동
		int num;
		cout << "커피자판기를 작동합니다. " << endl;
		
		while(true) {
			cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기) >> ";
			cin >> num;
			switch(num) {
				case 1 : {
					
					selectEspresso();
					break;
				}
				case 2 : {
					
					selectAmericano();
					break;
				}
				case 3 : {
					
					selectSugarCoffee();
					break;
				}
				case 4 : {
					show();
					break;
				}
				case 5 : {
					fill();
					break;
				}
				case 6 : {
					return;
				}
			}
		}
	}
};



int main() {
	CoffeeVendingMachine c;
	
	c.run();
}