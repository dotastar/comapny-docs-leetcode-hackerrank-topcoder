#include "../inc.h"

double solve(int n)
{
    assert(n >= 0);
    vector<double> r(1, 1), t;
    for(int j = 0;j < n;++j){
        if(r.size() - 1 > n - j)
            r.resize(n - j + 1);
        t.resize(1 + r.size());
        cout<<j<<": ";
        print(r);
        for(size_t i = 0;i < r.size();++i){
            if(!r[i])
                continue;
            if(i > 0)
                t[i - 1] += r[i] / 2;
            assert(i + 1 < t.size());
            t[i + 1] += r[i] / 2;
        }
        t[0] += r[1] / 2;
        r.swap(t);
        t.clear();
    }
    print(r);
    return r[0];
}

int main()
{
    cout<<solve(20)<<endl;
}
