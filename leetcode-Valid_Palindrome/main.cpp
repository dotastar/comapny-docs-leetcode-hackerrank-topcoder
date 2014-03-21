#include "../inc.h"

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())
            return true;
        size_t i = 0, j = s.size() - 1;
        for(;i < j;++i, --j){
            while(i < j && !isAlphaNum(s[i]))
                ++i;
            if(i >= j)
                return true;
            while(i < j && !isAlphaNum(s[j]))
                --j;
            if(i >= j)
                return true;
            if(!isEq(s[i], s[j]))
                return false;
        }
        return true;

    }
    bool isAlphaNum(char c){
        return ('a' <= c && c <= 'z')
            || ('A' <= c && c <= 'Z')
            || ('0' <= c && c <= '9');
    }
    bool isEq(char a, char b){
        if('A' <= a && a <= 'Z')
            a += 'a' - 'A';
        if('A' <= b && b <= 'Z')
            b += 'a' - 'A';
        return a == b;
    }
};

int main()
{
    cout<<Solution().isPalindrome("A man, a plan, a canal: Panama")<<endl;
    cout<<Solution().isPalindrome("race a car")<<endl;
    cout<<Solution().isPalindrome("1a2")<<endl;
}
