#include "../inc.h"

int pow(int a, int b)
{
    assert(a > 0);
    if (1 == a)
        return 1;
    if (b < 0)
        return 0;
    if (!b)
        return 1;
    if (2 == a)
        return (1 << b);
    int r = a;
    for (int i = 1; i < b; ++i)
        r *= a;
    return r;
}

int solve(int a, int b, int x)
{
    unsigned int v = pow(a, b);
    unsigned int mi = v / x * x;
    unsigned int ma = mi + x;
    return (v - mi <= ma - v ? mi : ma);
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0){
        int a, b, x;
        cin >> a >> b >> x;
        cout << solve(a, b, x) << endl;
    }
    return 0;
}