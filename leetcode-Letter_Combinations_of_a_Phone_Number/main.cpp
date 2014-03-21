#include "../inc.h"

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        const string map[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> r;
        string v;
        help(r, digits, 0, v, map);
        return r;
    }
    void help(vector<string> & r, const string & digits, size_t idx, string & v, const string (&map)[10]){
        assert(idx <= digits.size());
        if(idx == digits.size()){
            r.push_back(v);
            return;
        }
        const string & m = map[digits[idx] - '0'];
        if(m.empty()){
            help(r, digits, idx + 1, v, map);
            return;
        }
        size_t old = v.size();
        for(size_t i = 0;i < m.size();++i){
            v.resize(old);
            v.push_back(m[i]);
            help(r, digits, idx + 1, v, map);
        }
    }
};

int main()
{
    Solution().letterCombinations("");
}
