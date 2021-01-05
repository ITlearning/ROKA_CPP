#include<iostream>
#include<cstring>
using namespace std;

int main() 
{
	char buf[10000];
	int cnt[26] = {0, };
	int c;
	cin.getline(buf, 10000, ';');
	
	for(int i = 0; i < strlen(buf); i++) {
		if(isalpha(buf[i])) {
			if(int(buf[i]) >= 65 && int(buf[i]) <= 90) {
			buf[i] = tolower(buf[i]);
			}
			c++;
		}
		
	}
	
	for(int i = 0; i < strlen(buf); i++) {
		cnt[int(buf[i] - 97)]++;
	}
	
	cout << "총 알파벳 수 : " << c << endl;
	for(int i = 0; i < 26; i++) {
		cout << char(i + 97) << " (" << cnt[i] << ") \t: ";
		
		for(int j = 0; j < cnt[i]; j++) {
			cout << "*";
		}
		cout << endl;
	}
}














/*char c[10001];
	int cnt[26] = { 0, };
	cin.getline(c, 10000, ';');
	
	for (int i = 0; i < strlen(c); i++)
	{
		cnt[int(c[i])-97]++;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << char(i + 97) << " (" << cnt[i] << ")\t: ";
		for (int j = 0; j < cnt[i]; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	
*/

