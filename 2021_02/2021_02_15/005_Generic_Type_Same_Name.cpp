// 제레릭 함수와 이름이 같은 중복 함수 작성
#include <iostream>
using namespace std;

template <class T>
void print(T array[], int n) {
	for(int i = 0; i < n; i++)
		cout << array[i] << '\t';
	cout << endl;
}

void print(char array[], int n = 5) { // 템플릿 함수와 동일한 이름의 중복 함수 // 템플릿에서 함수 선언에 디폴트 매개 변수를 사용할 수 있다.
	for(int i = 0; i < n; i++)
		cout << (int)array[i] << '\t'; // array[i]를 int 타입으로 변환하여 정수 출력
	cout << endl;
}

int main() {
	int x[] = {1,2,3,4,5};
	double d[5] = {1.1,2.2,3.3,4.4,5.5};
	print(x,5);
	print(d,5);
	
	char c[5] = {1,2,3,4,5};
	print(c,5); // 5를 지우고 컴파일해도 디폴트 매개 변수에 의해 컴파일이 진행되고 출력된다.
}