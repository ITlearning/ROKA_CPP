#include <iostream>
#include <string>
using namespace std;

class Matrix {
	int n1,n2,n3,n4;
public:
	Matrix(int n1 = 0,int n2 = 0,int n3 = 0,int n4 = 0) { this->n1 = n1; this->n2 = n2; this->n3 = n3; this->n4 = n4; }
	void show() { cout << "Matrix = { " << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << " }" << endl; }
	
	friend Matrix operator + (Matrix op1, Matrix op2);
	friend bool operator == (Matrix op1, Matrix op2);
	Matrix& operator += (Matrix op1);
};

Matrix operator+ (Matrix op1, Matrix op2) {
	Matrix tmp;
	tmp.n1 = op1.n1 + op2.n1;
	tmp.n2 = op1.n2 + op2.n2;
	tmp.n3 = op1.n3 + op2.n3;
	tmp.n4 = op1.n4 + op2.n4;
	
	return tmp;
}

bool operator == (Matrix op1, Matrix op2) {
	if(op1.n1 == op2.n1 && op1.n2 == op2.n2 && op1.n3 == op2.n3 && op1.n4 == op2.n4) return true;
	else return false;
}

Matrix& Matrix::operator += (Matrix op1) {
	n1 = n1 + op1.n1;
	n2 = n2 + op1.n2;
	n3 = n3 + op1.n3;
	n4 = n4 + op1.n4;
	return *this;
}

int main() {
	Matrix a(1,2,3,4), b(2,3,4,5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if(a == c) 
		cout << "a and c are the same." << endl;
}