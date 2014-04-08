#include "../inc.h"

struct Cmp
{
    bool operator ()(const pair<int, int> & c1, const pair<int, int> & c2) const{
        return c1.first < c2.first;
    }
};

int solve(vector<pair<int, int> > & city_pair)
{
    sort(city_pair.begin(), city_pair.end(), Cmp());
    vector<int> ret(city_pair.size(), 1);
    int r = ret[0];
    for (size_t i = 1; i < city_pair.size(); ++i){
        for (size_t j = 0; j < i; ++j){
            if (city_pair[j].second < city_pair[i].second)
                ret[i] = max(ret[i], ret[j] + 1);
        }
        r = max(r, ret[i]);
    }
    return r;
}

int main()
{
    srand((unsigned int)time(NULL));
    vector<pair<int, int> > c;
    genPairArray(c, 5, 0, 10);
    print(c);
    cout << solve(c) << endl;
}