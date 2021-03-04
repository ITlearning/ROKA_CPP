#include <iostream>
#include <string>
using namespace std;

class HardWareException {
	string step;
	string msg;
public:
	HardWareException(string step = "", string msg = "") {
		this->step = step;
		this->msg = msg;
	}
	string getStep() {
		return step;
	}
	string getMsg() {
		return msg;
	}
	void setMsg(string msg) {
		this->msg = msg;
	}
	void what() {
		cout << step;
	}
};

class CPU {
	string instruction;
	int op1, op2;
	string cmd;
	void fetch();
	void decode();
	void execute();
public:
	void run();
	
	static int stringToInt(string x);
};

void CPU::fetch() { // 명령어를 키보드로부터 읽어온다.
	cin >> cmd;
}

void CPU::decode() {
	
}