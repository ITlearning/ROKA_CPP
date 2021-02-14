#include <iostream>
#include <string>
using namespace std;

class Shape {
	Shape* next;
protected:
	Shape() { next = NULL; }
}