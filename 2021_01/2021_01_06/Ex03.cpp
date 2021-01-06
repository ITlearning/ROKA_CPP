#include <iostream>
#include <string>
using namespace std;

class Account {
	string name;
	int number;
	int cash;
	public:
	Account(string n, int m, int c);
	void deposit(int money);
	int withdraw(int dis);
	string getOwner();
	int inquiry();
};

Account::Account(string n, int m, int c) {
	name = n;
	number = m;
	cash = c;
}

void Account::deposit(int money) {
	cash += money;
}

int Account::withdraw(int dis) {
	cash -= dis;
	return dis;
}

string Account::getOwner() {
	return name;
}

int Account::inquiry() {
	return cash;
}

int main() {
	Account a("Kitae", 1, 5000);
	a.deposit(50000);
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
	int money = a.withdraw(20000);
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
	
	cout << money << endl;
}