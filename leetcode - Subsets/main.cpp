#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > r;
        if(S.empty())
            return r;
        sort(S.begin(), S.end());
        assert(S.size() <= 32);
        unsigned int bits = 0;
        unsigned int max = (1 << S.size()) - 1;
        for(;bits <= max;++bits){
            vector<int> v;
            unsigned int b = bits;
            for(int i = 0;b;b >>= 1, ++i)
                if(b & 1)
                    v.push_back(S[i]);
            r.push_back(v);
        }
        return r;
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > r;
        if(S.empty())
            return r;
        map<int, int> m;
        for(size_t i = 0;i < S.size();++i)
            ++m[S[i]];
        vector<int> v;
        help(m.begin(), m.end(), v, r);
        return r;
    }
    template<class Iter>
    void help(Iter f, Iter t, vector<int> & v, vector<vector<int> > & r){
        if(f == t){
            r.push_back(v);
        }else{
            Iter it = f++;
            size_t old = v.size();
            for(int i = 0;i <= it->second;++i){
                v.resize(old);
                v.resize(old + i, it->first);
                help(f, t, v, r);
            }
        }
    }
};

int main(){}