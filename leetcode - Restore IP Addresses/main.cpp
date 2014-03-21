#include "..\inc.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> r;
        if(s.size() < 4 || 12 < s.size())
            return r;
        string v;
        help(r, s, 0, 0, v);
        return r;
    }
    void help(vector<string> & r, string s, int idx, int part, string & v){
        if(4 == part && idx == s.size()){
            r.push_back(v);
            return;
        }
        int rma = (3 - part) * 3;
        int rmi = (3 - part) * 1;
        size_t old = v.size();
        for(int i = 1;i <= 3;++i){
            int left = s.size() - idx - i;
            if(rmi <= left && left <= rma){
                if(3 == i){
                    int v = 100 * (s[idx] - '0') + 10 * (s[idx + 1] - '0') + s[idx + 2] - '0';
                    if(v > 255)
                        continue;
                }
                v.resize(old);
                v.append(s, idx, i);
                if(part < 3)
                    v.push_back('.');
                help(r, s, idx + i, part + 1, v);
            }
            if('0' == s[idx])
                break;
        }
    }
};

int main()
{
    print(Solution().restoreIpAddresses("25525511135"));
    print(Solution().restoreIpAddresses("010010"));
}