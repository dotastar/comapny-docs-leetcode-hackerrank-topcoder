#include "..\inc.h"

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for(int i = 0;i < n;){
            if(A[i] <= 0 || A[i] == i + 1 || A[i] > n || A[A[i] - 1] == A[i]){
                ++i;
                continue;
            }
            swap(A[i], A[A[i] - 1]);
        }
        for(int i = 0;i < n;++i)
            if(A[i] != i + 1)
                return i + 1;
        return n + 1;
    }
};

int main()
{
    {
        int A[] = {3,4,-1,1, 3};
        cout<<Solution().firstMissingPositive(A, sizeof A / sizeof A[0])<<endl;
    }
    {
        int A[] = {1,1};
        cout<<Solution().firstMissingPositive(A, sizeof A / sizeof A[0])<<endl;
    }
}