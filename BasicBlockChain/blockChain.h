#include <vector>
#include "block.h"

using namespace std;

class BlockChain {
public:
    BlockChain(int index,const string &data);

    void addBlock(Block newBlock);
    Block getLastBlock();
private:
    int difficulty;
    int counter;
    vector<Block> chain;
};
