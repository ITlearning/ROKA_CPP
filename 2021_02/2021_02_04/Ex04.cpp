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
	
	friend bool operator < (string b, Book& a);
};

bool operator < (string b, Book& a) {
	if(b < a.title) return true;
	else return false;
}

int main() {
	Book a("청춘", 20000, 300);
	string b;
	cout << "책 이름을 입력하세요 >> ";
	getline(cin, b);
	if(b < a)
		cout << a.getTitle() << "이 " << b << "보다 뒤에 있구나!" << endl;
}