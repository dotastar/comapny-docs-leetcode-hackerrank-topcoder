#include "..\inc.h"

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size())
            return false;
        return help(s1, s2, 0, 0, s1.size());
    }
    bool help(string s1, string s2, int i1, int i2, int len){
        int c[256] = {0};
        bool eq = true;
        for(int i = 0;i < len;++i){
            if(s1[i1 + i] == s2[i2 + i])
                continue;
            ++c[s1[i1 + i]];
            --c[s2[i2 + i]];
            eq = false;
        }
        if(eq)
            return true;
        for(int i = 0;i < 256;++i)
            if(c[i])
                return false;
        if(len < 3)
            return true;
        for(int i = 1;i < len;++i){
            if(help(s1, s2, i1, i2, i)
                    && help(s1, s2, i1 + i, i2 + i, len - i))
                return true;
            if(help(s1, s2, i1, i2 + len - i, i)
                    && help(s1, s2, i1 + i, i2, len - i))
                return true;
        }
        return false;
    }
};

int main()
{
    cout<<Solution().isScramble("great", "rgtae")<<endl;
    cout<<Solution().isScramble("abcd", "bdac")<<endl;
    cout<<Solution().isScramble("tqxpxeknttgwoppemjkivrulaflayn", "afaylnlurvikjmeppowgttnkexpxqt")<<endl;
}