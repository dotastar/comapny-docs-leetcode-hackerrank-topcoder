#include "../inc.h"

class Solution {
public:
    int maxProduct(int A[], int n) {
        assert(A && n > 0);
        int m1 = A[0], m2 = A[0], r = m1;
        for (int i = 1; i < n; ++i){
            if (A[i] >= 0){
                m1 = max(A[i], m1 * A[i]);
                m2 *= A[i];
            } else{
                int t = m1;
                m1 = m2 * A[i];
                m2 = min(A[i], t * A[i]);
            }
            r = max(r, m1);
        }
        return r;
    }
};

int main()
{
    {
        int A[] = { -4,-3,-2 };
        cout << Solution().maxProduct(A, sizeof A / sizeof A[0]) << endl;
    }{
        int A[] = { 2, 3, -2, 4 };
        cout << Solution().maxProduct(A, sizeof A / sizeof A[0]) << endl;
    }{
        int A[] = { -2 };
        cout << Solution().maxProduct(A, sizeof A / sizeof A[0]) << endl;
    }{
        int A[] = { -2, 3, -4 };
        cout << Solution().maxProduct(A, sizeof A / sizeof A[0]) << endl;
    }
    return 0;
}