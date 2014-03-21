#include "../inc.h"

void help(int cnt, set<int> & ret)
{
    if(cnt <= 0)
        return;
    if(1 == cnt){
        ret.insert(9);
        return;
    }
    set<int> s;
    help(cnt - 1, s);
    for(set<int>::const_iterator it = s.begin();it != s.end();++it){
        int v = *it;
        ret.insert(v + 9);
        ret.insert(v - 9);
        //ret.insert(-v - 9);
        ret.insert(v * 9);
        //ret.insert(-v * 9);
        ret.insert(v / 9);
        //ret.insert(-v / 9);
        ret.insert(9 - v);
        if(v){
            ret.insert(9 / v);
            //ret.insert(9 / -v);
        }
    }
}

int solve(int n)
{
    set<int> s;
    help(n, s);
    //print(s);
    for(int i = 1;;++i)
        if(0 == s.count(i))
            return i;
    return -1;
}

int main()
{
    for(int i = 1;i <= 20;++i)
        cout<<i<<": "<<solve(i)<<endl;
}
