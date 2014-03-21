#include "..\inc.h"

class Solution {
public:
    int trap(int A[], int n) {
        if(n < 3)
            return 0;
        int r = 0;
        int s = 0, t, c;
        for(s = 0;s < n - 1;s = t){
            //find left wall
            for(;s < n - 1;++s)
                if(A[s] > A[s + 1])
                    break;
            if(s >= n - 1)
                break;
            //find right wall
            c = s + 1;
            for(t = s + 2;t < n;++t){
                if(A[t] > A[c])
                    c = t;
                if(A[s] <= A[t])
                    break;
            }
            //if no wall is higher than the left, use the highest wall
            if(t >= n)
                t = c;
            //calc water amount
            int h = min(A[s], A[t]);
            for(int i = s + 1;i < t;++i)
                if(A[i] < h)
                    r += h - A[i];
        }
        return r;
    }
};

int main(){}