#include "Div.h"

void Div::setValue(int x, int y) {
	a = x;
	b = y;
}

int Div::calculate() {
	return a / b;
}