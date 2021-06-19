#include "Blockchain.h"
//create chain with genesis block
BlockChain::BlockChain(int index,const string &data)
{
	Block genesis=Block(index, data,"0000000000000000000000000000000000000000000000000000000000000000");
	genesis.mineBlock(1);
    chain.push_back(genesis);
    difficulty=2;
    counter=0;
}

void BlockChain::addBlock(Block newBlock)
{
    newBlock.prevHash = getLastBlock().hash;
    newBlock.mineBlock(difficulty);
    chain.push_back(newBlock);
    //make harder after two blocks added
    /*
    counter++;
    if(counter%2==0){
    	difficulty++;    	
	}*/
	difficulty++;
}

Block BlockChain::getLastBlock()
{
    return chain.back();
}
