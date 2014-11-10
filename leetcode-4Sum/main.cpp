#include "../inc.h"

class Solution {
public:
    //O(N^3 * logN)
    vector<vector<int> > fourSum1(vector<int> &num, int target) {
        vector<vector<int> > r;
        if(num.size() < 4)
            return r;
        map<int, int> cnt;
        for(size_t i = 0;i < num.size();++i)
            ++cnt[num[i]];
        vector<int> v;
        help(r, v, target, cnt.begin(), cnt);
        return r;
    }
    void help(vector<vector<int> > & r, vector<int> & v, int target
            , map<int, int>::const_iterator from
            , const map<int, int> & cnt){
        if(v.size() == 4){
            if(!target)
                r.push_back(v);
            return;
        }else if(v.size() == 3){
            if(target <= v.back())
                return;
            map<int, int>::const_iterator wh = cnt.find(target);
            if(wh == cnt.end())
                return;
            v.push_back(target);
            r.push_back(v);
            return;
        }
        if(from == cnt.end())
            return;
        size_t old = v.size();
        for(map<int, int>::const_iterator it = from;it != cnt.end();++it){
            map<int, int>::const_iterator n = it;
            ++n;
            for(int i = 1;i <= it->second && i + old <= 4;++i){
                int m = i * it->first;
                v.resize(old);
                v.resize(old + i, it->first);
                help(r, v, target - m, n, cnt);
            }
        }
    }


    //O(N^2)
    vector<vector<int> > fourSum2(vector<int> &num, int target) {
        vector<vector<int> > r;
        if(num.size() < 4)
            return r;
        unordered_map<int, vector<pair<int, int> > > save;
        for(size_t i = 0;i < num.size();++i)
            for(size_t j = i + 1;j < num.size();++j)
                save[num[i] + num[j]].push_back(make_pair<int>(i, j));
        typedef unordered_map<int, vector<pair<int, int> > >::const_iterator It;
        for(It it = save.begin();it != save.end();++it){
            It wh = save.find(target - it->first);
            if(wh == save.end())
                continue;
            for(size_t i = 0;i < it->second.size();++i){
                for(size_t j = 0;j < wh->second.size();++j){
                    const pair<int, int> & p1 = it->second[i];
                    const pair<int, int> & p2 = wh->second[j];
                    if(p1.first != p2.first && p1.first != p2.second
                            && p1.second != p2.first && p1.second != p2.second){
                        vector<int> v;
                        v.push_back(num[p1.first]);
                        v.push_back(num[p1.second]);
                        v.push_back(num[p2.first]);
                        v.push_back(num[p2.second]);
                        sort(v.begin(), v.end());
                        if(r.end() == find(r.begin(), r.end(), v))
                            r.push_back(v);
                    }
                }
            }
        }
        return r;
    }
};

class Solution2 {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        unordered_map<int, vector<pair<int, int>>> s;
        for(size_t i = 0;i < num.size();++i)
            for(size_t j = i + 1;j < num.size();++j)
                s[num[i] + num[j]].emplace_back(i, j);
        set<vector<int>> ret;
        for(auto it1 = s.begin();it1 != s.end();++it1){
            auto it2 = s.find(target - it1->first);
            if(s.end() == it2)
                continue;
            for(const auto & p1 : it1->second)
                for(const auto & p2 : it2->second){
                    vector<int> idx{p1.first, p1.second, p2.first, p2.second};
                    sort(idx.begin(), idx.end());
                    if(idx[0] == idx[1] || idx[1] == idx[2] || idx[2] == idx[3])
                        continue;
                    vector<int> r{num[idx[0]], num[idx[1]], num[idx[2]], num[idx[3]]};
                    sort(r.begin(), r.end());
                    ret.insert(r);
                }
        }
        return vector<vector<int>>(ret.begin(), ret.end());
    }
};

int main()
{
    {
        const int a[] = {-1, -2, -3, -4, 0, 0, 0, -4, -3, -3, -6};
        vector<int> num(a, a + sizeof a / sizeof a[0]);
        vector<vector<int> > r = Solution().fourSum2(num, -10);
        print(r);
    }
    {
        const int a[] = {-500,-481,-480,-469,-437,-423,-408,-403,-397,-381,-379,-377,-353,-347,-337,-327,-313,-307,-299,-278,-265,-258,-235,-227,-225,-193,-192,-177,-176,-173,-170,-164,-162,-157,-147,-118,-115,-83,-64,-46,-36,-35,-11,0,0,33,40,51,54,74,93,101,104,105,112,112,116,129,133,146,152,157,158,166,177,183,186,220,263,273,320,328,332,356,357,363,372,397,399,420,422,429,433,451,464,484,485,498,499};
        vector<int> num(a, a + sizeof a / sizeof a[0]);
        vector<vector<int> > r = Solution().fourSum2(num, 2139);
        print(r);
    }
    {
        const int a[] = {-479,-472,-469,-461,-456,-420,-412,-403,-391,-377,-362,-361,-340,-336,-336,-323,-315,-301,-288,-272,-271,-246,-244,-227,-226,-225,-210,-194,-190,-187,-183,-176,-167,-143,-140,-123,-120,-74,-60,-40,-39,-37,-34,-33,-29,-26,-23,-18,-17,-11,-9,6,8,20,29,35,45,48,58,65,122,124,127,129,145,164,182,198,199,206,207,217,218,226,267,274,278,278,309,322,323,327,350,361,372,376,387,391,434,449,457,465,488};
        vector<int> num(a, a + sizeof a / sizeof a[0]);
        vector<vector<int> > r = Solution().fourSum2(num, 1979);
        print(r);
    }
}
