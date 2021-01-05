#ifndef EXP.H
#define EXP.H

class Exp {
	int base;
	int exp;
	public:
	Exp();
	Exp(int a, int b);
	Exp(int c);
	int getValue();
	int getBase();
	int getExp();
	bool equals(Exp b);
};

Exp::Exp() {
	base = 1; exp = 1;
}

Exp::Exp(int c) {
	base = c; exp = 1;
}

Exp::Exp(int a, int b) {
	base = a; exp = b;
}

int Exp::getValue() {
	return pow(base, exp);
}

int Exp::getBase() {
	return base;
}

int Exp::getExp() {
	return exp;
}

bool Exp::equals(Exp b) {
	if(getValue() == b.getValue()) {
		return true;
	}else {
		return false;
	}
}

#endif