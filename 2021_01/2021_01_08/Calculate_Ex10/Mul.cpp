#include "Mul.h"

void Mul::setValue(int x, int y) {
	a = x;
	b = y;
}

int Mul::calculate() {
	return a * b;
}