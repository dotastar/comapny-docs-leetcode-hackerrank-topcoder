#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > r;
        if(n < 1 || k < 1 || n < k)
            return r;
        vector<int> v;
        help(r, v, n, k);
    }
    void help(vector<vector<int> > & r, vector<int> & v, int n, int k){
        int old = v.size();
        if(old == k){
            r.push_back(v);
            return;
        }
        int i = (old ? v.back() + 1 : 1);
        for(;i <= n;++i){
            v.resize(old);
            v.push_back(i);
            help(r, v, n, k);
        }
    }
};

int main(){}