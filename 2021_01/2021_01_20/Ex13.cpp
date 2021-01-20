#include <iostream>
#include <string>
using namespace std;

class Histogram {
	string text;
	int len;
public:
	Histogram(string text) { this->text = text; cout << text << endl; }
	void put(string text) { this->text += text; cout << text; }
	void putc(char a) { text += a; cout << a; }
	void print();
};

void Histogram::print() {
	cout << endl;
	
	int num = 0;
    int alphabet[26] = { 0 };
    for (int i = 0; i < text.length(); ++i) {
        if (isalpha(tolower(text[i])) != 0) {
            ++num;
            alphabet[(int)(tolower(text[i]) - 97)]++;
        }
    }
	
	cout << endl << endl;
	
	cout << "총 알파벳 수 " << num;
	cout << endl << endl;
	for (int i = 0; i < 26; ++i) {
        char c = 'a' + i;
        cout << c << " (" << alphabet[i] << ")\t: ";
        for (int j = 0; j < alphabet[i]; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
	Histogram elvis("Wise men say, only fools rush in But I Can't help, ");
	elvis.put("falling in love with you");
	elvis.putc('-');
	elvis.put("Elvis Presley");
	elvis.print();
}