#include "../inc.h"

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string> > res;
        for(size_t i = 0;i < strs.size();++i){
            string k = strs[i];
            sort(k.begin(), k.end());
            res[k].push_back(strs[i]);
        }
        vector<string> r;
        for(unordered_map<string, vector<string> >::const_iterator it = res.begin();it != res.end();++it){
            if(it->second.size() < 2)
                continue;
            r.insert(r.end(), it->second.begin(), it->second.end());
        }
        return r;
    }
};

int main()
{
}
