#include "../inc.h"

class Solution {
public:
    struct Pos{
        size_t i, j, k;
        bool operator <(const Pos & a) const{
            if(i != a.i)
                return i < a.i;
            if(j != a.j)
                return j < a.j;
            return k < a.k;
        }
    };
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        map<Pos, bool> save;
        return help(s1, s2, s3, 0, 0, 0, save);
    }
    bool help(string s1, string s2, string s3, size_t i, size_t j, size_t k, map<Pos, bool> & save){
        Pos p;
        p.i = i;
        p.j = j;
        p.k = k;
        map<Pos, bool>::const_iterator wh = save.find(p);
        if(wh != save.end())
            return wh->second;
        for(;i < s1.size() && j < s2.size() && k < s3.size();){
            if(s1[i] == s3[k]){
                if(s2[j] == s3[k] && help(s1, s2, s3, i, j + 1, k + 1, save)){
                    save[p] = true;
                    return true;
                }
                ++i, ++k;
            }else if(s2[j] == s3[k]){
                ++j, ++k;
            }else{
                save[p] = false;
                return false;
            }
        }
        if(k == s3.size()){
            bool r = (i == s1.size() && j == s2.size());
            save[p] = r;
            return r;
        }
        if(i == s1.size()){
            bool r = (s2.substr(j) == s3.substr(k));
            save[p] = r;
            return r;
        }
        bool r = (s1.substr(i) == s3.substr(k));
        save[p] = r;
        return r;
    }
};

int main()
{
    {
        string s1 = "aabcc";
        string s2 = "dbbca";
        cout<<Solution().isInterleave(s1, s2, "aadbbcbcac")<<endl;
        cout<<Solution().isInterleave(s1, s2, "aadbbbaccc")<<endl;
    }{
        string s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
        string s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
        cout<<Solution().isInterleave(s1, s2, "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab")<<endl;
    }
}
