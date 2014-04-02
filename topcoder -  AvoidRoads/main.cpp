#include "../inc.h"

long long gcd(long long a, long long b)
{
    assert(a > 0);
    while (b > 0){
        a %= b;
        swap(a, b);
    }
    return a;
}

long long C(int n, int i)
{
    if (i < 1 || i >= n)
        return 1;
    long long dn = 1, di = 1;
    for (int j = 1; j <= i; ++j){
        di *= j;
        dn *= n + 1 - j;
        long long d = gcd(di, dn);
        di /= d;
        dn /= d;
    }
    return dn / di;
}

long long solve(int width, int height, const vector<string> & bad)
{
    if (bad.empty())
        return C(width + height, width);

    return -1;
}

int main()
{
    {
        cout << solve(1, 1, {}) << endl;
    }{
        cout << solve(35, 31, {}) << endl;
    }
}