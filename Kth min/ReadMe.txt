Given two sorted array in ascending order with 
same length N, calculate the first K min a[i]+b[j]. 
time complexty O(N). 
some misunderstood first K, to put it straight, 
to find the Kth min, not the first min


dozerg:
����N��N�ľ���A������A[i][j] = a[i] + b[j]��
��N=5Ϊ��������ǰ10����С��ֵΪ�����X����ʶ��λ�ã�
��ô��11����С��ֵ���������С�O���е�����һ����
��ʵ����ÿ���ҵ���k����С��ֵ�󣬵�(k+1)����С��ֵ���������ɸ����ܵ�λ�á�
���������������sqrt(2)*N��
���������㷨�ĸ��Ӷ�ΪO(sqrt(2)*N*K)=O(N*K)��

X X X X O
X X X O I
X X O I I
X O I I I
O I I I I
