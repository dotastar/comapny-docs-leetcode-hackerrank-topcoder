#include <cassert>
#include <iostream>

using namespace std;

//calc 2^e % 1000000007
//formular: (AB)%C = ((A%C)(B%C))%C
unsigned long long expMod(int e)
{
    assert(e >= 0);
    if (e < 64)
        return ((unsigned long long)(1) << e) % 1000000007;
    unsigned long long r = expMod(e / 2);
    r = (r * r) % 1000000007;
    if (e & 1)
        r *= 2;
    return r % 1000000007;
}

long long solve(int A, int B)
{
    if (A > B)
        swap(A, B);
    //A <= B
    if (A < 0)
        return 0;
    if (B < 25)
        return 0;
    if (A > B - 2)
        return 0;
    long long ret[25];
    for (int i = 0; i < 25; ++i)
        ret[i] = 1;
    for (int j = 0; j < A && j < 24; ++j){
        for (int i = 1; i < 25; ++i)
            ret[i] = (ret[i] + ret[i - 1]) % 1000000007;
    }
    if (B == 25)
        return ret[24];
    if (A < B - 2)
        return 0;
    unsigned long long r = expMod(A - 24);
    return (r * ret[24]) % 1000000007;
}

void test()
{
    cout << solve(3, 25) << endl;
    cout << solve(1000000000, 1000000000 - 2) << endl;
    cout << solve(748922783, 748922783 - 2) << endl;    //862148271
}

int main()
{
    //test(); return 0;
    int A, B;
    cin >> A >> B;
    cout << solve(A, B) << endl;
}