#include <iostream>
#include "Box.h"
using namespace std;
Box::Box(int w, int h) {
	setSize(w,h);
	fill = '*';
}

void Box::setFill(char f) {
	fill = f;
}

void Box::setSize(int w, int h) {
	width = w;
	height = h;
}

void Box::draw() {
	for(int i = 0; i < height; i++) {
		for(int m = 0; m < width; m++) {
			cout << fill;
		}
		cout << endl;
	}
}