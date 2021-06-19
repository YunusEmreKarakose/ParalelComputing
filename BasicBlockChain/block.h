#include <sstream>
#include <iostream>

using namespace std;
class Block {
public:
    string hash;
    string prevHash;
    double timer;
    Block(int index, const string &data,const string &prevHashIn);

    void mineBlock(int difficulty);
    int getIndex();
	int getNonce();
	string getData();
private:
    int index;
    int nonce;
    string data;

    string calculateHash(int n);
};
