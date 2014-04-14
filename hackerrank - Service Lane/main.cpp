#include "../inc.h"

void prepare(const vector<int> & width, vector<pair<int, int> > & save)
{
    for (int i = width.size() - 1; i >= 0; --i){
        if (i + 1 < int(width.size()))
            save[i] = save[i + 1];
        switch (width[i]){
            case 1:save[i].first = i; break;
            case 2:save[i].second = i; break;
        }
    }
}

int solve(const vector<pair<int, int> > & save, int from, int to)
{
    const pair<int, int> & p = save[from];
    if (p.first >= 0 && to >= p.first)
        return 1;
    if (p.second >= 0 && to >= p.second)
        return 2;
    return 3;
}

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> w;
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        w.push_back(x);
    }
    vector<pair<int, int> > save(w.size(), make_pair(-1, -1));
    prepare(w, save);
    for (int i = 0; i < t; ++i){
        int from, to;
        cin >> from >> to;
        cout << solve(save, from, to) << endl;
    }
    return 0;
}