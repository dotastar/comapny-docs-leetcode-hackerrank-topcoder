#include "../inc.h"

int help(const int * don, size_t sz)
{
    if (!sz)
        return 0;
    assert(don);
    if (sz < 2)
        return don[0];
    int pp = don[0], p = max(pp, don[1]);
    for (size_t i = 2; i < sz; ++i){
        pp = max(p, pp + don[i]);
        swap(pp, p);
    }
    return p;
}

int solve(const vector<int> & donations)
{
    if (donations.empty())
        return 0;
    return max(help(&donations[0], donations.size() - 1), help(&donations[1], donations.size() - 1));
}

int main()
{
    {
        vector<int> don{ 10, 3, 2, 5, 7, 8 };
        cout << solve(don) << endl;
    }{
        vector<int> don{ 11, 15 };
        cout << solve(don) << endl;
    }{
        vector<int> don{ 7, 7, 7, 7, 7, 7, 7 };
        cout << solve(don) << endl;
    }{
        vector<int> don{ 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
        cout << solve(don) << endl;
    }{
        vector<int> don{ 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,
            6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
            52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 };
        cout << solve(don) << endl;
    }
}