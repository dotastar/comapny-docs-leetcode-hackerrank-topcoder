#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> r;
        r.push_back(0);
        if(n <= 0)
            return r;
        vector<bool> u(1 << n);
        u[0] = true;
        help(n, r, u);
        return r;
    }
    bool help(int n, vector<int> & r, vector<bool> & u){
        size_t old = r.size();
        if(old >= u.size())
            return true;
        assert(old > 0);
        int v = r.back();
        for(int i = 0;i < n;++i){
            r.resize(old);
            int vv = v ^ (1 << i);
            if(u[vv])
                continue;
            r.push_back(vv);
            u[vv] = true;
            if(help(n, r, u))
                return true;
            u[vv] = false;
        }
        return false;
    }
};

void print(const vector<int> & v)
{
    for(size_t i = 0;i < v.size();++i)
        cout<<v[i]<<" ";
    cout<<endl;
}

int main()
{
    print(Solution().grayCode(0));
    print(Solution().grayCode(1));
    print(Solution().grayCode(2));
    print(Solution().grayCode(3));
    print(Solution().grayCode(4));
}
