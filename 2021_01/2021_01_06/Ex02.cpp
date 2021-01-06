#include <iostream>
#include <string>
using namespace std;

class Date {
	int year;
	int month;
	int day;
	public:
	Date(int y, int m, int d);
	Date(string a);
	void show();
	int getYear();
	int getMonth();
	int getDay();
};

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}

Date::Date(string a) {
	year = stoi(a.substr(0,4)); //substr 인덱스에서부터 길이만큼 잘라서 반환하는 함수
	month = stoi(a.substr(5,1)); // 5번째 인덱스에서부터 1길이만큼을 반환한다.
	day = stoi(a.substr(7,2));
}

void Date::show() {
	cout << year << "년" << month << "월" << day << "일" << endl;
}

int Date::getYear() {
	return year;
}

int Date::getMonth() {
	return month;
}

int Date::getDay() {
	return day;
}

int main() {
	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
}