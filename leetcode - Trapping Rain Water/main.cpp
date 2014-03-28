#include "..\inc.h"

class Solution {
public:
    //O(N^2)
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
    //O(N)
    int trap2(int A[], int n) {
        if (n < 3)
            return 0;
        vector<int> h(n);
        h[0] = A[0];
        for (int i = 1; i < n - 1; ++i)
            h[i] = max(h[i - 1], A[i]);
        h[n - 1] = A[n - 1];
        int r = 0;
        for (int i = n - 2; i > 0; --i){
            h[i] = min(h[i], max(A[i], h[i + 1]));
            if (h[i] > A[i])
                r += h[i] - A[i];
        }
        return r;
    }
};

class SolutionFollowup {
public:
    //O(N)
    int trap(int A[], int n) {
        if (n < 3)
            return 0;
        vector<int> h(n);
        h[0] = A[0];
        for (int i = 1; i < n - 1; ++i)
            h[i] = max(h[i - 1], A[i]);
        h[n - 1] = A[n - 1];
        int r = 0, rr = 0;
        for (int i = n - 2; i > 0; --i){
            h[i] = min(h[i], max(A[i], h[i + 1]));
            if (h[i] > A[i]){
                r += h[i] - A[i];
                if (r > rr)
                    rr = r;
            } else
                r = 0;
        }
        return rr;
    }
};

int main()
{
    {
        int A[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
        cout << Solution().trap2(A, sizeof A / sizeof A[0]) << endl;
        cout << SolutionFollowup().trap(A, sizeof A / sizeof A[0]) << endl;
    }
}