// Book 클래스를 만들고 Book 객체를 스트림에 출력하는 << 연산자 작성
#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	string press;
	string author;
public:
	Book(string title ="", string press = "", string author = "") {
		this->title = title;
		this->press = press;
		this->author = author;
	}
	friend ostream& operator << (ostream& stream, Book b);
};

ostream& operator << (ostream& stream, Book b) {
	stream << b.title << "," << b.press << "," << b.author;
	return stream;
}

int main() {
	Book b("소유나 존재냐", "한국출판사", "에리히프롬");
	cout << b;
}