// 보류. 진행중.

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

class decodeException : public HardWareException {
public:
	decodeException(string step = "", string msg = "") : HardWareException(step, msg) {
		setMsg("invalid 명령어 예외");
	}
};

class fetchException : public HardWareException {
public:
	fetchException(string step = "", string msg = "") : HardWareException(step, msg) {
		setMsg("명령 라인 없음");
	}
};

class UnException : public HardWareException {
public:
	UnException(string step = "", string msg = "") : HardWareException(step, msg) {
		setMsg("피연산자 제외");
	}
};

class ZeroException : public HardWareException {
public:
	ZeroException(string step = "", string msg = "") : HardWareException(step, msg) {
		setMsg("0으로 나누는 예외");
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
	
	static int stringToInt(string x) { return stoi(x); }
};

void CPU::fetch() { // 명령어를 키보드로부터 읽어온다.
	string a,b;
	getline(cin, cmd, '\n');
	if(cmd.size() == 0) {
		return;
	}else if (cmd.size() != 3) {
		return;
	}
	cin >> a >> b;
	if(a.size() == 0 || b.size() == 0) {
		instruction = "Zero";
		return;
	}
	if(cin.fail()) {
		
	}
	op1 = stringToInt(a);
	op2 = stringToInt(b);
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
	} else {
		return;
	}
}

void CPU::execute() { // 명령어 코드에 따라 명령 실행 
	if(instruction == "ADD") {
		cout << '\t' << instruction << ' ' << op1 << ' ' << op2 << ": \t" << op1 + op2 << endl;
	} else if (instruction == "SUB") {
		cout << '\t' << instruction << ' ' << op1 << ' ' << op2 << ": \t" << op1 - op2 << endl;
	} else if (instruction == "MUL") {
		cout << '\t' << instruction << ' ' << op1 << ' ' << op2 << ": \t" << op1 * op2 << endl;
	} else if (instruction == "DIV") {
		cout << '\t' << instruction << ' ' << op1 << ' ' << op2 << ": \t" << op1 / op2 << endl;
	} else if (instruction == "Zero") {
		cmd = "Zero";
	}
}

void CPU::run() {
	while(true) {
		try {
			fetch();
			decode();
				if(cmd != "ADD" && cmd != "SUB" && cmd != "MUL" && cmd != "DIV") {
					if(cmd.size() != 3) {
						if (cmd.size() == 0) {
						throw fetchException("fetch");
					}	else if (cmd == "Zero") {
						throw ZeroException("decode");
					}	
						throw decodeException("decode");
				}
			} 
			execute();
		}
		catch(HardWareException &d) {
			d.what();
		}
	}
}


int main() {
	CPU cpu;
	cpu.run();
}