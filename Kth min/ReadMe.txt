Given two sorted array in ascending order with 
same length N, calculate the first K min a[i]+b[j]. 
time complexty O(N). 
some misunderstood first K, to put it straight, 
to find the Kth min, not the first min


dozerg:
假设N×N的矩阵A，其中A[i][j] = a[i] + b[j]，
以N=5为例，假设前10个最小的值为矩阵里‘X’标识的位置，
那么第11个最小的值可能是所有‘O’中的任意一个。
其实对于每次找到第k个最小的值后，第(k+1)个最小的值，总有若干个可能的位置。
这个数量的最坏情况是sqrt(2)*N。
所以整个算法的复杂度为O(sqrt(2)*N*K)=O(N*K)。

X X X X O
X X X O I
X X O I I
X O I I I
O I I I I
