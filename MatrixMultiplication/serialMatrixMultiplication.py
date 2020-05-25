#numpy for double
import numpy as np
#https://docs.python.org/3/library/time.html
import time as time
# AxB=C
def matrixMul(A,B):
    #A matrix
    rowCountA=len(A)
    colCountA=len(A[0])
    #B Matrix
    rowCountB=len(B)
    colCountB=len(B[0])

    if(colCountA != rowCountB):
        print("Can't multiply A and B")
        return
    #create C array(result) colContB x rowCountA
    C=[[0 for row in range(colCountB)] for col in range(rowCountA)]

    #multiplication start time
    startTime=time.time_ns()
    for i in range(rowCountA):
        for j in range(colCountB):
            tmp=0
            for k in range(colCountA):
                tmp=tmp+(A[i][k]*B[k][j])
            C[i][j]=tmp
    
    #print(C)
    print("multiplication took--- %s nanoseconds ---" % (time.time_ns() - startTime))
    return
# AxB=C
def matrixMulP(A,B):
    #A matrix
    rowCountA=len(A)
    colCountA=len(A[0])
    #B Matrix
    rowCountB=len(B)
    colCountB=len(B[0])

    if(colCountA != rowCountB):
        print("Can't multiply A and B")
        return
    #create C array(result) colContB x rowCountA
    C=[[0 for row in range(colCountB)] for col in range(rowCountA)]

    #multiplication start time
    startTime=time.time_ns()
    for i in range(rowCountA):
        for j in range(colCountB):
            tmp=0
            for k in range(colCountA):
                tmp=tmp+(A[i][k]*B[k][j])
            C[i][j]=tmp
    
    #print(C)
    print("multiplication took--- %s nanoseconds ---" % (time.time_ns() - startTime))
    return

# run    
N=int(300)

#float
matrixAf=[[np.float32(1.1) for row in range(N)] for col in range(N)]
matrixBf=[[np.float32(1.1) for row in range(N)] for col in range(N)]
matrixMul(matrixAf,matrixBf)

#double
matrixAd=[[np.float64(1.1) for row in range(N)] for col in range(N)]
matrixBd=[[np.float64(1.1) for row in range(N)] for col in range(N)]
matrixMul(matrixAd,matrixBd)

