#include <iostream>
#include <string>
using namespace std;
class Circle {
    int radius; // 원의 반지름 값
    string name; // 원의 이름
public:
    void setCircle(string name, int radius); //이름과 반지름 설정
    double getArea();
    string getName();
};
void Circle::setCircle(string name, int radius) {
    this->name = name;
    this->radius = radius;
}
double Circle::getArea() { //면적구하기
    return radius*radius*3.14;
}
string Circle::getName() {
    return name;
}
class CircleManger {
    Circle *p;
    int size;
public:
    CircleManger(int size); //size 크기의 배열을 동적 생성. 사용자로부터 입력 완료
    ~CircleManger();
    void searchByName(); // 사용자로부터 원의 이름을 입력받아 면적 출력
    void searchByArea(); // 사용자로부터 면적을 입력받아 면적보다 큰 원의 이름 출력
};
CircleManger::CircleManger(int size) { //size 크기의 배열을 동적 생성.
    this->size = size;
    this->p = new Circle[size];//객체 배열의 동적 생성
    string name;
    int radius;
    for (int i = 0; i < size; ++i) {
        cout << "원 " << i + 1 << "의 이름과 반지름 >> ";
        cin >> name >> radius;
        p[i].setCircle(name, radius);
    }
}
CircleManger::~CircleManger() {
    delete[] p;
}
void CircleManger::searchByName() { // 사용자로부터 원의 이름을 입력받아 면적 출력
    cout << "검색하고자 하는 원이 이름 >> ";
    string name;
    cin >> name;
    for (int i = 0; i < this->size; ++i) {
        if (name.compare(p[i].getName()) == 0) {
            cout << name << "의 면적은" << p[i].getArea() << endl;
            break;
        }
    }
}
void CircleManger::searchByArea() { // 사용자로부터 면적을 입력받아 면적보다 큰 원의 이름 출력
    cout << "최소 면적을 정수로 입력하세요 >> ";
    int area;
    cin >> area;
    for (int i = 0; i < this->size; ++i) {
        if (area < p[i].getArea()) {
            cout << p[i].getName() << "의 면적은," << p[i].getArea();
        }
    }
}
int main() {
    int num;
    cout << "원의 개수 >> ";
    cin >> num;
    CircleManger circle(num);
    circle.searchByName();
    circle.searchByArea();
}