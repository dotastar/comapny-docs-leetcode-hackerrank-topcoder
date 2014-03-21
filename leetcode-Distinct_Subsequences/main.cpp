#include "../inc.h"

class Solution {
public:
    int numDistinct1(string S, string T) {
        if(T.empty())
            return 1;
        if(S.empty())
            return 0;
        int r = 0;
        help(S, 0, T, 0, r);
        return r;
    }
    void help(const string & S, size_t si, const string & T, size_t ti, int & r){
        if(ti >= T.size()){
            ++r;
            return;
        }
        for(size_t i = si;i < S.size();++i){
            if(S[i] != T[ti])
                continue;
            help(S, i + 1, T, ti + 1, r);
        }
    }

    int numDistinct2(string S, string T) {
        if(S.size() < T.size())
            return 0;
        if(T.empty())
            return 1;
        vector<int> v(S.size() + 1, 1);
        for(size_t i = 0;i < T.size();++i){
            vector<int> t(v.size());
            for(size_t j = i;j < S.size();++j)
                t[j + 1] = t[j] + (S[j] == T[i] ? v[j] : 0);
            t.swap(v);
        }
        return v.back();
    }
};

int main()
{
    cout<<Solution().numDistinct2("ccc", "c")<<endl;
    cout<<Solution().numDistinct2("rabbbit", "rabbit")<<endl;
}
