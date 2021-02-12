#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class GameObject {
protected:
	int distance; // 한 번 이동거리
	int x,y; // 현재 위치
public:
	GameObject(int startX, int startY, int distance) { // 초기 위치와 이동거리 설정
		this->x = startX; this->y = startY;
		this->distance = distance;
	}
	virtual ~GameObject() {}; // 가상 소멸자
	
	virtual void move() = 0; // 이동한 후 새로운 위치로 x,y 변경
	virtual char getShape() = 0; // 객체의 모양을 나타내는 문자 리턴
	
	int getX() { return x; }
	int getY() { return y; }
	bool collide(GameObject *p) { // 이 객체가 객체 p와 충돌했으면 true 리턴
		if(this->x == p->getX() && this->y == p->getY())
			return true;
		else
			return false;
	}
};

class Human : public GameObject {
	string m;
	bool t,f;
public:
	Human(int startX, int startY, int distance) : GameObject(startX, startY, distance) { t = false; f= false; }
	void move() {
		
		cout << "왼쪽(a), 아래(s), 위(d), 오른쪽(f) >> ";
		cin >> m;
		if(m == "a") {
			if(x <= 0) {
				x = 0;
			} else if (x >= 19) {
				x = 19;
			} else {
				x -= distance;
			}
		} else if( m == "s"){
			if(y <= 0) {
				y = 0;
			} else if (y >= 21) {
				y = 20;
			} else {
				y += distance;
			}
		} else if(m == "d") {
			if(x <= 0) {
				if(t == false) {
					x += distance;
					t = true;
				}else {
					x = 0;
				}
			} else if (x >= 19) {
				x = 19;
			} else {
				
			}
			
		} else if(m == "f") {
			if(y <= 0) {
				if(t == false) {
					y += distance;
					t = true;
				}else {
					y = 0;
				}
			} else if (y >= 19) {
				y = 19;
			} else {
				y -= distance;
			}
			
		}
	}
	
	char getShape() {
		return 'H';
	}
	
};

class Monster : public GameObject {
public:
	Monster(int startX, int startY, int distance) : GameObject(startX, startY, distance) {}
	void move() {
		srand((unsigned int)time(0));
		
		int num = rand() % 4;
		if(num == 0) {
			x -= distance;
		} else if(num == 1){
			y -= distance;
		} else if(num == 2) {
			x += distance;
		} else if(num == 3) {
			y += distance;
		}
	}

	char getShape() {
		return 'M';
	}
};

class Food : public GameObject {
	int cnt;
public:
	Food(int startX, int startY, int distance) : GameObject(startX, startY, distance) { cnt = 0; }
	void move() {
		
		if(cnt > 3) {
			if(cnt == 5) {
				cnt = 0;
			}else {
				int num = rand() % 4;
				if(num == 0) {
					x -= distance;
				} else if(num == 1){
					y -= distance;
				} else if(num == 2) {
					x += distance;
				} else if(num == 3) {
					y += distance;
				}
			}
				cnt++;
		}else {
			cnt++;
		}
	}
	
	char getShape() {
		return '@';
	}
};

int main() {
	int cnt = 0;
	Human H(0,0,1);
	Monster M(5,5,2);
	Food F(9,9,1);
	cout << "** Human의 Food 먹기 게임을 시작합니다. **" << '\n';
	int j = 0;
	string Game[10][20];
	for(int i = 0; i < 10; i++) {
		j = 0;
		for(; j < 20; j++){
			Game[i][j] = "-";
		}
	}
	Game[H.getX()][H.getY()] = H.getShape();
	Game[M.getX()][M.getY()] = M.getShape();
	Game[F.getX()][F.getY()] = F.getShape();
	while(true) {
		
		Game[H.getX()][H.getY()] = H.getShape();
		Game[M.getX()][M.getY()] = M.getShape();
		Game[F.getX()][F.getY()] = F.getShape();
		for(int i = 0; i < 10; i++) {
		j = 0;
		for(; j < 20; j++){
			cout << Game[i][j];
		}
		cout << '\n';
		}
		cout << '\n';
		int px = H.getX();
		int py = H.getY();
		int mx = M.getX();
		int my = M.getY();
		int fx = F.getX();
		int fy = F.getY();
		Game[px][py] = "-";
		Game[mx][my] = "-";
		Game[fx][fy] = "-";
		H.move();
		M.move();
		F.move();
		
	}
	

}