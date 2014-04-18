#include <iostream>

using namespace std;

int solve(long long n)
{
    int save[10] = { -1, 1, 0 };
    int ret = 0;
    for (long long m = n; m;){
        long long d = m / 10;
        long long r = m - d * 10;
        m = d;
        if (save[r] > 0)
            ++ret;
        else if (save[r] == 0){
            if (0 == n % r){
                save[r] = 1;
                ++ret;
                switch (r){
                    case 9:save[3] = 1; break;
                    case 8:save[2] = save[4] = 1; break;
                    case 6:save[2] = save[3] = 1; break;
                    case 4:save[2] = 1; break;
                }
            } else
                save[r] = -1;
        }
    }
    return ret;
}

int main()
{
    int t;
    cin >> t;
    while (t--){
        long long n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}