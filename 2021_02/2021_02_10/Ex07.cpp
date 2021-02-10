#include <iostream>
#include <string>
using namespace std;

class BaseMemory {
	char *mem;
protected:
	BaseMemory(int size) { mem = new char [size]; }
	void setIndex(int a, char m) { mem[a] = m; }
	char getMem(int s) { return mem[s]; }
	void setMem(char x[], int s) {
		for(int i = 0; i < s; ++i) {
			mem[i] = x[i];
		}
	}
};

class ROM : virtual public BaseMemory {
	int f;
	char *bob;
public:
	ROM(int size, char x[], int f) : BaseMemory(size) { 
		setMem(x,f);
	}
	char read(int i) {
		return getMem(i);
	}
	
};

class RAM : virtual public BaseMemory {
	int g;
public:
	RAM(int size) : BaseMemory(size) {}
	void write(int i, char x) { setIndex(i, x); }
	char read(int i) {
		return getMem(i);
	}
};

int main() {
	char x[5] = {'h','e','l','l','o'};
	ROM biosROM(1024*10, x, 5);
	RAM mainMemory(1024*1024);
	
	for(int i = 0; i< 5; ++i) mainMemory.write(i, biosROM.read(i));
	for(int i = 0; i< 5; ++i) cout << mainMemory.read(i);

}
