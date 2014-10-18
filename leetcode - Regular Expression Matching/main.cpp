#include "..\inc.h"

class Solution1 {
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

class Solution2 {
public:
    bool help(char s, char p){
        return (s == p || (s && '.' == p));
    }
    bool isMatch(const char *s, const char *p) {
        if (!p || !*p)
            return (!s || !*s);
        assert('*' != *p);
        for (++p ; ; ){
            if ('*' == *p){
                for (;;++s){
                    if (isMatch(s, p + 1))
                        return true;
                    if (!help(*s, *(p - 1))){
                        ++p;
                        break;
                    }
                }
            } else {
                if (!help(*s++, *(p - 1)))
                    return false;
                if (!*p)
                    break;
                ++p;
            }
        }
        return (!*s);
    }
};

class Solution3 {
public:
    bool isMatch(const char *s, const char *p) {
        vector<bool> dp{true}, tmp;
        for(const char * pp = p;pp && *pp;++pp)
            dp.push_back('*' == *pp ? *(dp.rbegin() + 1) : false);
        for(const char * ss = s;ss && *ss;++ss, tmp.clear()){
            tmp.push_back(false);
            for(size_t i = 0;i < dp.size() - 1;++i)
                tmp.push_back('.' == p[i] || *ss == p[i] ?
                    dp[i] :
                    ('*' == p[i] ?
                        *(tmp.rbegin() + 1) || (('.' == p[i - 1] || *ss == p[i - 1]) && (tmp.back() || dp[i + 1]))
                        : false));
            dp.swap(tmp);
        }
        return dp.back();
    }
};

template<class S>
void test()
{
    typedef S Solution;
    cout<<Solution().isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*a*a*b")<<endl;
    cout<<Solution().isMatch("aaa", "ab*a*c*a")<<endl;
    cout<<Solution().isMatch("aa","aa")<<endl;
    cout<<Solution().isMatch("aa", "a*")<<endl;
    cout<<Solution().isMatch("aa", ".*")<<endl;
    cout<<Solution().isMatch("ab", ".*")<<endl;
    cout<<Solution().isMatch("aab", "c*a*b")<<endl;
    cout<<Solution().isMatch("aa", "aab*")<<endl;
    cout<<Solution().isMatch("aaa", "a*a")<<endl;
    cout << "----\n";
    cout<<Solution().isMatch("ab", ".*c")<<endl;
    cout << Solution().isMatch("acaabbaccbbacaabbbb", "a*.*b*.*a*aa*a*") << endl;
    cout << Solution().isMatch("", ".") << endl;
    cout << Solution().isMatch("aa", "a") << endl;
    cout << Solution().isMatch("aaa", "aa") << endl;
    cout << "END\n";
}

int main()
{
    test<Solution1>();
    test<Solution2>();
}