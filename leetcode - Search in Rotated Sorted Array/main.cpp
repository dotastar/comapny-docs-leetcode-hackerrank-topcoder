#include "../inc.h"

class Solution {
public:
    int searchI(int A[], int n, int target) {
        int f = 0, c = n;
        while(c > 0){
            int m = c / 2;
            if(target == A[f + m])
                return f + m;
            if(A[f] <= A[f + m]){
                if(A[f] <= target && target < A[f + m])
                    c = m;
                else{
                    f += m + 1;
                    c -= m + 1;
                }
            }else{
                if(A[f + m] < target && target <= A[f + c - 1]){
                    f += m + 1;
                    c -= m + 1;
                }else
                    c = m;
            }
        }
        return -1;
    }
    bool searchII(int A[], int n, int target) {
        int f = 0, c = n;
        while (c > 0){
            int m = c / 2;
            if (target == A[f + m])
                return true;
            if (A[f] < A[f + m]){
                if (A[f] <= target && target < A[f + m])
                    c = m;
                else{
                    f += m + 1;
                    c -= m + 1;
                }
            } else if (A[f] > A[f + m]){
                if (A[f + m] < target && target <= A[f + c - 1]){
                    f += m + 1;
                    c -= m + 1;
                } else
                    c = m;
            } else {
                ++f;
                --c;
            }

        }
        return false;
    }
};

int main()
{
    {
        int A[] = { 4, 5, 6, 7, 0, 1, 2 };
        cout << Solution().searchI(A, sizeof A / sizeof A[0], 1) << endl;
    }{
        int A[] = { 1, 1, 1, 1, 1, 4, 1 };
        cout << Solution().searchII(A, sizeof A / sizeof A[0], 5) << endl;
    }
}

/*
3,1
3
f 0
c 2
m 1
*/