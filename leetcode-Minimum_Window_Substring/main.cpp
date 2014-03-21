#include "../inc.h"

class Solution {
public:
    string minWindow1(string S, string T) {
        if(T.empty())
            return string();
        unordered_map<char, int> t;
        for(size_t i = 0;i < T.size();++i)
            ++t[T[i]];
        unordered_map<char, deque<int> > s;
        int ri = 0, rl = -1;
        for(size_t i = 0, c = 0;i < S.size();++i){
            if(!t.count(S[i]))
                continue;
            s[S[i]].push_back(i);
            ++c;
            if(s.size() < t.size() || c < T.size())
                continue;
            int mi = -1, ma = -1;
            bool full = true;
            for(unordered_map<char, deque<int> >::iterator it = s.begin();it != s.end();++it){
                deque<int> & v = it->second;
                unordered_map<char, int>::const_iterator ti = t.find(it->first);
                assert(ti != t.end());
                if(int(v.size()) < ti->second){
                    full = false;
                    break;
                }
                while(int(v.size()) > ti->second)
                    v.pop_front();
                for(int i = 0;i < ti->second;++i){
                    int idx = v[i];
                    if(mi < 0 || mi > idx)
                        mi = idx;
                    if(ma < 0 || ma < idx)
                        ma = idx;
                }
            }
            if(full && (rl < 0 || ma - mi + 1 < rl)){
                ri = mi;
                rl = ma - mi + 1;
            }
        }
        if(rl < 0)
            return string();
        return S.substr(ri, rl);
    }
    string minWindow2(string S, string T) {
        if(S.size() < T.size() || S.empty())
            return string();
        int t[256] = {0};
        for(size_t i = 0;i < T.size();++i)
            ++t[T[i]];
        int s[256] = {0};
        int ri = 0, rl = -1;
        size_t f = 0, i = 0;
        for(bool full = false;i < S.size();++i){
            if(!t[S[i]])
                continue;
            ++s[S[i]];
            if(!full){
                bool ff = true;
                for(int j = 0;j < 256;++j)
                    if(s[j] < t[j]){
                        ff = false;
                        break;
                    }
                if(ff)
                    full = true;
            }
            if(!full)
                continue;
            for(;f < i;++f)
                if(t[S[f]]){
                    if(s[S[f]] > t[S[f]])
                        --s[S[f]];
                    else
                        break;
                }
            if(rl < 0 || rl > i - f + 1){
                ri = f;
                rl = i - f + 1;
            }
        }
        if(rl < 0)
            return string();
        return S.substr(ri, rl);
    }
};

int main()
{
    {
        string S = "ADOBECODEBANC";
        string T = "ABC";
        cout<<Solution().minWindow2(S, T)<<endl;
    }{
        string S = "a";
        string T = "aa";
        cout<<Solution().minWindow2(S, T)<<endl;
    }
}
