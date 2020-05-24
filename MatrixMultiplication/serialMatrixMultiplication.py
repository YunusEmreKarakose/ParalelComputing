#numpy for double
import numpy as np
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

    for i in range(rowCountA):
        for j in range(colCountB):
            tmp=0
            for k in range(colCountA):
                tmp=tmp+(A[i][k]*B[k][j])
            C[i][j]=tmp
    
    #print(C)
    return

# run    
N=int(100)

#float
matrixA=[[np.float32(1.1) for row in range(N)] for col in range(N)]
matrixB=[[np.float32(1.1) for row in range(N)] for col in range(N)]
"""
#double
matrixA=[[np.float64(1.1) for row in range(N)] for col in range(N)]
matrixB=[[np.float64(1.1) for row in range(N)] for col in range(N)]
"""
#multiplication start time
startTime=time.time()
matrixMul(matrixA,matrixB)


print("multiplication took--- %s seconds ---" % (time.time() - startTime))