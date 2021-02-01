// 다른 클래스 전체를 프렌드로 선언

// * TIP : 프렌드를 선언하는 위치는 클래스 내에 private, public 영역 등 아무 위치에나 가능하다. * 

#include <iostream>
using namespace std;

class Rect;

class RectManager {
public:
	bool equals(Rect r, Rect s);
	void copy(Rect& dest, Rect& src);
};

class Rect {
	int width, height;
public:
	Rect(int width, int height) { this->width = width; this->height = height; }
	friend RectManager; // RectManager 클래스의 모든 함수를 프렌드 함수로 선언
};

bool RectManager::equals(Rect r, Rect s) {
	if(r.width == s.width && r.height == s.height) return true;
	else return false;
}

void RectManager::copy(Rect& dest, Rect& src) {
	dest.width = src.width; dest.height = src.height;
}

int main() {
	Rect a(3,4), b(5,6);
	RectManager man;
	
	man.copy(b,a); //a를 b에 복사한다.
	if(man.equals(a,b)) cout << "equal" << endl;
	else cout << "Not equal" << endl;
}