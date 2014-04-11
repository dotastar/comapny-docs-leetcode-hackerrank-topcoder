#include "../inc.h"

vector<int> solve(int n)
{
    vector<int> ret;
    if (n < 1)
        return ret;
    //init state
    vector<vector<pair<int, bool> > > dp(1);  //list of list of (result, backtrace)
    for (int i = 0; i <= n; ++i)
        dp[0].push_back(make_pair(i, false));
    //dp
    for (int i = 2; i * i <= n; ++i){
        vector<pair<int, bool> > cur = dp.back();
        const int sq = i * i;
        for (int j = sq; j <= n; ++j){
            int c = cur[j - sq].first + 1;
            cur[j].second = (c < cur[j].first);
            cur[j].first = min(cur[j].first, c);
        }
        dp.resize(dp.size() + 1);
        dp.back().swap(cur);
    }
    //back trace
    for (int i = dp.size() - 1; i >= 0;){
        if (dp[i][n].second){
            int sq = i + 1;
            sq *= sq;
            if (n >= sq){
                ret.push_back(sq);
                n -= sq;
                continue;
            }
        }
        --i;
    }
    if (n)
        ret.resize(ret.size() + n, 1);
    return ret;
}

int main()
{
    for (int i = 1; i <= 25; ++i)
        print(solve(i));
    print(solve(100000));
}