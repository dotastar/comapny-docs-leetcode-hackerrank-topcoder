class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 0)
            return 0;
        int c = 0;
        for(int i = 1;i < n;++i)
            if(A[c] != A[i])
                A[++c] = A[i];
        return c + 1;
    }
};
