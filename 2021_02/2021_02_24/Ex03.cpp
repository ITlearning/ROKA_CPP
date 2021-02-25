#include <iostream>
using namespace std;
    
int main() {
    int a;
    cin.ignore(100,';');
	while((a = cin.get()) != EOF)  {
		cout.put(a);
		if(a == '\n') {
			cin.ignore(100,';');
		}
			
	}
}


/*

*/