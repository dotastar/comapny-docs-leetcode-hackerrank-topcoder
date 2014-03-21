#include "../inc.h"

class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > path(1, vector<string>(1, start));
        if(start == end)
            return path;
        //bfs
        vector<vector<string> > r;
        if(!help(path, end, dict))
            return r;
        //dfs
        vector<string> tmp(1, end);
        help(path, path.size() - 1, end, tmp, r);
        //reverse r
        for(size_t i = 0;i < r.size();++i){
            if(r[i].size() < 2)
                continue;
            for(size_t j = 0, k = r[i].size() - 1;j < k;++j, --k)
                r[i][j].swap(r[i][k]);
        }
        return r;
    }
    bool help(vector<vector<string> > & path, string end, unordered_set<string> & dict){
        if(path.empty())
            return false;
        for(vector<string> tmp;;tmp.clear()){
            vector<string> & v = path.back();
            for(size_t i = 0;i < v.size();++i){
                string & s = v[i];
                for(size_t j = 0;j < s.size();++j){
                    const char old = s[j];
                    for(s[j] = 'a';s[j] <= 'z';++s[j]){
                        if(old == s[j])
                            continue;
                        if(s == end){
                            s[j] = old;
                            return true;
                        }
                        unordered_set<string>::iterator wh = dict.find(s);
                        if(wh == dict.end())
                            continue;
                        tmp.push_back(*wh);
                        dict.erase(wh);
                    }
                    s[j] = old;
                }
            }
            if(tmp.empty())
                return false;
            path.resize(path.size() + 1);
            path.back().swap(tmp);
        }
        return false;
    }
    void help(const vector<vector<string> > & path, int idx, const string & target, vector<string> & tmp, vector<vector<string> > & r){
        if(idx < 0){
            r.push_back(tmp);
            return;
        }
        const vector<string> & v = path[idx];
        const size_t old = tmp.size();
        for(size_t i = 0;i < v.size();++i){
            if(!help(v[i], target))
                continue;
            tmp.resize(old);
            tmp.push_back(v[i]);
            help(path, idx - 1, v[i], tmp, r);
        }
    }
    bool help(const string & a, const string & b){
        assert(a.size() == b.size());
        int r = 0;
        for(size_t i = 0;i < a.size();++i){
            if(a[i] != b[i])
                ++r;
            if(r > 1)
                break;
        }
        return (1 == r);
    }
};

int main()
{
    {
        string start = "hit";
        string end = "cog";
        const char * d[] = {"hot","dot","dog","lot","log"};
        unordered_set<string> dict;
        for(size_t i = 0;i < sizeof d / sizeof d[0];++i)
            dict.insert(d[i]);
        print(Solution().findLadders(start, end, dict));
    }
}
