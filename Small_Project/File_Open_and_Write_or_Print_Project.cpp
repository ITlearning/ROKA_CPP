// 간단한 프로젝트 01
// 파일을 열고, 수정하고, 출력까지 하는 프로그램
// 1.0.0 Ver.
// 수정한 텍스트는 바로바로 볼수가 있다.

// 문제점 : 아직 파일을 새롭게 생성하는 방법을 구축하지 못했다.
// 추후 해결점 : 파일 생성과 삭제, 또한 가지고 있는 파일들을 다 볼 수 있는 프로그램을 구상하겠다.
// CURD 형식의 너무나도 간단한 프로그램이다. 프로젝트라고도 말하기 힘든 것.
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	int c;
	char name[100];
	char text[30];
	char print[50];
	while(true) {
		cout << "파일 열기 : 1, 파일 수정하기 : 2, 파일 출력하기 : 3 >> ";
		cin >> c;
		switch(c) {
			case 1 : {
				ofstream fout("/workspace/ROKA_CPP/2021_02/2021_02_27/student.txt");
				if(!fout) {
					cout << name << "파일을 열 수 없습니다." << endl;
					break;
				}
				break;
			}
			case 2 : {
				ofstream fout("/workspace/ROKA_CPP/2021_02/2021_02_27/student.txt");
				cout << name << "에 저장할 것을 입력하세요." << endl;
				cout << ">> ";
				cin >> text;
				fout << text;
				fout.close();
				break;
			}	
			case 3 : {
				ifstream fin;
				fin.open("/workspace/ROKA_CPP/2021_02/2021_02_27/student.txt");
				if(!fin) {
				cout << "파일을 열 수 없습니다." << endl;
				break;
				}
				fin >> print;
				cout << print << endl;
				fin.close();
				break;
			}
			default :
				return 0;
		}
	}