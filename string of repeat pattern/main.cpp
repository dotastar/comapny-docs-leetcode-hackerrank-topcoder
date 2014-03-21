#include "..\inc.h"

bool solve(const string & s)
{
    if(s.size() < 4)
        return false;
    int len = 1;
    for(size_t pi = 0, i = 1;i < s.size();){
        if(s[pi] == s[i]){
            pi = (pi + 1) % len;
            ++i;
        }else if(!pi){
            len = ++i;
        }else{
            len = i - 1;
            pi = 0;
        }
    }
    return (len > 1 && len < int(s.size()));
}

int main()
{
    cout<<solve("abcabcabc")<<endl;
    cout<<solve("abcdabcd")<<endl;
    cout<<solve("aaaaaaaabaaaaaaaab")<<endl;
    cout<<"----\n";
    cout<<solve("bcdbcdbcde")<<endl;
    cout<<solve("abcde")<<endl;
    cout<<solve("aaaaaaaaaa")<<endl;
    cout<<solve("aaaaaaaabaaaaaaaaab")<<endl;
}