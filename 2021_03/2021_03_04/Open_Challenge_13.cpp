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
		cout << step << "스탭, " << msg << endl;
	}
};

class CPU {
protected:
		
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
	cin >> cmd >> op1 >> op2;
}

void CPU::decode() { //명령어 코드가 무엇인지 판별 
	if(cmd == "ADD") {
		instruction = cmd;
	} else if (cmd == "SUB") {
		instruction = cmd;
	} else if (cmd == "MUL") {
		instruction = cmd;
	} else if (cmd == "DIV") {
		instruction = cmd;
	} else if(cmd == " "){
		cmd = "Empty";
	} else {
		cmd = "NULL";
	}
}

void CPU::execute() { // 명령어 코드에 따라 명령 실행 
	if(instruction == "ADD") {
		cout << instruction << ' ' << op1 << ' ' << op2 << ": \t" << op1 + op2 << endl;
	} else if (instruction == "SUB") {
		cout << instruction << ' ' << op1 << ' ' << op2 << ": \t" << op1 - op2 << endl;
	} else if (instruction == "MUL") {
		cout << instruction << ' ' << op1 << ' ' << op2 << ": \t" << op1 * op2 << endl;
	} else if (instruction == "DIV") {
		cout << instruction << ' ' << op1 << ' ' << op2 << ": \t" << op1 / op2 << endl;
	}
}

void CPU::run() {
	while(true) {
		try {
			fetch();
			decode();
			if(cmd != "ADD" && cmd != "SUB" && cmd != "MUL" && cmd != "DIV") {
				if(cmd == "NULL") {
					throw HardWareException("decode", "invalid 명령어 예외");
				} else if (cmd == "Empty") {
					throw HardWareException("fetch", "명령 라인 없음");
				}	
			}
			execute();
			if(op2 == 0) {
				throw HardWareException("decode", "0으로 나누는 예외");
			} else if (op2 <= 0) {
				
			} 
		}
	}
}
