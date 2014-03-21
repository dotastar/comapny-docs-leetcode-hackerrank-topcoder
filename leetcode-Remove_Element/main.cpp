class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(n <= 0)
            return 0;
        int i = 0, j = n - 1;
        while(i < j)
            if(A[i] == elem)
                A[i] = A[j--];
            else
                ++i;
        return A[i] == elem ? i : i + 1;
    }
};
