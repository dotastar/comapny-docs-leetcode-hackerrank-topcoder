class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if(!n)
            return;
        for(int i = m - 1, j = i + n;i >= 0;--i,--j)
            A[j] = A[i];
        int i = n, j = 0, k = 0;
        for(;i < m + n && j < n;++k){
            if(A[i] < B[j]){
                A[k] = A[i++];
            }else
                A[k] = B[j++];
        }
        for(;j < n;++j,++k)
            A[k] = B[j];
    }
};

