#include "block.h"
#include "sha256.h"
#include <omp.h>
#define MAX_P            (omp_get_max_threads())
#define P                (omp_get_num_threads())
#define CHUNK_SIZE       4
#define MAX_NONCE 		 1000000000

//other blocks
Block::Block(int indexIn, const string &dataIn,const string &prevHashIn)
{
	index=indexIn;
	prevHash=prevHashIn;
	data=dataIn;
}

void Block::mineBlock(int difficulty)
{
    char head[difficulty + 1];
    for (int i = 0; i < difficulty; ++i)
    {
        head[i] = '0';
    }
    head[difficulty] = '\0';

    string str(head);	
	//nonce calculation start time
	double start = omp_get_wtime();
	cout<<"Calculating hash with:::"<<index << data << prevHash<<"+nonce"<<endl;
	bool nonceFound=false;	
	int n;
	string hashTmp;
	//set chunk
	int chunk=1;
	if(index>2){
		chunk=index*index;
	}
	int chunk2=chunk;
	//dynamic after 3 block
	if(index<3){
		cout<<"Static Schedule"<<endl;
		#pragma omp parallel for private(n,hashTmp) num_threads(4) schedule(static,1)
		for(n=0;n<MAX_NONCE;n++){
			if(nonceFound!=true){	
				hashTmp= calculateHash(n);
				//if hash is ok			
				if(hashTmp.substr(0, difficulty) == str){
					
					//nonce calculation end time
			    	double end=omp_get_wtime();
					timer=end - start;
					nonceFound=true;
					nonce=n;
					hash=hashTmp;
					//print details
					cout<<"Block::       "<<index<<" Mined"<<endl;
					cout<<"Data::>       "<<data<<endl;
					cout<<"Nonce::>      "<<nonce<<endl;
					cout<<"Thread Num::> "<<omp_get_thread_num()<<endl;		
					cout<<"Nonce calculation took::" <<end - start<<endl;
			    	cout<<"Hash::>       "<< hash << endl;
			    	cout<<"PrevHash::>   "<<prevHash<<endl;
				}
				
			}					
		}
	}else{
		
		cout<<"Dynamic Schedule"<<endl;
		#pragma omp parallel for private(n,hashTmp) num_threads(4) schedule(dynamic,5)
		for(n=0;n<MAX_NONCE;n++){
			if(nonceFound!=true){	
				hashTmp= calculateHash(n);
				//if hash is ok			
				if(hashTmp.substr(0, difficulty) == str){
					
					//nonce calculation end time
			    	double end=omp_get_wtime();
					timer=end - start;
					nonceFound=true;
					nonce=n;
					hash=hashTmp;
					//print details
					cout<<"Block::       "<<index<<" Mined"<<endl;
					cout<<"Data::>       "<<data<<endl;
					cout<<"Nonce::>      "<<nonce<<endl;
					cout<<"Thread Num::> "<<omp_get_thread_num()<<endl;		
					cout<<"Nonce calculation took::" <<end - start<<endl;
			    	cout<<"Hash::>       "<< hash << endl;
			    	cout<<"PrevHash::>   "<<prevHash<<endl;
				}
				
			}					
		}
	}
	
	
	
    //control fail
    if(nonceFound!=true){
    	cout<<"Couldnt mine with MAX_NONCE:"<<MAX_NONCE<<endl;
	}
}

int Block::getIndex(){	return index;	}
int Block::getNonce(){	return	nonce;	}
string Block::getData(){ return data;	}

string Block::calculateHash(int n)
{		
    stringstream param;
	param<<index << data << prevHash << n;	
    return sha256(param.str());
}
