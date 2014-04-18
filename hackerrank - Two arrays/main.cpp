#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

bool solve(vector<int> & a, vector<int> & b, int k)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    for (size_t i = 0; i < a.size(); ++i){
        if (a[i] + b[i] < k)
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i){
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int j = 0; j < n; ++j)
            cin >> a[j];
        for (int j = 0; j < n; ++j)
            cin >> b[j];
        cout << (solve(a, b, k) ? "YES" : "NO") << endl;
    }
}