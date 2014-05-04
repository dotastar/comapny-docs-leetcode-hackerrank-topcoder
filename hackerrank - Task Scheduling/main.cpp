#include "../inc.h"

//O(N^2)
void solve(const vector<pair<int, int>> & T)
{
    typedef pair<map<int, int>::iterator, bool> __Ret;
    map<int, int> tasks;    //deadline -> total minutes before current deadline
    int ret = 0;
    for (size_t i = 0; i < T.size(); ++i){
        __Ret ir = tasks.insert(make_pair(T[i].first, 0));
        if (ir.second){ //new insertion
            map<int, int>::iterator p = ir.first;
            if (p != tasks.begin()){
                --p;
                ir.first->second = p->second;   //get previous total
            }
        }
        for (; ir.first != tasks.end(); ++ir.first){
            ir.first->second += T[i].second;
            ret = max(ret, ir.first->second - ir.first->first);
        }
        cout << ret << endl;
    }
}

void test()
{
    {
        vector<pair<int, int>> T;
        T.push_back(make_pair(2, 2));
        T.push_back(make_pair(1, 1));
        T.push_back(make_pair(4, 3));
        T.push_back(make_pair(10, 1));
        T.push_back(make_pair(2, 1));
        solve(T);
    }
}


int main()
{
    test(); return 0;
    int t;
    cin >> t;
    vector<pair<int, int>> tasks(t);
    for (int i = 0; i < t; ++t)
        cin >> tasks[i].first >> tasks[i].second;
    solve(tasks);
}
