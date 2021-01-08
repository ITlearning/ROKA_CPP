#include "Add.h"

void Add::setValue(int x, int y) {
	a = x;
	b = y;
}

int Add::calculate() {
	return a + b;
}