#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int C(int n, int a)
{
    if (n < a || n < 1)
        return 0;
    if (a < 1)
        return 1;
    a = min(a, n - a);
    double r = 1;
    for (int i = 0; i < a; ++i){
        r *= (n - i);
        r /= (i + 1);
    }
    return int(r);
}

vector<int> save;

int ways(int n)
{
    int r = 0;
    for (int i = 0; i <= n / 4; ++i)
        r += C(n - 3 * i, i);
    return r;
}

int solve(int n)
{
    return save[ways(n)];
}

void prepare()
{
    int r = ways(40);
    vector<bool> p(r + 1);
    p[0] = p[1] = true;
    for (int i = 0; i <= r; ++i){
        if (p[i])
            continue;
        for (int j = 2 * i; j <= r; j += i)
            p[j] = true;
    }
    save.resize(r + 1);
    for (int i = 1; i <= r; ++i){
        save[i] = save[i - 1];
        if (p[i])
            continue;
        ++save[i];
    }
}

int main()
{
    prepare();
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}