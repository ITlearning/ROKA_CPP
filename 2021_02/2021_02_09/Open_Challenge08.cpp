#include <iostream>
#include <string>
using namespace std;

class Product {
	// 상품의 식별자 (id)
	// 상품설명, 생산자, 가격을 나타내는 정보 포함
	int id;
	string ex;
	string pro;
	string money;
public:
	
	Product();
	virtual void show() = 0;
	Product(int id, string ex, string pro, string money) { this->id = id; this->ex = ex; this->pro = pro; this->money = money; }
	int getId() { return id; }
	string getPro() { return pro; }
	string getEx() { return ex; }
	string getMoney() { return money; }
};

class Book : public Product {
	// ISBN 번호 , 저자, 책 제목 정보 포함
	string ISBN;
	string writer;
	string bookname;
public:
	Book();
	Book(int id, string ex, string pro, string money, string ISBN, string writer, string bookname) : Product(id, ex, pro, money) {
		this->ISBN = ISBN; this->writer = writer; this->bookname = bookname;
	}
	string getISBN() { return ISBN; }
	string getWriter() { return writer; }
	string getBookname() { return bookname; }
	
	void show() {
		cout << "---- 상품 ID : " << getId() << endl;
		cout << "상품 설명 : " << getEx() << endl;
		cout << "생산자 :" << getPro() << endl;
		cout << "가격 :" << getMoney() << endl;
		cout << "ISBN : " << ISBN << endl;
		cout << "책 제목 : " << bookname << endl;
		cout << "저자 : " << writer << endl;
	}
};

class CompactDisc : public Product {
	// 앨범 제목, 가수의 이름정보를 포함
	string albumName;
	string singer;
public:
	CompactDisc();
	CompactDisc(int id, string ex, string pro, string money,string albumName, string singer) : Product(id, ex, pro, money) {
		this->albumName = albumName;
		this->singer = singer;
	}
	string getAlbumName() { return albumName; }
	string getSinger() { return singer; }
	
	void show() {
		cout << "---- 상품 ID : " << getId() << endl;
		cout << "상품 설명 : " << getEx() << endl;
		cout << "생산자 :" << getPro() << endl;
		cout << "가격 :" << getMoney() << endl;
		cout << "앨범 제목 : " << albumName << endl;
		cout << "가수 : " << singer << endl;
	}
};

class ConversationBook : public Book {
	// 회화책에서 다루는 언어 명 정보를 포함
	string sub;
public:
	ConversationBook();
	ConversationBook(int id, string ex, string pro, string money, string sub,string ISBN, string writer, string bookname) : Book(id, ex, pro, money, ISBN, writer, bookname) {
		this->sub = sub;
	}
	string getSub() { return sub; }
	
	void show() {
		cout << "---- 상품 ID : " << getId() << endl;
		cout << "상품 설명 : " << getEx() << endl;
		cout << "생산자 :" << getPro() << endl;
		cout << "가격 :" << getMoney() << endl;
		cout << "ISBN : " << getISBN() << endl;
		cout << "책 제목 : " << getBookname() << endl;
		cout << "저자 : " << getWriter() << endl;
		cout << "언어 : " << sub << endl;
	}
};

int main() {
	Product *p[100];
	int id;
	string ex, pro, writer, bookname, albumName, singer, sub, money, ISBN;
	id = 0;
	
	cout << "***** 상품 관리 프로그램을 작동합니다 *****" << endl;
	while(true) {
		
		cout << "상품 추가(1), 모든 상품 조회(2), 끝내기(3) ? ";
		int button;
		cin >> button;
		
		if(button == 1) {
			if(id <= 100) {
			cout << "상품 종류 책(1), 음악CD(2), 회화책(3) ? ";
			cin >> button;
			cin.ignore();
				if(button == 1) {
					cout << "상품 설명 >> "; getline(cin, ex);
					cout << "생산자 >> "; getline(cin, pro);
					cout << "가격 >> "; getline(cin, money);
					cout << "ISBN >> "; getline(cin,ISBN);
					cout << "책 제목 >> "; getline(cin, bookname, '\n');
					cout << "저자 >> "; getline(cin, writer, '\n');
					Book *b = new Book(id, ex, pro,money,ISBN, writer, bookname);
					p[id] = b;
					++id;
				}
				else if(button == 2) {
					cout << "상품 설명 >> "; getline(cin, ex);
					cout << "생산자 >> "; getline(cin, pro);
					cout << "가격 >> "; getline(cin, money);
					cout << "앨범 제목 >> "; getline(cin, albumName);
					cout << "가수 >>"; getline(cin, singer);
					CompactDisc *c = new CompactDisc(id, ex, pro,money,albumName, singer);
					p[id] = c;
					++id;
				}
				else if(button == 3) {
					cout << "상품 설명 >> "; getline(cin, ex);
					cout << "생산자 >> "; getline(cin, pro);
					cout << "가격 >> "; getline(cin, money);
					cout << "ISBN >> "; getline(cin, ISBN);
					cout << "책 제목 >> "; getline(cin, bookname);
					cout << "저자 >> "; getline(cin, writer);
					cout << "언어 >>"; getline(cin, sub);
					ConversationBook *s = new ConversationBook(id, ex, pro,money, sub,ISBN, writer, bookname);
					p[id] = s;
					++id;
				}
				else {
					cout << "숫자 입력 오류";
				}
			}
		} else if(button == 2) {
			if(id == 0) {
				cout << "상품이 없습니다. " << endl;
			}	
			
			for(int i = 0; i < id; i++) {
				
				p[i]->show();
			}
		} else if (button == 3) {
			break;
		} else {
			cout << "다시 입력하세요" << endl;
		}
	}
}