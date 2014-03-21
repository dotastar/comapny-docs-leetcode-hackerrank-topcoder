#include "../inc.h"

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > r;
        if(candidates.empty())
            return r;
        set<int> c;
        for(size_t i = 0;i < candidates.size();++i)
            c.insert(candidates[i]);
        vector<int> v;
        help(target, c.begin(), c.end(), v, r);
        return r;
    }
    template<class Iter>
    void help(int t, Iter b, Iter e, vector<int> & v, vector<vector<int> > & r){
        if(!t){
            if(!v.empty())
                r.push_back(v);
            return;
        }
        size_t old = v.size();
        for(;b != e && *b <= t;++b){
            v.resize(old);
            v.push_back(*b);
            help(t - *b, b, e, v, r);
        }
    }

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > r;
        if(num.empty())
            return r;
        vector<pair<int, int> > save;
        {
            map<int, int> m;
            for(size_t i = 0;i < num.size();++i)
                ++m[num[i]];
            save.resize(m.size());
            copy(m.begin(), m.end(), save.begin());
        }
        vector<int> idx;
        help(save, idx, target, r);
        return r;
    }
    void help(const vector<pair<int, int> > & save, vector<int> & idx, int target, vector<vector<int> > & r){
        if(!target){
            vector<int> rr;
            for(size_t i = 0;i < idx.size();++i)
                rr.push_back(save[idx[i]].first);
            r.push_back(rr);
            return;
        }
        size_t old = idx.size();
        for(size_t i = (idx.empty() ? 0 : idx.back());i < save.size();++i){
            idx.resize(old);
            int cnt = count(idx.begin(), idx.end(), int(i));
            if(cnt >= save[i].second)
                continue;
            if(save[i].first > target)
                break;
            idx.push_back(i);
            help(save, idx, target - save[i].first, r);
        }
    }
};

int main()
{
    vector<int> c(2, 1);
    vector<vector<int> > r = Solution().combinationSum(c, 1);
    cout<<r.size()<<endl;
}
