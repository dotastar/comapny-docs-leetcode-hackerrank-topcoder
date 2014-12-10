#include "../inc.h"

vector<vector<int>> matrix;

void init(int n)
{
    assert(0 < n);
    matrix.resize(n);
    for (size_t i = 0; i < matrix.size(); ++i)
        matrix[i].resize(i, -1);
}

int mget(int a, int b)
{
    if (a == b)
        return -2;
    if (a < b)
        swap(a, b);
    assert(0 <= b && a < int(matrix.size()));
    return matrix[a][b];
}

void mset(int a, int b, int v)
{
    if (a == b)
        return;
    if (a < b)
        swap(a, b);
    assert(0 <= b && a < int(matrix.size()));
    matrix[a][b] = v;
}

int mmin(int a, int b)
{
    if (a < 0)
        return b;
    if (b < 0)
        return a;
    return min(a, b);
}

int mmin(int a, int b, int c, int d)
{
    return mmin(a, mmin(b, mmin(c, d)));
}

void make(int a, int b, int d)
{
    mset(a, b, mmin(d, mget(a, b)));
    const int cur = mget(a, b);
    const int n = matrix.size();
    for (int i = 0; i < n; ++i){
        const int ia = mget(i, a);
        if (-1 == ia)
            continue;
        for (int j = i + 1; j < n; ++j){
            const int jb = mget(j, b);
            if (-1 == jb)
                continue;
            int ij = mmin(mget(i, j), cur, ia, jb);
            mset(i, j, ij);
        }
    }
}

int check(int a, int b)
{
    int d = mget(a, b);
    if (-2 == d)
        d = 0;
    return d;
}

void solve()
{
    int n;
    cin >> n;
    if (n <= 1)
        return;
    init(n);
    string ins;
    int a, b;
    while (cin >> ins >> a >> b){
        if ("check" == ins){
            cout << check(a - 1, b - 1) << endl;
        } else{
            int d;
            cin >> d;
            make(a - 1, b - 1, d);
        }
    }
}

int main()
{
    solve();
    return 0;
}