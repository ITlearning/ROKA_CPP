// 블록체인의 증명 과정인 작업증명(PoW - Proof of Work)을 C++로 구현하기

// PoW 란?
// PoW는 신뢰를 보장할 수 없는 탈 중앙화 시스템에서, 신뢰를 보장 할 수 있는 증명과정이다.
// 비트코인의 경우 작업증명을 이용하여 코인의 실제 유무와, 거래내역등이 올바르게 진행되었고, 맞는지를 체크한다.
// 말 그대로 '작업'해서 '증명' 하는것이다. 
// 더 풀어보자면, SHA-256 해시를 이용하여 난수발생을 통해 해시 값을 만들어낸다.
// 그러면 그 만들어진 해시 값, 그 값을 풀어내기위해 해시를 찾는 과정을 무수히 반복함으로써 해당 작업에 참여했음을 증명하는 방식이다.


// 해시값은 토씨 하나라도 바뀌면 그대로 값이 전체적으로 바뀐다.
// 따라서 위, 변조가 불가능하다.
#include <iostream>
#include <cstring>
#include "KISA_SHA256/KISA_SHA256.h"
using namespace std;

typedef struct blockheader {
	BYTE PreviousBlockHash[257]; // 전 블록의 거래내역을 해쉬 한 값
};

typedef struct block {
	int blockSize; // 거래내역 크기
	blockheader header; // 위에 있는 블록헤더
	int transactionCount = 0; // 몇 번째 거래인지
	BYTE transaction[100]; //거래 내역
};

int main() {
	block Block[10];
	int select = 0;
	int total;
	
	cout << "첫 거래내용 입력 : ";
	cin >> Block[0].transaction;
	
	Block[0].blockSize = strlen((char*)Block[0].transaction);
	total = 1;
	
	while(total < 10) {
		cout << total + 1 << "번째 거래내용 입력 : ";
		cin >> Block[total].transaction;
		Block[total].transactionCount = Block[total-1].transactionCount + 1;
		Block[total].blockSize = strlen((char*)Block[total].transaction);
		SHA256_Encrypt(Block[total - 1].transaction, Block[total-1].blockSize, Block[total].header.previousBlockHash);
		total++;
	}
	
	while(true) {
		cout << endl << "1. 거래내역 확인   2. 거래내역 변조    0. 종료" << endl;
		cin >> select;
		if(select == 0) {
			return 0;
		} else if (select == 1) {
			int i;
			cout << endl << "번호 선택(1~9)";
			cin >> select;
			
			BYTE EncryptCheck[257];
			SHA256_Encrypt(Block[select - 1].transaction, Block[select - 1].blockSize, EncryptCheck);
			
			for(i = 0; i < 256; i++) {
				if(Block[select].header.previousBlockHash[i] != EncryptCheck[i]) {
					break;
				}
			}
			if(i != 256) {
				cout << "거래기록이 변조되었습니다." << endl;
			} else {
				cout << "거래기록 : " << Block[select - 1].transaction << endl;
			}
		} else if (select == 2) {
			cout << endl << "번호 선택(1~9)";
			cin >> select;
			
			Block[select - 1].transaction[0] = (BYTE)"\0";
			cout << endl << "거래 내용 입력 : " ;
			cin >> Block[select - 1].transaction;
			cout << "변조 완료" << endl;
		}
	}
	
	return 0;
}