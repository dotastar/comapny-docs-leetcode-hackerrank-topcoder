#include "../inc.h"

class Solution {
public:
    double pow(double x, int n) {
        if (n < 0){
            x = 1 / x;
            n = -n;
        }
        double r = 1;
        for (int m = 0x40000000; m; m >>= 1){
            r *= r;
            if (m & n)
                r *= x;
        }
        return r;
    }
    double pow2(double x, int n) {
        if (!n)
            return 1;
        else if (n < 0){
            x = 1 / x;
            n = -n;
        }
        if (1 == n)
            return x;
        double r = pow2(x, n / 2);
        r *= r;
        if (n & 1)
            r *= x;
        return r;
    }
};

int main()
{
    cout << Solution().pow2(5, 4) << endl;
}
