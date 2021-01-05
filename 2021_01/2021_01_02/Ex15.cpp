#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
	char d[100];
	int a = 0;
	char *b;
	int c;
	while(true) {
		cout << "? ";
		cin.getline(d, 100, '\n');
	
		a = atoi(strtok(d, " "));
		b = strtok(NULL, " ");
		c = atoi(strtok(NULL, " "));
	
		switch(*b) {
			case '+' : {
				cout << a << " + " << c << " = " << a + c << endl; break;
			}
			case '-' : {
				cout << a << " - " << c << " = " << a - c << endl; break;
			}
			case '*' : {
				cout << a << " * " << c << " = " << a * c << endl; break;
			}
			case '/' : {
				cout << a << " / " << c << " = " << a / c << endl; break;
			}
			case '%' : {
				cout << a << " % " << c << " = " << a % c << endl; break;
			}
			case '#' : {
				return 0;
			}
		}
	}
	
		
}