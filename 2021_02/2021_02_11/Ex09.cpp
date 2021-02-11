#include <iostream>
#include <string>
using namespace std;

class Consol {
public:
	static void start();
	static int menu();
	static int time();
	static int num();
	static string name();
};

void Consol::start() {
	cout << "***** 한성 항공에 오신것을 환영합니다. *****" << endl; 
}

int Consol::menu() {
	cout << endl << endl;
	cout << "예약:1, 취소:2, 보기:3, 끝내기 4>> ";
	int n;
	cin >> n;
	return n;
}

int Consol::time() {
	cout << "07시 :1, 12시:2, 17시:3 >> ";
	int t;
	cin >> t;
	return t;
}

int Consol::num() {
	cout << "좌석 번호 >> ";
	int i;
	cin >> i;
	return i;
}

string Consol::name() {
	cout << "이름 입력 >> ";
	string n;
	cin >> n;
	return n;
}

class Seat {
	string seatName;
public:
	Seat() { seatName = "---"; }
	string getseatName() { return seatName; }
	void setName(string seatName) { this->seatName = seatName; }
};

class Schedule {
	Seat *seat;
	string time;
public:
	Schedule() { seat = new Seat[8]; }
	~Schedule() {delete[] seat; }
	void setTime(string t) { time = t; }
	void show() {
		cout << time << " :";
		for(int i = 0; i < 8; ++i)
			cout << seat[i].getseatName() << "\t";
		cout << endl;
	}
	void reservationSeat(int num, string name) {
		seat[num - 1].setName(name);
	}
	
	void cancleSeat(int num, string name) {
		seat[num - 1].setName("---");
	}
};

class Air {
	Schedule *sch;
public:
	Air() {
		sch = new Schedule [3];
		sch[0].setTime("07시");
		sch[1].setTime("12시");
		sch[2].setTime("17시");
	}
	~Air() { delete[] sch; }
	void reservation(int t) {
		sch[t-1].show();
		int num = Consol::num();
		string name = Consol::name();
		sch[t-1].reservationSeat(num,name);
	}
	void cancle(int t) {
		sch[t-1].show();
		int num = Consol::num();
		string name = Consol::name();
		sch[t-1].cancleSeat(num, name);
	}
	void showAll() {
		for(int i = 0; i< 3; ++i) {
			sch[i].show();
		}
	}
};

int main() {
	Air air;
	Consol::start();
	while(true) {
		int n = Consol::menu();
		if(n == 1) {
			int t = Consol::time();
			air.reservation(t);
		}
		else if(n == 2) {
			int t = Consol::time();
			air.cancle(t);
		}
		else if(n ==3) {
			air.showAll();
		}
		else if(n == 4) {
			cout << "예약 시스템을 종료합니다." << endl;
			break;
		}else {
			break;
		}
	}
}