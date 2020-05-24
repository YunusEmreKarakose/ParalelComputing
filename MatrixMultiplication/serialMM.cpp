#include<iostream>
#include <time.h>

#include <chrono> 
using namespace std;
//Matrix class
template <typename T>
class Matrix{
    private:
        T *A;//matrix
        int row;
        int column;
    public:
    //float/double
    Matrix(int row,int column){
        this->A=new T[row*column];
        this->row=row;
        this->column=column;
        for(int i=0;i<row*column;i++){
            this->A[i]=1.1;
        }        
    }
    //destructor
    ~Matrix(){
        cout<<"deleted"<<endl;
        delete[]A;
    }
    //get func
    int getRow(){ return this->row;	}
    int getColumn(){	return this->column;	}
    T getMatrixElem(int i,int j){
    	return A[i*this->column+j];
	}
    //print matrix
    void printMatrix(){
        for(int i=0;i<this->row;i++){
            for(int j=0;j<this->column;j++){
                cout<<this->A[i*this->column+j]<<" ";
            }
            cout<<endl;
        }
    }
    //serial matrix multiplciation
    void serialMM(Matrix &m){
    	if(this->column==m.getRow()){//can multiply
    		//multiplication start/end time
    		auto start = chrono::steady_clock::now();
    		//this*m=result
    		T *result=new T[this->row*m.getColumn()];
			for(int i=0;i<this->row;i++){
				for(int j=0;j<m.getColumn();j++){
						T tmp=0;
						for(int k=0;k<this->column;k++){
							tmp=tmp+(this->getMatrixElem(i,k)*m.getMatrixElem(k,j));
						}
						result[i*m.getColumn()+j]=tmp;	
					}
			}
			//end time
			auto end = chrono::steady_clock::now();
			auto diff = end - start;
			cout << chrono::duration <double, milli> (diff).count() << " millisecond" << endl;
			//printresult
			/*cout<<"result:"<<endl;
			for(int i=0;i<this->row;i++){
				for(int j=0;j<m.getColumn();j++){
						cout<<result[i*m.getColumn()+j]<<" ";	
					}
				cout<<endl;
			}*/
			delete []result;	
		}else{
			cout<<"these matrixes cant be multiplied"<<endl;
		}
	}
};

int main(){
    int a=200;
    //float
    Matrix<float> *m1=new Matrix<float>(a,a);
    Matrix<float> *m2=new Matrix<float>(a,a);
    m1->serialMM(*m2);
	//double
    Matrix<double> *m3=new Matrix<double>(a,a);
    Matrix<double> *m4=new Matrix<double>(a,a);
    m3->serialMM(*m4);
	
	
	delete m1;
    delete m2;
    delete m3;
    delete m4;
    cin>>a;
return 0;
}
