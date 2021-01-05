#include<iostream>
#include<cstring>
using namespace std;

int main() 
{
	char c[10001];
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
	
	


}
