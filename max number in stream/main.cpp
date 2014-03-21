#include "..\inc.h"

int gen(int cnt)
{
    assert(cnt > 0);
    return rand() % (cnt + 1);
}

void solve(int cnt)
{
    multiset<int> set;
    list<multiset<int>::iterator> seq;
    vector<int> his, ret;   //for recording only
    //generate cnt numbers
    for(int i = 0;i < cnt - 1;++i){
        int n = gen(cnt);
        seq.push_back(set.insert(n));
        his.push_back(n);
    }
    //generate infinite numbers
    for(int i = 0;i < 20;++i){
        int n = gen(cnt);
        seq.push_back(set.insert(n));
        his.push_back(n);
        ret.push_back(*set.rbegin());
        set.erase(*seq.begin());
        seq.pop_front();
    }
    //print
    print(his);
    cout<<endl;
    for(int i = 0;i < cnt - 1;++i)
        cout<<"  ";
    print(ret);
}

int main()
{
    srand(int(time(0)));
    solve(4);
}