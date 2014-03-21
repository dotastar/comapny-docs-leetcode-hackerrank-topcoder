#include "../inc.h"

typedef vector<pair<int, int> > __Stack;

void pop(__Stack & s, pair<int, int> & p)
{
    assert(!s.empty());
    p = s.back();
    s.pop_back();
}

void push(__Stack & s, pair<int, int> & p)
{
    if(s.empty() || s.back().first != p.first)
        s.push_back(p);
    else
        s.back().second += p.second;
}

void help(__Stack & src, __Stack & dst, int m)
{
    for(pair<int, int> p;!src.empty();){
        pop(src, p);
        if(!src.empty() && p.second > m){
            pair<int, int> pp = p;
            pp.second = m;
            push(dst, pp);
            p.second -= m;
            pop(src, pp);
            push(src, p);
            push(src, pp);
        }else
            dst.push_back(p);
    }
}

bool solve(vector<int> & array, int m)
{
    if(array.empty())
        return true;
    if(m <= 0)
        return false;
    //gen stack 1
    __Stack s1, s2;
    pair<int, int> p;
    p.first = array.front();
    p.second = 1;
    for(size_t i = 1;i < array.size();++i){
        if(p.first == array[i])
            ++p.second;
        else{
            push(s1, p);
            p.first = array[i];
            p.second = 1;
        }
    }
    push(s1, p);
    //stack 1 -> stack 2
    help(s1, s2, m);
    //stack 2 -> stack 1
    help(s2, s1, m);
    //gen array
    array.clear();
    for(size_t i = 0;i < s1.size();++i){
        p = s1[i];
        if(p.second > m)
            return false;
        array.resize(array.size() + p.second, p.first);
    }
    return true;
}

int main()
{
    {
        int a[] = {1,4,1,4,1,1,1,1};
        vector<int> array(a, a + sizeof a / sizeof a[0]);
        if(solve(array, 2))
            print(array);
        else
            cout<<"cannot solve\n";
    }
    {
        int a[] = {1,1,1,1,1,4,1,4,};
        vector<int> array(a, a + sizeof a / sizeof a[0]);
        if(solve(array, 2))
            print(array);
        else
            cout<<"cannot solve\n";
    }
}
