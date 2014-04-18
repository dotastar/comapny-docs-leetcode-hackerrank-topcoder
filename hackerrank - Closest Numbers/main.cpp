#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > solve(vector<int> & a)
{
    sort(a.begin(), a.end());
    int m = -1;
    vector<pair<int, int> > ret;
    for (size_t i = 1; i < a.size(); ++i){
        int d = a[i] - a[i - 1];
        if (m < 0 || d < m){
            ret.clear();
            ret.push_back(make_pair(a[i - 1], a[i]));
            m = d;
        } else if (d == m)
            ret.push_back(make_pair(a[i - 1], a[i]));
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<pair<int, int> > ret = solve(a);
    for (size_t i = 0; i < ret.size(); ++i)
        cout << ret[i].first << " " << ret[i].second << " ";
    return 0;
}