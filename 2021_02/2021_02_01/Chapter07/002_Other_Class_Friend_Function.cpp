// 다른 클래스의 멤버 함수를 프렌드 함수로 선언
#include <iostream>
using namespace std;

class Rect; //먼저 참조하는 선언문.

class RectManager {
public:
	bool equals(Rect r, Rect s); // 요때 선언되는 Rect가 위에 선언하지 않았으면 컴파일 오류가 나기 때문에 위에 먼저 선언을 해준다.
};

class Rect {
	int width, height;
public:
	Rect(int width, int height) { this->width = width; this->height = height; }
	friend bool RectManager::equals(Rect r, Rect s); //프렌드 함수 선언
	// 이렇게 함으로써 Rect클래스의 모든 멤버를 자유롭게 접근 가능하다.
};

bool RectManager::equals(Rect r, Rect s) {
	if(r.width == s.width && r.height == s.height) return true;
	else return false;
}

int main() {
	Rect a(3,4) , b(3,4);
	RectManager man;
	
	if(man.equals(a,b)) cout << "equal" << endl;
	else cout << "Not equal" << endl;
}