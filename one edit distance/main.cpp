#include <iostream>
#include <string>

using namespace std;

bool help(string s1, string s2, size_t p1, size_t p2)
{
    for(size_t i = 0;p1 + i < s1.size();++i)
        if(s1[p1 + i] != s2[p2 + i])
            return false;
    return true;
}

bool solve(string s1, string s2)
{
    if(s1.size() > s2.size())
        s1.swap(s2);
    if(s1.size() + 1 < s2.size())
        return false;
    for(size_t i = 0;i < s1.size();++i){
        if(s1[i] == s2[i])
            continue;
        if(s1.size() == s2.size())
            return help(s1, s2, i + 1, i + 1);
        return help(s1, s2, i, i + 1);
    }
    return (s1.size() < s2.size());
}

int main()
{
    cout<<solve("xyz", "xz")<<endl;
    cout<<solve("xyz", "xyk")<<endl;
    cout<<solve("xy", "xyz")<<endl;
    cout<<"---\n";
    cout<<solve("xyz", "xyz")<<endl;
    cout<<solve("xyz", "xzy")<<endl;
    cout<<solve("xyz", "x")<<endl;
    cout<<solve("x", "xyz")<<endl;
}
