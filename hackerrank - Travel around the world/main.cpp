#include "../inc.h"

struct Solution1
{
    //O(N^2)
    int solve(long long c, const vector<long long> & a, const vector<long long> & b){
        C = c;
        A = a;
        B = b;
        int ret = 0;
        for (size_t i = 0; i < A.size(); ++i)
            if (canFrom(i))
                ++ret;
        return ret;
    }
private:
    bool canFrom(size_t f) const{
        long long cur = 0;
        for (size_t i = 0; i < A.size(); ++i){
            const size_t idx = (i + f) % A.size();
            cur += A[idx];
            if (cur > C)
                cur = C;
            cur -= B[idx];
            if (cur < 0)
                return false;
        }
        return true;
    }
    long long C;
    vector<long long> A, B;
};

struct Solution2
{
    //O(N)
    int solve(long long C, const vector<long long> & A, const vector<long long> & B){
        vector<long long> d(A.size());
        //first round
        int i = A.size() - 1, ret = 0;
        long long m = 0;
        for (; i >= 0; --i){
            m += B[i];
            if (m > C)
                return 0;
            if (m > A[i])
                d[i] = (m -= A[i]);
            else{
                d[i] = m = 0;
                ++ret;
            }
        }
        //second round
        i = A.size() - 1;
        for (; i >= 0; --i){
            m += B[i];
            if (m > C)
                return 0;
            long long t = (m > A[i] ? m - A[i] : 0);
            if (t == d[i])
                break;
            if (!d[i])
                --ret;
            d[i] = m = t;
        }
        return ret;
    }
};

typedef Solution2 Solution;

void testeach(long long c, const vector<long long> & a, const vector<long long> & b)
{
    long long r1 = Solution1().solve(c, a, b);
    long long r2 = Solution().solve(c, a, b);
    if (r1 != r2){
        print(a);
        print(b);
        cout << c << endl;
        cout << "Solution1: " << r1 << endl;
        cout << "Solution: " << r2 << endl;
        system("pause");
    }
}

void test()
{
    srand(time(0));
    {
        vector<long long> a{ 3, 5, 5, 2, 5, 1, 4, 3 };
        vector<long long> b{ 4, 1, 3, 5, 2, 2, 2, 3 };
        long long k = 6;
        testeach(k, a, b);
    }
    {
        vector<long long> a{ 2, 3, 2, 4, 3, 4, 2, 2 };
        vector<long long> b{ 4, 1, 5, 2, 1, 1, 5, 2 };
        long long k = 8;
        testeach(k, a, b);
    }
    {
        vector<long long> a{ 2, 3, 4, 2, 4, 5, 2, 3 };
        vector<long long> b{ 1, 3, 5, 3, 1, 1, 4, 2 };
        long long k = 6;
        testeach(k, a, b);
    }
    {
        vector<long long> a{ 2, 5, 2, 3, 1, 1, 4, 2 };
        vector<long long> b{ 2, 1, 1, 2, 3, 4, 2, 4 };
        long long k = 7;
        testeach(k, a, b);
    }
    {
        vector<long long> a{ 3};
        vector<long long> b{ 3 };
        long long k = 2;
        testeach(k, a, b);
    }
    {
        vector<long long> a{ 3, 1, 2 };
        vector<long long> b{ 2, 2, 2 };
        long long k = 3;
        testeach(k, a, b);
    }
    for (; 1;){
        vector<long long> a, b;
        genArray(a, 8, 1, 5);
        genArray(b, 8, 1, 5);
        int c = genRand(6, 10);
        testeach(c, a, b);
    }
}

int main()
{
    //test(); return 0;
    int n;
    long long c;
    cin >> n >> c;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    cout << Solution().solve(c, a, b) << endl;
}