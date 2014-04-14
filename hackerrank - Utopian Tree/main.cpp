#include "../inc.h"

long long save[60];

long long solve(int n)
{
    if (n < 1)
        return 1;
    assert(n <= 60);
    if (!save[n - 1]){
        save[n - 1] = solve(n - 1);
        if (n & 1)
            save[n - 1] *= 2;
        else
            save[n - 1] += 1;
    }
    return save[n - 1];
}

int main()
{
    //parse input
    int c;
    cin >> c;
    vector<int> ns;
    vector<long long> ret;
    for (int i = 0; i < c; ++i){
        int n;
        cin >> n;
        ret.push_back(solve(n));
    }
    for (size_t i = 0; i < ret.size(); ++i)
        cout << ret[i] << endl;
    return 0;
}