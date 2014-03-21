class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n < 3)
            return n;
        int i = 2, p = i;
        for(;i < n;++i)
            if(A[i] != A[p - 2])
                A[p++] = A[i];
        return p;
    }
};

int main(){}