// static 멤버를 가진 Math 클래스 작성

#include <iostream>
using namespace std;

class Math {
public:
	static int abs(int a) { return a>0?a:-a; }
	static int max(int a, int b) { return (a>b)?a:b; }
	static int min(int a, int b) { return (a>b)?b:a; }
};

int main() {
	cout << Math::abs(-5) << endl;
	cout << Math::max(10,8) << endl;
	cout << Math::min(-3, -8) << endl;
	// static멤버는 클래스에 각각 하나씩 밖에 없기에 main문에서 클래스 자체로 불러올 수가 있다.
}