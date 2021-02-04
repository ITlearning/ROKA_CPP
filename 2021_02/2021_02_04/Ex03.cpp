#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title ="", int price = 0, int pages = 0) {
		this->title = title;
		this->price = price;
		this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }
	friend bool operator!(Book& b);
};

bool operator!(Book& b) {
	if(b.price == 0) return true;
	else return false;
}

int main() {
	Book book("벼룩시장", 0, 50);
	if(!book) cout << "공짜다." << endl;
}