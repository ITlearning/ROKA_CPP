#include <iostream>
using namespace std;

class SortedArray {
	int size;
	int *p;
	void sort();
public:
	SortedArray() { p = NULL; size = 0; }
	SortedArray(SortedArray& scr) {
		this->size = scr.size;
		this->p = new int [this->size];
		for(int i = 0; i < this->size; i++) {
			this->p[i] = scr.p[i];
		}
	}
	SortedArray(int p[], int size) {
		this->size = size;
		this->p = new int [size];
		for(int i = 0; i < size; i++) {
			this->p[i] = p[i];
		}
	}
	~SortedArray() { delete [] p; }
	SortedArray operator + (SortedArray& op2) {
		SortedArray tmp;
		tmp.size = this->size + op2.size;
		tmp.p = new int [tmp.size];
		for(int i = 0; i < tmp.size; i++) {
			if(i < this->size)
				tmp.p[i] = this->p[i];
			else
				tmp.p[i] = op2.p[i - (tmp.size - op2.size)];
		}
		
		return tmp;
	}
	SortedArray& operator = (const SortedArray& op2) {
		delete [] p;
		this->size = op2.size;
		this->p = new int [this->size];
		for(int i = 0; i < this->size; i++) {
			this->p[i] = op2.p[i];
		}
		return *this;
	}
	void show() {
		sort();
		cout << "배열 출력 : ";
		for(int i = 0; i < size; i++) {
			cout << p[i] << ' ';
		}
		cout << endl;
	}
};

void SortedArray::sort() {
	int swp;
	for(int i = 0; i < size; i++) {
		for(int j = i; j < size; j++) {
			if(p[i] > p[j] || p[i] == p[j]) {
				swp = p[i];
				p[i] = p[j];
				p[j] = swp;
			}
		}
	}
}

int main() {
	int n[] = { 2, 20, 6 };
	int m[] = { 10, 7, 8, 30 };
	SortedArray a(n,3), b(m,4), c;
	
	c = a + b;
	a.show();
	b.show();
	c.show();
}