#include "..\inc.h"

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string r;
        if(strs.empty())
            return r;
        r = strs[0];
        for(size_t i = 1;!r.empty() && i < strs.size();++i){
            size_t j = 0;
            for(;j < r.size() && j < strs[i].size();++j)
                if(r[j] != strs[i][j])
                    break;
            r.resize(j);
        }
        return r;
    }
};

int main(){}