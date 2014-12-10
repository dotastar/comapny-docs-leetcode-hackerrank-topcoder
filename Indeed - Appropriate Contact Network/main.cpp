#include "../inc.h"

vector<string> rel;

bool getBit(int bits, int index)
{
    return (0 != (bits & (1 << index)));
}

void setBit(int & bits, int index)
{
    bits |= (1 << index);
}

void resetBit(int & bits, int index)
{
    bits &= ~(1 << index);
}

int countBits(int bits)
{
    int r = 0;
    for (; bits; ++r, bits &= (bits - 1));
    return r;
}

double help(int cur, int bits)
{
    const int n = rel.size();
    vector<int> left;
    for (int i = 0; i < n; ++i)
        if ('Y' == rel[cur][i] && !getBit(bits, i))
            left.push_back(i);
    if (left.empty())
        return countBits(bits);
    const double pb = 1. / left.size();
    double r = 0;
    for (int i : left){
        setBit(bits, i);
        r += pb * help(i, bits);
        resetBit(bits, i);
    }
    return r;
}

void solve()
{
    cout.precision(14);
    cout << help(0, 1) << endl;
}

void test()
{
    {
        rel = { "NYYY", "YNNN", "YNNY", "YNYN" };
        solve();
    }{
        rel = { "NNNNN", "NNYYY", "NYNYY", "NYYNY", "NYYYN" };
        solve();
    }{
        rel = { "NNNNYNYNNY", "NNYYNNYNYY", "NYNYYYNYYN", "NYYNYYYNYY", "YNYYNYYYNN", "NNYYYNYYYN", "YYNYYYNYYN", "NNYNYYYNYN", "NYYYNYYYNY", "YYNYNNNNYN" };
        solve();
    }
}


int main()
{
    test();
    return 0;

    int n;
    cin >> n;
    rel.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> rel[i];
    solve();
    return 0;
}