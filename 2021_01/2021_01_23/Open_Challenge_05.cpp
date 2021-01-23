#include <iostream>
#include <string>
using namespace std;

class Morse {
	string alphabet[26];
	string digit[10];
	string slash, question, comma, period, plus, equal;
public:
	Morse();
	void text2Morse(string text, string& morse);
	void morse2Text(string morse, string& text);
};

Morse::Morse() {
	string alphamorse[26] = { ".-", "-...", "-.-.", "-..", ".",
							 "..-.", "--.", "....", "..", ".---",
							 "-.-", ".-..", "--", "-.", "---",
							 ".--.", "--.-", ".-.", "...", "-",
							 "..-", "...-", ".--", "-..-", "-.--", "--.."};
	string digitmorse[10] = { "-----", ".----", "..---", "...--", "....-",
							".....", "-....", "--...", "---..", "----." };
	
	for(i=0; i<26; i++)
		alphabet[i] = alphamorse[i];
	for(i=0; i<10; i++)
		digit[i] = digitmorse[i];
	
	slash = "-..-.";
	question = "..--..";
	comma = "--..--";
	period = ".-.-.-";
	plus = ".-.-.";
	equal = "-...-";
}

void Morse::text2Morse(string text, string& morse) {
	for(int i = 0; i < text.size(); i++) {
		morse[i] = alphabet[((text[i]) - 97)];
	}
}

void morse2Text(string morse, string &text) {
	
}

int main() {
	Morse m;
	string text;
	string morse;
	cout << "입력 : " ;
	getline(cin, text, '\n');
	m.text2Morse(text, morse);
	
	cout << morse << endl;
}