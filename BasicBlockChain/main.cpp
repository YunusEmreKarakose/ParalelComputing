
#include "blockChain.h"
#include <omp.h>

int main() {
	//pdf data-->>  Bize her yer Trabzon! Bölümün en yakýþýklý hocasý Ýbrahim Hoca’dýr  
	//only english char -->> Bize her yer Trabzon! Bolumun en yakisikli hocasi Ibrahim Hoca’dir
	//with ctrl+2 (') -->>Bize her yer Trabzon! Bolumun en yakisikli hocasi Ibrahim Hoca'dir
	//create chain with genesis block
	BlockChain bChain = BlockChain(1,"Bize her yer Trabzon! Bolumun en yakisikli hocasi Ibrahim Hoca'dir");
	//get genesis block
	Block genesis=bChain.getLastBlock();
	//create data for next block
	int index=genesis.getIndex();
	string data=genesis.getData();
	string prevHash=genesis.prevHash;
	string hash=genesis.hash;
	int nonce=genesis.getNonce();
	
	for(int i=2;i<30;i++){
		
		cout<<endl;
		cout<<endl;
		cout<<endl;
		//add new block to chain
		stringstream param;
		//param<<index << data << prevHash<<hash << nonce;
		param<<index << data << prevHash<< nonce ;
		bChain.addBlock(Block(i,param.str(),hash));
		//store new block data for next block
		Block current=bChain.getLastBlock();
		index=current.getIndex();
		data=current.getData();
		prevHash=current.prevHash;
		hash=current.hash;
		nonce=current.getNonce();
				
	}
	return 0;
}
