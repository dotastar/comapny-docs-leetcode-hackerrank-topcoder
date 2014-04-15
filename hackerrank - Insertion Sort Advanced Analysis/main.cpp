#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long solve1(const vector<int> & a)
{
    map<int, int> save; //val -> count
    int ret = 0;
    for (size_t i = 0; i < a.size(); ++i){
        map<int, int>::iterator wh = save.upper_bound(a[i]);
        for (; wh != save.end(); ++wh)
            ret += wh->second;
        ++save[a[i]];
    }
    return ret;
}

long long merge(vector<int> & a, size_t from, size_t len)
{
    if (len < 2)
        return 0;
    const size_t h = len / 2;
    long long ret = merge(a, from, h);
    ret += merge(a, from + h, len - h);
    vector<int> tmp(a.begin() + from, a.begin() + from + h);
    size_t i = from, j = 0, k = h;
    for (; j < h && k < len; ++i){
        if (tmp[j] <= a[from + k])
            a[i] = tmp[j++];
        else{
            ret += h - j;
            a[i] = a[from + k++];
        }
    }
    for (; j < h; ++i)
        a[i] = tmp[j++];
    for (; k < len; ++i)
        a[i] = a[from + k++];
    return ret;
}

long long solve2(vector<int> & a)
{
    return merge(a, 0, a.size());
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; ++j)
            cin >> a[j];
        cout << solve2(a) << endl;
    }
    return 0;
}