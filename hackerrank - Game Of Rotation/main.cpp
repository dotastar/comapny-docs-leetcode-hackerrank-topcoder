#include "../inc.h"

long sum(const vector<long> & A, size_t from)
{
    long r = 0;
    for (size_t i = 0; i < A.size(); ++i)
        r += A[(from + i) % A.size()] * (i + 1);
    return r;
}

//O(N^2)
long solve1(const vector<long> & A)
{
    long r = sum(A, 0);
    for (size_t i = 1; i < A.size(); ++i)
        r = max(r, sum(A, i));
    return r;
}

long solve2(const vector<long> & A)
{

}

#define solve solve1

void test()
{
    cout << solve({ 20, 30, 10 }) << endl;
}

int main()
{
    test(); return 0;
    int n;
    cin >> n;
    vector<long> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    cout << solve(A) << endl;
}