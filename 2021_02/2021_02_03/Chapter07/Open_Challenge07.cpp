#include <iostream>
#include <string>
using namespace std;

class Histogram {
	string text;
	int len;
public:
	Histogram(string text) { this->text = text; }
	Histogram& operator << (char c);
	Histogram& operator << (string c);
	void show() { cout << text << endl; }
	void operator!();
};

Histogram& Histogram::operator << (string c) {
	text += c;
	return *this;
}


Histogram& Histogram::operator << (char c) {
	text += c;
	return *this;
}

void Histogram::operator!() {
	int alpha[26] = { 0 };
    int count=0;
    char c;
	for(int i = 0; i < text.size(); ++i) {
		c = text[i];
		if(isalpha(c) != 0) {
			c = tolower(text[i]);
			alpha[(int)c - 97]++;
			++count;
		}
	}
	
	cout << text << endl << endl;
	cout << "총 알파벳 수 " << count << endl;
	
	for(int i = 0; i < 26; ++i) {
		cout << (char)(i + 97) << ":";
		for(int j = 0; j < alpha[i]; ++j)
			cout << "*";
		cout << endl;
	}
	
	
}

int main() {
	Histogram song("Wise men say, \nonly fools rush in But I can't help, \n");
	song << "Falling" << "in love with you." << "- by ";
	song << 'k' << 'i' << 't';
	
	!song;
}
