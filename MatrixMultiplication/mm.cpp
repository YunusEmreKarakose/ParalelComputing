#include<iostream>
#include <omp.h>

using namespace std;
template <class T>
void smm(T *A,T *B,int size);
template <class T>
void pmm(T *A,T *B,int size);
//main
int main(){
    cout.precision(10);
    int size=500;
    double *Ad=new double[size*size];    
    double *Bd=new double[size*size];
    for(int i=0;i<size*size;i++){
        Ad[i]=1.1;
        Bd[i]=1.1;        
    }
    smm<double>(Ad,Bd,size);
    pmm<double>(Ad,Bd,size);
    delete []Ad;
    delete []Bd;
    cin>>size;
    return 0;
}
//seri
template <class T>
void smm(T *A,T *B,int size){
    T *C=new T[size*size];
    //multiplication start/end time
    auto start = omp_get_wtime();
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            for(int k=0;k<size;k++){
                C[i*size+j]+=A[i*size+k]*B[k*size+i];
            }
            
        }
    }
    //end time
    double end=omp_get_wtime();
	cout<<"multiplication took " <<end - start<<endl;
    
    delete []C;
    return;
};
//paralel
template <class T>
void pmm(T *A,T *B,int size){
    T *C=new T[size*size];
    //start time
    double start=omp_get_wtime();
    //default num_threads(2) 2=4=8 eşit sonuç
    //schedule static dynamic yakın
    #pragma omp parallel for shared(A,B,C) schedule(dynamic)
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            for(int k=0;k<size;k++){
                C[i*size+j]+=A[i*size+k]*B[k*size+i];
            }
        }
    }
    
    //end time
    double end=omp_get_wtime();
	cout<<"multiplication took " <<end - start<<endl;
    delete []C;
    return;
};
