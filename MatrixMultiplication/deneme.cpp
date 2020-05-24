#include<iostream>
//https://en.cppreference.com/w/cpp/chrono/steady_clock
#include <chrono> 
#include "omp.h"

using namespace std;

int main(){
    int size=200;
    double A[size][size];    
    double B[size][size];
    for(int i=0;i<size;i++){
        A[i][i]=1.1;
        B[i][i]=1.1;        
    }
    double C[size][size];

    //multiplication start/end time
    auto start = chrono::steady_clock::now();
    #pragma omp paralel for  private(i,j,k) num_threads(8)
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            double tmp=0.0;
            for(int k=0;k<size;k++){
                tmp+=A[i][k]*B[k][i];
            }
            C[i][j]=tmp;
        }
    }
    //end time
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
    cout.precision(10);//print time diff with all float
    cout << chrono::duration <double, nano> (diff).count() << " nano" << endl;
    cin>>size;
    return 0;
}