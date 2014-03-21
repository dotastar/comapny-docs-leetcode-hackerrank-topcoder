#include "..\inc.h"

class Solution {
public:
    struct Node{
        char ch_;
        int cnt_;
        Node(char c = 0, int i = 1):ch_(c),cnt_(i){}
        int match(char c) const{
            if(1 == cnt_)
                return ('.' == ch_ || c == ch_ ? 1 : 0);
            return ('.' == ch_ || c == ch_ ? 3 : 2);
        }
    };
    bool isMatch(const char *s, const char *p) {
        if(!p || !*p)
            return (!s || !*s);
        //preprocess pattern
        vector<Node> reg;
        for(const char * i = p;*i;++i){
            if('*' == *i){
                reg.back().cnt_ = 0;
            }else
                reg.push_back(Node(*i));
        }
        //match
        return help(reg, s, 0);
    }
    bool help(const vector<Node> & reg, const char * s, size_t pi){
        for(const char * i = s;i && *i;){
            if(pi >= reg.size())
                return false;
            switch(reg[pi].match(*i)){
                case 0:return false;
                case 1:++pi;++i;break;
                case 2:++pi;break;
                default:
                    if(help(reg, i, pi + 1))
                        return true;
                    ++i;
            }
        }
        for(;pi < reg.size();++pi)
            if(reg[pi].cnt_)
                return false;
        return true;
    }
};

int main()
{
    cout<<Solution().isMatch("acaabbaccbbacaabbbb", "a*.*b*.*a*aa*a*")<<endl;
    cout<<Solution().isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*a*a*b")<<endl;
    cout<<Solution().isMatch("", ".")<<endl;
    cout<<Solution().isMatch("aaa", "ab*a*c*a")<<endl;
    cout<<Solution().isMatch("aa","a")<<endl;
    cout<<Solution().isMatch("aa","aa")<<endl;
    cout<<Solution().isMatch("aaa","aa")<<endl;
    cout<<Solution().isMatch("aa", "a*")<<endl;
    cout<<Solution().isMatch("aa", ".*")<<endl;
    cout<<Solution().isMatch("ab", ".*")<<endl;
    cout<<Solution().isMatch("aab", "c*a*b")<<endl;
    cout<<Solution().isMatch("aa", "aab*")<<endl;
    cout<<Solution().isMatch("aaa", "a*a")<<endl;
    cout<<Solution().isMatch("ab", ".*c")<<endl;
}