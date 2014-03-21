#include "../inc.h"

bool help(char s, char p)
{
    return ((s && '.' == p) || s == p);
}

bool solve(const char * str, const char * pattern)
{
    if(!pattern || !*pattern)
        return (!str || !*str);
    const char * s = str;
    const char * p = pattern;
    for(;*s || *p;){
        if(!*p){
            return !*s;
        }else if('*' == *(p + 1)){
            for(;;){
                if(solve(s, p + 2))
                    return true;
                if(!help(*s++, *p))
                    break;
            }
            return false;
        }else if(!help(*s++, *p++))
            return false;
    }
    return true;
}

int main()
{
    //true
    cout<<solve("", "")<<endl;
    cout<<solve("", "a*b*c*")<<endl;
    cout<<solve("Facebook", "F.cebo*k")<<endl;
    cout<<solve("aaa", "a*aaa")<<endl;
    cout<<solve("bbb", "a*bbb")<<endl;
    cout<<solve("abc", ".*abc")<<endl;
    //false
    cout<<"---\n";
    cout<<solve("a", "")<<endl;
    cout<<solve("aa", "a")<<endl;
    cout<<solve("ab", "a*")<<endl;
    cout<<solve("aaa", "a*aaaa")<<endl;
    cout<<solve("dabc", ".*abcd")<<endl;
}
