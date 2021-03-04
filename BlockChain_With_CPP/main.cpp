// 이 코드는 https://www.youtube.com/watch?v=2VDQeQfh4Hs의 영상을 보고 작성한 코드입니다.
// 영어로 되어 있어 이해가 잘 안될것 같지만, 그래도 해보겠습니다.

#include <ctime>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Transaction Data

struct TransactionData {
	double amount;
	string senderKey; // 송신자 역할을 하는 키인듯 하다.
	string receiverKey; // 수신자 역할을 하는 키인듯 하다.
	time_t timestamp;
};

//Block Class
class Block
{
private:
    int index;
    size_t blockHash;
    size_t previousHash;
    size_t generateHash();
    
public:
    // Constuctor
    Block(int idx, TransactionData d, size_t prevHash);
    
    // Get Index
    int getIndex();
    
    // Get Original Hash
    size_t getHash();
    
    // Get Previous Hash
    size_t getPreviousHash();
    
    // Transaction Data
    // Would ordinarily be a private member with a "getter": getData()
    TransactionData data;
    
    // Validate Hash
    bool isHashValid();
};
// Constructor with Params
Block::Block(int idx, TransactionData d, size_t prevHash)
{
    index = idx;
    data = d;
    previousHash = prevHash;
    blockHash = generateHash();
}

// private functions
int Block::getIndex()
{
    return index;
}

/*
 Generates hash for current block
 - Includes previousHash in generation
 - ^ Very important
*/
size_t Block::generateHash()
{
    // creating string of transaction data
    std::string toHashS = std::to_string(data.amount) + data.receiverKey + data.senderKey + std::to_string(data.timestamp);
    
    // 2 hashes to combine
    std::hash<std::string> tDataHash; // hashes transaction data string
    std::hash<std::string> prevHash; // re-hashes previous hash (for combination)
    
    // combine hashes and get size_t for block hash
    return tDataHash(toHashS) ^ (prevHash(std::to_string(previousHash)) << 1);
}

// Public Functions
size_t Block::getHash()
{
    return blockHash;
}

size_t Block::getPreviousHash()
{
    return previousHash;
}

bool Block::isHashValid()
{
    return generateHash() == blockHash;
}

// BlockChain Class



class BlockChain {
private:
	Block createGenesisBlock();
public:
	// Public Chain
	vector<Block> chain;
	
	// Constructor
	BlockChain();
	
	// Public Function
	void addBlock(TransactionData data);
	bool isChainValid();
	
	Block *getLatesBlock();
	
};

//BlockChain Constructor

BlockChain::BlockChain() { // 생성자 실행시 제네시스 블록 넣기 , 제네시스 블록은 제일 첫번째 블록
	Block genesis = createGenesisBlock();
	chain.push_back(genesis);
}

Block BlockChain::createGenesisBlock() {
	time_t current;
	TransactionData d;
	d.amount = 0;
	d.receiverKey = "None";
	d.senderKey = "None";
	d.timestamp = time(&current);
	
	hash<int> hash1;
	Block genesis(0, d,0);
	return genesis;
}

Block *BlockChain::getLatesBlock() {
	return &chain.back();
}

void BlockChain::addBlock(TransactionData d) {
	int index = (int)chain.size() - 1;
	Block newBlock(index, d, getLatesBlock()->getHash());
}

bool BlockChain::isChainValid() {
	vector<Block>::iterator it;
	int chainLen = (int)chain.size();
	
	for(it = chain.begin(); it != chain.end(); ++it) {
		Block currentBlock = *it;
		if(!currentBlock.isHashValid()) {
			
			return false;
		}
		
		if(chainLen > 1) {
			Block previousBlock = *(it - 1);
			if(currentBlock.getPreviousHash() != previousBlock.getHash()){
				return false;
			}
		}
	}
	
	return true;
}

int main() {
	// Start BlockChain
	BlockChain AwesomeCoin;
	
	// Data for first added Block
	TransactionData data1;
	time_t dataTime;
	data1.amount = 1.5;
	data1.receiverKey = "IN";
	data1.senderKey = "Park";
	data1.timestamp = time(&dataTime);
	
	AwesomeCoin.addBlock(data1);
	
	cout << "Is Chain Valid? " << endl << AwesomeCoin.isChainValid() << endl;
	
	
	TransactionData data2;
	time_t data2Time;
	data2.amount = 0.000001223;
	data2.receiverKey = "Mark";
	data2.senderKey = "Joe";
	data2.timestamp = time(&data2Time);
	
	AwesomeCoin.addBlock(data2);
	
	cout << "Now is ths Chain Valid? " << endl << AwesomeCoin.isChainValid() << endl;
	
	Block *hackBlock = AwesomeCoin.getLatesBlock();
	hackBlock->data.amount = 10000;
	hackBlock->data.receiverKey = "In - from Crypto Cnthusiasts";
	
	cout << "Now is the chain still valid????" << endl;
	cout << AwesomeCoin.isChainValid() << endl;
	
}

// 가장 간단하게 블록체인의 저장과, 비교를 구현한듯 하다.
// 구동되는것에서도 보았듯, 새로운 블록을 추가하는건 상관없다.
// 하지만, 기존에 존재하던 블록을 해킹을 시도하여 이름을 바꾸고 정보를 저장한뒤 출력을 하면
// 이미 변경이 됐다는 문구와 함께 false가 나온다.
// 이로써 간단하게나마 블록체인의 구동을 엿볼수 있었다.