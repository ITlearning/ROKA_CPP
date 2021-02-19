#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Book {
	string Year;
	string BookName;
	string Writer;
public:
	Book(string Year = "", string BookName = "", string Writer = "") {
		this->Year = Year;
		this->BookName = BookName;
		this->Writer = Writer;
	}
	
	string getWriter() { return Writer; }
	string getBookName() { return BookName; }
	string getYear() { return Year; }
};

int main() {
	vector<Book> v;
	string year;
	string bookName;
	string writer;
	cout << "입고할 책을 입력하세요. 년도에 -1을 입력하면 입고를 종료합니다." << endl;
	while(true) {
		cout << "년도 >> ";
		getline(cin, year);
		if(year == "-1")
			break;
		cout << "책이름 >> ";
		getline(cin, bookName);
		cout << "저자 >> ";
		getline(cin, writer);
		v.push_back(Book(year,bookName,writer));
	}
	cout << "총 입고된 책은 " << v.size() << "권 입니다." << endl;
	cout << "검색하고자 하는 저자 이름을 입력하세요 >> ";
	cin >> writer;
	for(int i = 0; i < v.size(); i++) {
		if(v[i].getWriter() == writer)
			cout << v[i].getYear() << "년도, " << v[i].getBookName() << ", " << v[i].getWriter() << endl;
	}
	cout << "검색하고자 하는 년도를 입력하세요 >> ";
	cin >> year;
	for(int i = 0; i < v.size(); i++) {
		if(v[i].getYear() == year)
			cout << v[i].getYear() << "년도, " << v[i].getBookName() << ", " << v[i].getWriter() << endl;
	}
}