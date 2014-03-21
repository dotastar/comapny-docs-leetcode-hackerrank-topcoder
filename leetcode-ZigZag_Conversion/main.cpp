#include "../inc.h"

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows < 2)
            return s;
        vector<string> rs(nRows);
        int idx = 0, d = 1;
        for(size_t i = 0;i < s.size();++i){
            rs[idx].push_back(s[i]);
            idx = nextIdx(idx, d, nRows);
        }
        for(size_t i = 1;i < rs.size();++i)
            rs[0].append(rs[i]);
        return rs[0];
    }
    int nextIdx(int i, int & d, int row){
        int r = i + d;
        if(r < 0){
            d = 1;
            return 1;
        }else if(r >= row){
            d = -1;
            return row - 2;
        }
        return r;
    }
};

int main(){}
