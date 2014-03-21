#include "../inc.h"

void help(string & ret, string & s, int n1, int n2, int n3)
{
    int i = 0;
    size_t old = ret.size();
    if(!s.empty()){
        ++i;
        char c = *s.rbegin();
        switch(c){
            case '(':ret.push_back(')');break;
            case '[':ret.push_back(']');break;
            case '{':ret.push_back('}');break;
            default:;
        }
        s.resize(s.size() - 1);
        help(ret, s, n1, n2, n3);
        s.push_back(c);
        ret.resize(old);
    }
    if(n1 > 0){
        ++i;
        ret.push_back('(');
        s.push_back('(');
        help(ret, s, n1 - 1, n2, n3);
        s.resize(s.size() - 1);
        ret.resize(old);
    }
    if(n2 > 0){
        ++i;
        ret.push_back('[');
        s.push_back('[');
        help(ret, s, n1, n2 - 1, n3);
        s.resize(s.size() - 1);
        ret.resize(old);
    }
    if(n3 > 0){
        ++i;
        ret.push_back('{');
        s.push_back('{');
        help(ret, s, n1, n2, n3 - 1);
        s.resize(s.size() - 1);
        ret.resize(old);
    }
    if(!i)
        cout<<ret<<endl;
}

void solve(int n1, int n2, int n3)
{
    string ret, s;
    help(ret, s, n1, n2, n3);
}

int main()
{
    solve(1, 1, 1);
    cout<<"---\n";
    solve(2, 0, 1);
    cout<<"---\n";
    solve(2, 0, 2);
}
