class Solution {
public:
    int removeDuplicatesI(int A[], int n) {
        if(n <= 0)
            return 0;
        int c = 0;
        for(int i = 1;i < n;++i)
            if(A[c] != A[i])
                A[++c] = A[i];
        return c + 1;
    }
    int removeDuplicatesII(int A[], int n) {
        if(n < 3)
            return n;
        int i = 2, p = i;
        for(;i < n;++i)
            if(A[i] != A[p - 2])
                A[p++] = A[i];
        return p;
    }
};
